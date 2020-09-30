// 30-09-2020 21:00:22 necronomicon
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
	int tt;
    cin >> tt;
    while(tt--) {
        int n, l;
        cin >> n >> l;
        Vi A(n);
        for(int &a: A) cin >> a;

        cout << setprecision(3);
        vector<long double> P(n), Q(n);
        long double x=0, v=1, t=0;
        for (int i = 0; i < n; i++)
        {
            P[i] = t = ((A[i]-x)/v) + t;
            x = A[i];
            v++;
        }
        P.insert(P.begin(), 0);
        P.push_back((l-x)/v + t);
        x=l, v=1, t=0;
        for (int i = n-1; i >= 0; i--)
        {
            Q[i] = t = ((x-A[i])/v) + t;
            x = A[i];
            v++;
        }
        Q.insert(Q.begin(), (x)/v + t);
        Q.push_back(0);
        // reverse(Q.begin(), Q.end());
        // for(long double p: P) cout << fixed << setprecision(3) << p << ", "; cout << endl;
        // for(long double p: Q) cout << fixed << setprecision(3) << p << ", "; cout << endl;   
        // cout << endl;

        A.push_back(l);
        A.insert(A.begin(), 0);
        long double high=l, low=0;
        int ub, lb;
        while(high > low) {
            x = (high+low)/2;
            ub = upper_bound(A.begin(), A.end(), x) - A.begin();
            lb = ub-1;
            // time for a to reach here t1
            long double t1 = ( (abs(P[ub]-P[lb]) * (x-A[lb])) / abs(A[ub]-A[lb]) ) + P[lb];
            // time for a to reach here t1
            long double t2 = ( (abs(Q[ub]-Q[lb]) * (x-A[lb])) / abs(A[ub]-A[lb]) ) + Q[lb];

            if(abs(t1-t2) < 1e10) { // equal
                cout << fixed << setprecision(3) << t1 << endl;
                break;
            }
            else if(t1 < t2) high = x;
            else low = x;
        }
        // cout << -1 << endl;
    }
    return EXIT_SUCCESS;
}
