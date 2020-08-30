// 20-07-2020 09:47:01 necronomicon
#include <bits/stdc++.h>
using namespace std;

#define ARR_MAX (int)1e5 //Max array length
#define INF (int)1e9 //10^9
#define MOD 1000000007 //10^9+7
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
    int n, ans;
    string a;
    while(cin >> n) {
        VPii u, v;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            for (int j = 0; j < n; j++)
            {   
                if(a[j] == '1') u.push_back({i, j});
                else if(a[j] == '3') v.push_back({i, j});
            }
        }
        ans = 0;
        for (Pii uu: u)
        {
            int temp = INT_MAX;
            for(Pii vv: v) temp = min(temp, abs(uu.first - vv.first) + abs(uu.second - vv.second));
            ans = max(ans, temp);
        }
        cout << ans << endl;
    }
    
    return EXIT_SUCCESS;
}
