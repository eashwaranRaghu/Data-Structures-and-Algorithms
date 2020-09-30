// 28-09-2020 13:46:47 necronomicon
#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define ARR_MAX (int)1e5
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
typedef vector<VVi> VVVi;

int main () {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        VVVi T;
        for(int i=0; i<n; i++) {
            VVi u;
            int x, y;
            cin >> x >> y;
            u.push_back({x, y});
            cin >> x >> y;
            u.push_back({x, y});
            T.push_back(u);
        }
        bool f1=0, f2=1;
        if(m%2) goto here;
        for (int i = 0; i < n; i++)
        {
            if (T[i][0][1] == T[i][1][0]) f1 = 1;
            for (int j = i; j < n; j++)
            {
                bool f =
                (T[i][0][1] == T[j][1][0]) &&
                (T[i][1][0] == T[j][0][1]) &&
                
                (T[i][0][0] == T[j][1][1]) &&
                (T[i][1][1] == T[j][0][0]) ;
                if(f) f2 = 1;
            }
        }
        here: cout << ((f1 && f2)? "YES" : "NO" )<< endl;
    }
    return EXIT_SUCCESS;
}
