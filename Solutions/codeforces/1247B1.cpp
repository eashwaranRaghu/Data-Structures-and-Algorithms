// 26-10-2019 16:49:50 badLiver
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
        int ai, n, k, d;
        cin >> n >> k >> d;
        Vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        UMii m;
        USi s;
        for (int i = 0; i < d; i++)
        {
            m[v[i]]++;
            s.insert(v[i]);
        }
        int ans = s.size();
        for (int i = 0; i+d < n; i++)
        {
            m[v[i]]--;
            if(m[v[i]] == 0) s.erase(v[i]);

            m[v[i+d]]++;
            s.insert(v[i+d]);

            ans = min(ans, (int)s.size());
        }
        cout << ans << endl;
    }
    return EXIT_SUCCESS;
}
