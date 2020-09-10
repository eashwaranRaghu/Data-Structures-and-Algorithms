// 18-11-2019 11:15:07 badLiver
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
	string a,b;
    cin >> a >> b;
    Vi v(b.size()+1), u(b.size()+1);
    for (int i = 1; i <= b.size(); i++)
    {
        v[i] = ((b[i-1]=='1')? 1:0) + v[i-1];
        u[i] = ((b[i-1]=='0')? 1:0) + u[i-1];
    }
    int64 total=0;
    for (int i = 1; i <= a.size(); i++)
    {
        if(a[i-1]=='1') {
            total += (u[b.size()-a.size()+i] - u[i-1]);
        }
        else {
            total += (v[b.size()-a.size()+i] - v[i-1]);
        }
    }
    cout << total;
    return EXIT_SUCCESS;
}
