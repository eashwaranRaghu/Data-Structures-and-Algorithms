// Created on 27-06-2019 13:34:52 by necronomicon
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
int arr[100000];
int64 op(int64 a, int64 b, string o){
    if(o == "AND") return a&b;
    else if(o == "XOR") return a^b;
    else return a|b;
}
int64 fn(int64 n, int64 k, int64 ans, string o){
    if(k == 0) return ans;
    if(o == "AND" || o == "OR"){
        for (int j = 0; j < n; j++)
        {
            ans = op(ans, arr[j], o);
        }
        return ans;
    }
    k %= 2;
    if(k){
        for (int j = 0; j < n; j++)
        {
            ans = op(ans, arr[j], o);
        }
    }
    return ans;
}

int main () {
	int64 t;
    cin >> t;
    while (t--){
        int64 n, k, ans;
        string o;
        cin >> n >> k >> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> o;
        cout << fn(n, k, ans, o) << endl;
    }
    return EXIT_SUCCESS;
}
