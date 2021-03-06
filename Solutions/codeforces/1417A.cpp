// 30-09-2020 02:14:25 necronomicon
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
	PQi pq;
    int t;
    cin >> t;
    while (t--) {
        int n, k, temp, c=0;
        cin >> n >> k;
        Vi v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        auto mn = min_element(v.begin(), v.end());
        for(int i=0; i<n; i++) {
            if(mn-v.begin() != i) {
                // cout <<  k-*(v.begin()+i) << '-' << (*mn )<< endl;
                c+= (k-*(v.begin()+i))/(*mn);
            }
        }
        cout << c << endl;
    }
    return EXIT_SUCCESS;
}
