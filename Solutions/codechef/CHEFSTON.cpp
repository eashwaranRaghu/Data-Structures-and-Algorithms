// Created on 22-06-2019 18:43:21 by necronomicon
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

int64 mx(int64 a, int64 b){
    return (a>b)? a:b;
}
int main () {
	int t;
    cin >> t;
    while (t--){
        int64 n, k, A[100009], B[100009];
        cin >> n >> k;
        for (int64 i = 0; i < n; i++) cin >> A[i];
        for (int64 i = 0; i < n; i++) cin >> B[i];
        int64 profit = 0;
        for (int64 i = 0; i < n; i++)
        {
            profit = mx(profit, ((k/A[i])*B[i]));
        }
        cout << profit << endl;
    }
    return EXIT_SUCCESS;
}
