// 15-11-2019 08:29:19 badLiver
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



int main (int argc, char const *argv[]) {
    int n, m, x,y,z, p, u,v, N,M;
    cin >> n >> m >> x >> y >> z >> p;
    x%=4;
    y%=2;
    z%=4;
    for (int i = 0; i < p; i++)
    {
        cin >> u >> v;
        N=n+1, M=m+1;
        for (int i = 0; i < x; i++) {
            u = N-u;
            swap(u, v);
            swap(N, M);
        }
        if(y==1) v = M-v;
        for (int i = 0; i < 4-z; i++) {
            u = N-u;
            swap(u, v);
            swap(N, M);
        }
        cout << u << ' ' << v << endl;
    }
    
    return EXIT_SUCCESS;
}
