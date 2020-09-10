// 02-11-2019 17:55:28 badLiver
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

int64 n,k,d;
vector<pair<int64,int64>> dp;

void rec() {
    dp[0] = {1,0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k && j <= i; j++)
        {
            if(j < d) {
                dp[i].first = (dp[i].first%MOD + dp[i-j].first%MOD)%MOD;
                dp[i].second = (dp[i].second%MOD+ dp[i-j].second%MOD)%MOD;
            }
            else {
                dp[i].second = (dp[i].second%MOD + (dp[i-j].second%MOD + dp[i-j].first%MOD)%MOD)%MOD;
            }
        }
    }
    cout << dp[n].second;
}

int main (int argc, char const *argv[]) {
    cin >> n >> k >> d;
    dp = vector<pair<int64,int64>>(n+1, {0,0});
    rec();
    return EXIT_SUCCESS;
}
