// Created on 06-07-2019 11:29:10 by necronomicon
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

int64 reduceB(int64 a, string b) 
{ 
    int64 mod = 0; 
    for (int i=0; i<b.size(); i++) 
        mod = (mod*10 + b[i] - '0')%a; 
    return mod;
} 

int main () {
	int t;
    cin >> t;
    while (t--){
        int64 n, k;
        string K;
        cin >> n >> K;
        k = reduceB(n, K);
        int64 mn = min(n-k, k), mx = max(n-k, k);
        if(mn<mx) cout << 2*mn << endl;
        else cout << 2*mn-1 << endl;
    }
    return EXIT_SUCCESS;
}
