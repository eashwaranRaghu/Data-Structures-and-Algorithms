// 16-11-2019 12:39:36 badLiver
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

string a,b;
Mii m;

void rec(int k, int pos) {
    if(k == a.size()) {
        m[pos]++;
        return;
    }
    if(b[k] != '?') {
        return rec(k+1, pos+((b[k] == '+')? 1:-1));
    }
    else {
        rec(k+1, pos+1);
        rec(k+1, pos-1);
    }
}

int main (int argc, char const *argv[]) {
    cin >> a >> b;
	rec(0,0);
    double num, den, ans;
    for (auto x: m)
    {
        // cout << x.first << ' ' << x.second << endl;
        den += x.second;
    }
    num = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i] == '+') num++;
        else num--;
    }
    num = m[num];
    ans = num/den;
    cout << fixed << setprecision(9) << ans;
    return EXIT_SUCCESS;
}
