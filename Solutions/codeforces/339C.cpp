// 19-11-2019 16:56:56 badLiver
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
string s;
int m;
bool oSign(int a, int b) {
    return a/abs(a) != b/abs(b);
}

Vi dfs(int balance, int lastWeight, int move) {
    if(move == m) {
        return {lastWeight};
    }
    for(int i=1; i<=10; i++) {
        int newBalance = (move%2==1)? balance+i: balance-i;
        if(s[i-1] == '1' && lastWeight != i && newBalance != 0 && oSign(balance, newBalance)) {
            Vi v = dfs(newBalance, i, move+1);
            if(v.size()) {
                v.push_back(lastWeight);
                return v;
            }
        }
    }
    return {};
}

int main (int argc, char const *argv[]) {
	cin >> s;
    cin >> m;
    Vi v = dfs(0, -1, 0);
    if(v.size()) {
        cout << "YES" << endl;
        v.pop_back();
        reverse(v.begin(), v.end());
        for(int u: v) cout << u << ' ';
    }
    else cout << "NO";
    
    return EXIT_SUCCESS;
}
