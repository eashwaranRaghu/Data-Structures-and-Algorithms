// 30-09-2020 02:36:39 necronomicon
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

int main () {
	int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        Vi A(n);
        Mii M, C, D;
        for(int &a: A) {
            cin >> a;
            M[a]++;
        }
        for(auto m: M) {
            int val = m.first, occ = m.second;
            int opp = M[k-val];
            if(opp) {
                if(k-val == val) { // half
                    C[val] = opp/2;
                    m.second = M[k-val] = 0;
                }
                else { // left right
                    C[val] = occ;
                    m.second = M[k-val] = 0;
                }
            }
        }
        for(int i=0; i<A.size(); i++) {
            if(C[A[i]]) {
                C[A[i]]--;
                cout << "1 ";
            }
            else cout << "0 ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
