// Created on 29-06-2019 19:07:05 by necronomicon
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
    string line;
    getline(cin, line);
    stringstream ss(line);
	int t;
    ss >> t;
    while (t--){
        getline(cin, line);
        stringstream sss(line);
        int n, temp;
        Vi v;
        while(sss >> temp){
            v.push_back(temp);
        }
        sort(v.begin(), v.end(), greater<int>());
        cout << ((v[0]==v.size()-1)? v[1]:v[0]) << endl;
    }
    return EXIT_SUCCESS;
}
