// Created on 21-06-2019 11:29:49 by necronomicon
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

int main () {
	int n1, n2, n3, temp, c=0;
    Mii s;
    cin >> n1 >> n2 >> n3;
    for (int i = 0; i < n1; i++)
    {
        cin >> temp;
        s[temp]++;
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> temp;
        s[temp]++;
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> temp;
        s[temp]++;
    }
    for(auto a : s){
        if(a.second > 1) c++;
    }
    cout << c << endl;
    for(auto a : s){
        if(a.second > 1) cout << a.first << endl;
    }
    
    return EXIT_SUCCESS;
}
