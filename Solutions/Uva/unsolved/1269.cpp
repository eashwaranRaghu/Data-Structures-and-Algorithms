// 17-07-2020 04:01:25 necronomicon
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
        int n, a, sum=0;
        Vi v;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>a;
            for(int b: v) if(a >= b) sum++;
            v.push_back(a);
        }
        cout << sum << endl;
    }
    return EXIT_SUCCESS;
}
