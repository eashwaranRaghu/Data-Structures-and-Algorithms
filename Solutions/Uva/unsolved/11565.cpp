// 21-07-2020 05:49:19 necronomicon
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
    int t;
    cin >> t;
    while (t--){
        int a, b, c, flag = 1;
        cin >> a >> b >> c;
        int bound = (int)sqrt(max(c, b));
        for (int x = -1*bound; x <= bound && flag; x++)
        {
            for (int y = x+1; y <= bound && flag; y++)
            {
                int z = a-x-y;
                if(x != z && y != z && x*y*z == b && x*x+y*y+z*z == c) {
                    flag = 0;
                    Vi ans = {x, y, z};
                    sort(ans.begin(), ans.end());
                    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
                }
            }
        }
        if(flag) cout << "No solution.\n";
        
    }
    return EXIT_SUCCESS;
}
