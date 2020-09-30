// 30-09-2020 20:07:28 necronomicon
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

int n;
Vi A, B, C, P;


bool per(int k) {
    if(k == n) {
        return (P.size() == n);
    }

    bool r;
    if(!((k>0 && P[k-1] == A[k])||(k==n-1 && P[0]==A[k]))) {
        P.push_back(A[k]);
        r = per(k+1);
        if(r) return r;
        else P.pop_back();
    }
    
    if(!((k>0 && P[k-1] == B[k])||(k==n-1 && P[0]==B[k]))) {
        P.push_back(B[k]);
        r = per(k+1);
        if(r) return r;
        else P.pop_back();
    }

    if(!((k>0 && P[k-1] == C[k])||(k==n-1 && P[0]==C[k]))) {
        P.push_back(C[k]);
        r = per(k+1);
        if(r) return r;
        else P.pop_back();
    }

    return false;
}

void solve() {
    cin >> n;
    A = Vi(n);
    B = Vi(n);
    C = Vi(n);
    for(int &a: A) cin >> a;
    for(int &b: B) cin >> b;
    for(int &c: C) cin >> c;
    per(0);
    // cout << "\n---\n";
    for(int p: P) cout << p << ' ';
    cout << endl;
    P.clear();
}

int main () {
	int t=0; 
    cin >> t;
    while(t--) {
        solve();
    }
    return EXIT_SUCCESS;
}
