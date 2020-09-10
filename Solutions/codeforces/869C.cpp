// 19-11-2019 13:13:01 badLiver
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

int64 arr[5001][5001];

int main (int argc, char const *argv[]) {
    int64 a, b, c;
    int64 mod = 998244353;
    cin >> a >> b >> c;
    for (int i = 1; i < 5001; i++) arr[i][1] = arr[1][i] = i+1;
    for (int i = 2; i < 5001; i++) for (int j = 2; j < 5001; j++) arr[i][j] = (arr[i-1][j]+arr[i-1][j-1]*j)%mod;
    cout << ((arr[a][b]*arr[a][c])%mod*arr[b][c])%mod;
    return EXIT_SUCCESS;
}
