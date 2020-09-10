// 14-11-2019 15:03:52 badLiver
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

int64 get(char c) {
    if(c == '_') return 63;
    if(c == '-') return 62;
    if('0'<= c && c <= '9') return (c-'0');
    if('A'<= c && c <= 'Z') return (c-'A'+10);
    if('a'<= c && c <= 'z') return (c-'a'+36);
    return 0;
}


int main (int argc, char const *argv[]) {
	string s;
    int64 t=0, ans=1;
    cin >> s;
    for (int i = 0; i < s.size(); i++) t += (6-__builtin_popcount(get(s[i])));
    for (int i = 0; i < t; i++) ans = ((ans%MOD)*3)%MOD;
    cout << ans;
    return EXIT_SUCCESS;
}
