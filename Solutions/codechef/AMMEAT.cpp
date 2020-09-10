// Created on 22-06-2019 18:57:18 by necronomicon
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

int main () {
	int t;
    cin >> t;
    while (t--){
        int64 n, m, arr[100009];
        cin >> n >> m;
        for (int64 i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr+n);
        int64 sum=0;
        int64 i;
        for (i = n-1; i >= 0; i--)
        {
            sum+=arr[i];
            if(sum >= m) break;
        }
        if(sum<m)cout<<-1<<endl;
        else cout << n-i << endl;
        
    }
    return EXIT_SUCCESS;
}
