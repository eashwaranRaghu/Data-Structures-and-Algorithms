// Created on 11-05-2019 22:32:49 by necronomicon
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
	int t, n, h, s[10000];
    cin >> t;
    while (t--){
        cin >> n >> h;
        for (size_t i = 0; i < n-h; i++)
        {
            s[i] = 0;
        }
        for (size_t i = n-h; i < n; i++)
        {
            s[i] = 1;
        }
        for (size_t i = 0; i < n; i++)
        {
            cout << s[i];
        }
        cout << endl;
        while(next_permutation(s, s+n)){
            for (size_t i = 0; i < n; i++)
            {
                cout << s[i];
            }
            cout << endl;
        }
        if(t) cout << endl;
    }
    return EXIT_SUCCESS;
}
