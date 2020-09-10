// Created on 11-05-2019 17:54:38 by necronomicon
#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ARR_MAX (int)1e5 //Max array length
#define INF (int)1e9 //10^9
#define EPS 1e-9 //10^-9
#define MOD 1000000007 //10^9+7
#define PI 3.1415926535897932384626433832795
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef pair<int, int> Pii;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef map<int,int> Mii;
typedef set<int> Si;
typedef multimap<int,int> MMii;
typedef multiset<int> MSi;
typedef unordered_map<int,int> UMii;
typedef unordered_set<int> USi;
typedef unordered_multimap<int,int> UMMii;
typedef unordered_multiset<int> UMSi;
typedef priority_queue<int> PQi;
typedef queue<int> Qi;
typedef deque<int> DQi;

int d, r, n;
string D[ARR_MAX], temp, s;


void rec(int k, string str){
    if(k == n){
        cout << str << endl;
        return;
    }
    if(s[k] == '0'){
        for (size_t i = 0; i < 10; i++)
        {
            rec(k+1, str + to_string(i));
        }
        
    } else {
        for (size_t i = 0; i < d; i++)
        {
            rec(k+1, str + D[i]);
        }
    }
    return;
}

int main () {
	while(cin >> d){
        cout << "--" << endl;
        for (size_t i = 0; i < d; i++){cin >> temp; D[i] = temp;}
        cin >> r;
        for (size_t i = 0; i < r; i++){
            cin >> temp;
            s = temp;
            n = s.length();
            rec(0, "");
        }
    }
    return EXIT_SUCCESS;
}
