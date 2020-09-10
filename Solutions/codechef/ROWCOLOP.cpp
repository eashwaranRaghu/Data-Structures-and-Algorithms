// Created on 22-06-2019 19:08:04 by necronomicon
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
	int64 n, q, r[314159], c[314159], mx_r=0, mx_c=0, a, b;
    string s;
    cin >> n >> q;
    for (int64 i = 0; i < n; i++)
    {
        r[i] =0; c[i] =0;
    }
    for (int64 i = 0; i < q; i++)
    {
        cin >> s >> a >> b;
        a--;
        if(s == "RowAdd"){
            r[a]+=b;
            mx_r = max(mx_r, r[a]);
        }
        else{
            c[a]+=b;
            mx_c = max(mx_c, c[a]);
        }
    }
    cout << mx_c + mx_r ;
    return EXIT_SUCCESS;
}
