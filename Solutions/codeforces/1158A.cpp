// 30-11-2019 18:02:43 badLiver
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
	int n, m, mx=0, flag =1, ans=0, ans2=0;
    cin >> n >> m;
    Vi u(n), v(m);

    for (int i = 0; i < n; i++) {
        cin >> u[i];
        ans += u[i];
        if(u[i] > mx) mx = u[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        ans += v[i];
        if(v[i] < mx) flag = 0;
    }

    if(flag == 0) {
        cout << -1;
    }
    else {
        ans *= (m-1);
        cout << ans + ans2;
    }
    


    
    return EXIT_SUCCESS;
}
