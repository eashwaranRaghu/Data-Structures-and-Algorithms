// 19-11-2019 14:30:41 badLiver
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

int v[100009], a[100009], b[100009];

int main (int argc, char const *argv[]) {
	int n;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(v[i] >= 0) a[i] = 1;
        else a[i] = 0;
        if(i!=0) a[i] += a[i-1];
    }
    for (int i = n-1; i >= 0; i--)
    {
        if(v[i] <= 0) b[i] = 1;
        else b[i] = 0;
        if(i!=n-1) b[i] += b[i+1];
    }
    int ans = n+1;
    for (int i = 0; i+1 < n; i++) ans = min(ans, a[i]+b[i+1]);
    printf("%d", ans);
    return EXIT_SUCCESS;
}
