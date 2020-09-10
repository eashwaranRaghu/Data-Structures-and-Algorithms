// 15-11-2019 18:50:31 badLiver
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
	int n, m, t, r;
    cin >> n >> m;
    Vi arr(n);
    VPii brr(m, {0,0});
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) cin >> brr[i].second >> brr[i].first;
    
    int idx =0;
    Vi large;
    while(idx < m) {
        auto itr = max_element(begin(brr)+idx, end(brr));
        if(itr == end(brr)) break;
        idx = itr-begin(brr);
        large.push_back(idx);
        idx++;
    }
    
    sort(begin(arr), begin(arr)+brr[large[0]].first, [&] (int a, int b) {return (brr[0].second==1)? (a<b):(a>b);});
    
    for (int i=1; i<large.size(); i++) 
    {
        t = brr[large[i]].second, r = brr[large[i]].first-1;
        if((t == 1 && arr[0] > arr[r]) || (t==2 && arr[0] < arr[r])) {
            for (int j = 0; j < r-j; j++)
            {
                swap(arr[j], arr[r-j]);
            }
        }
    }
    for (int x: arr) cout << x << ' ';
    return EXIT_SUCCESS;
}
