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

int n, m, pos, val, t[(int)1e5], arr[(int)1e5];

void build(int v, int tl, int tr) {
    int level = n-log2(v);
    if (tl == tr) {
        t[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        if(level%2) t[v] = 1;
        else t[v] = 0;
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
    int level = n-log2(idx);
    if (tLeft == tRight) {
        t[idx] = val;
    } else { // recall then update the node
        int tMid = (tLeft + tRight) / 2;
        if (pos <= tMid)
            update(idx*2, tLeft, tMid, pos, val);
        else
            update(idx*2+1, tMid+1, tRight, pos, val);
        if(level%2) t[idx] = t[idx*2] ^ t[idx*2+1];
        else t[idx] = t[idx*2] | t[idx*2+1];
    }
}

void build () {}
void showTree() {
    for (int i = 1; i < 2*(1<<n); i++)
    {
        cout << t[i] << ' ';
    }
    cout << endl;
}
int main () {
    // for(int i=1; i<= 10; i++) cout << i << ' ' << (int)log2(i) << endl;
	cin >> n >> m;
    for(int i=0; i<(1<<n); i++) { 
        cin >> arr[i];
    }
    build(1, 0, (1<<n)-1);
    showTree();
    cout << t[1] << endl;
    while(m--) {
        cin >> pos >> val;
        update(1, 0, (1<<n)-1, pos-1, val);
        showTree();
        cout << t[1] << endl;
    }
    return EXIT_SUCCESS;
}
