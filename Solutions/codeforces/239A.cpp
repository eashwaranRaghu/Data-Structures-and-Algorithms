// 19-10-2019 18:50:45 badLiver
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

int64 g, x, y, k, n;


int main (int argc, char const *argv[]) {
	
    cin >> y >> k >> n;
    int l, r;
    l = 1;
    r = (n/k)+1;
    bool flag = true;
    for (int i = l; i < r; i++)
    {
        if(i*k-y > 0) {
            cout << i*k-y << ' ';
            flag = false;
        }
    }
    if(flag) cout << -1;
    return EXIT_SUCCESS;
}
