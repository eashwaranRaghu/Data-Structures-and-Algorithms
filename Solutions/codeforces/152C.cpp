// 13-11-2019 09:33:15 badLiver
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
	int64 n, m, ans=1;
    cin >>n>>m;
    Vs v(n);
    VVi S(m, Vi(26, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < m; j++) {
            S[j][v[i][j] - 'A'] =1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int c=0;
        for (int j = 0; j < 26; j++)
        {
            if(S[i][j] == 1) c++;
        }
        ans = ((ans%MOD)*(c%MOD))%MOD;
        // cout << c<< endl;
    }
    
    cout << ans;

    return EXIT_SUCCESS;
}
