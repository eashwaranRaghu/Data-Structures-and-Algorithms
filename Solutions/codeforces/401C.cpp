// 30-10-2019 13:25:16 badLiver
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
	int n, m;
    cin >> n >> m;
    string s;
    if(2*(n+1) < m || n > m+1) cout << -1;
    else {
        if(2*(n+1) == m) {
            s="11";
            m-=2;
        }
        else if(2*(n+1) == m+1) {
            s="1";
            m--;
        }
        if(m-n > 1) {
            while(abs(n-m) >1) {
                s += "011";
                n--;
                m-=2;
            }
        }
        while(n>0 && m > 0) {
            s += "01";
            n--;
            m--;
        }
        if(n==1) s+="0";
        else if(m==1) s+="1";
        cout << s;
    }
    return EXIT_SUCCESS;
}
