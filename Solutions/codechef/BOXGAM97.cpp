// 26-10-2019 22:05:22 badLiver
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
	int t;
    cin >> t;
    while (t--){
        int64 n, k, p, ans;
        cin >> n >> k >> p;
        Vi v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        if(k%2 == 1) {
            if(p == 0) ans = *max_element(begin(v), end(v));
            else ans = *min_element(begin(v), end(v));
        }
        else {
            if(p==0) {
                int m = max(v[1], v[n-2]);
                for (int i = 1; i+1 < n; i++)
                {
                    m = max(m, min(v[i-1], v[i+1]));
                }
                ans = m;
            }
            else {
                int m = min(v[1], v[n-2]);
                for (int i = 1; i+1 < n; i++)
                {
                    m = min(m, max(v[i-1], v[i+1]));
                }
                ans = m;
            }
        }
        cout << ans << endl;
    }
    return EXIT_SUCCESS;
}
