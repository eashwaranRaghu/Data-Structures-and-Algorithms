// 17-09-2020 14:17:05 necronomicon
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

int n, t[(int)1e3];

void build(int a[], int idx, int tLeft, int tRight) {
    if (tLeft == tRight) {
        t[idx] = a[tLeft];
    } else {
        int tMid = (tLeft + tRight) / 2;
        build(a, idx*2, tLeft, tMid);
        build(a, idx*2+1, tMid+1, tRight);
        t[idx] = t[idx*2] + t[idx*2+1];
    }
}

int sum(int idx, int tLeft, int tRight, int left, int right) {
    if (left > right) 
        return 0;
    if (left == tLeft && right == tRight) {
        return t[idx];
    }
    int tMid = (tLeft + tRight) / 2;
    return sum(idx*2, tLeft, tMid, left, min(right, tMid)) // min if the query completely lies in left subtree
           + sum(idx*2+1, tMid+1, tRight, max(left, tMid+1), right); // max if the query completely lies in right subtree
}

void update(int idx, int tLeft, int tRight, int pos, int val) {
    if (tLeft == tRight) {
        t[idx] = val;
    } else { // recall then update the node
        int tMid = (tLeft + tRight) / 2;
        if (pos <= tMid)
            update(idx*2, tLeft, tMid, pos, val);
        else
            update(idx*2+1, tMid+1, tRight, pos, val);
        t[idx] = t[idx*2] + t[idx*2+1];
    }
}

void build () {}

int main () {
	int a = 1;
    cout << a << ' ' << (a << 1) << ' ' << (a >> 1);
    return EXIT_SUCCESS;
}
