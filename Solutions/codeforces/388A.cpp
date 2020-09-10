// 13-11-2019 15:52:41 badLiver
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
	int n;
    cin >> n;

    Vi v(n);
    VVi  arr;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(begin(v), end(v));
    arr.push_back({v[0]});
    for (int i = 1; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if(arr[j].size() <= v[i]) {
                arr[j].push_back(v[i]);
                flag = 1;
                break;
            }
        }
        if(!flag) {
            arr.push_back({v[i]});
        }
    }
    
    cout << arr.size();


    return EXIT_SUCCESS;
}
