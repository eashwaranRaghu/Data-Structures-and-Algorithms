// 28-09-2020 18:49:34 necronomicon
#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define ARR_MAX (int)1e5
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


void fun(int &a1, int &a2, int &a3, int &b1, int &b2, int &b3, int &ca) {
    int temp;
    switch (ca)
    {
    case 0:
        temp = min(a1, b3);
        a1 -= temp;
        b3 -= temp;
        break;
    case 1:
        temp = min(a2, b1);
        a2 -= temp;
        b1 -= temp;
        temp = min(a3, b2);
        a3 -= temp;
        b2 -= temp;
        break;
    case 2:
        temp = min(a3, b2);
        a3 -= temp;
        b2 -= temp;
        break;
    case 3:
        temp = min(a1, b1);
        a1 -= temp;
        b1 -= temp;
        break;
    case 4:
        temp = min(a2, b2);
        a2 -= temp;
        b2 -= temp;
        break;
    case 5:
        temp = min(a3, b3);
        a3 -= temp;
        b3 -= temp;
        break;
    default:
        break;
    }
}

int per(int a1, int a2, int a3, int b1, int b2, int b3, Vi v) {
    for (int x: v)
    {
        fun(a1,a2,a3,b1,b2,b3,x);
    }
    return min(a1, b2) + min(a2, b3) + min(a3, b1);
}
int mn, mx;
int main () {
	int n, a1,a2,a3, b1,b2,b3;
    cin >> n >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    mx = min(a1, b2) + min(a2, b3) + min(a3, b1);
    Vi v = {0,1,2,3,4,5};
    mn = INT_MAX;
    while(next_permutation(v.begin(), v.end())) {
        mn = min(mn, per(a1,a2,a3,b1,b2,b3,v));
    }
    cout << mn << ' ' << mx;
    return EXIT_SUCCESS;
}
