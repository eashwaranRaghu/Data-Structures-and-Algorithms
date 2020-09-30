// 28-09-2020 17:56:06 necronomicon
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

int main () {
	int n;
    cin >> n;
    Vi v(n);
    map<long long int, int> m;
    m[0]=1;
    for(int &x : v) cin >> x;
    long long int cnt = 0, prfx=0;
    for (int i = 0; i < n; i++)
    {
       prfx += (long long int)v[i];
       if(m[prfx]==1) {
           cnt++;
           m.clear();
           m[0]=1;
           prfx = (long long int)v[i];
       }
       m[prfx] = 1;
    }
    cout << cnt;
    return EXIT_SUCCESS;
}
