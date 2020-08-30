// 12-11-2019 09:54:44 badLiver
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
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
	int64 n, cur, ans=0;
    string s;
    cin >> n >> cur >> s;
    cur = min(cur, n-cur+1);
    cur--;
    int m1=cur, m2=cur;
    if(s[cur] != s[n-1-cur]) ans += min(abs(s[cur]-s[n-1-cur]), 26-abs(s[cur]-s[n-1-cur]));
    for (int i = cur+1; i < n/2; i++)
    {
        if(s[i] != s[n-1-i]) {
            m1 = i;
            ans += min(abs(s[i]-s[n-1-i]), 26-abs(s[i]-s[n-1-i]));
        }
    }
    for (int i = cur-1; i > -1; i--)
    {
        if(s[i] != s[n-1-i]) {
            m2 = i;
            ans += min(abs(s[i]-s[n-1-i]), 26-abs(s[i]-s[n-1-i]));
        }
    }
    m1 = abs(m1-cur);
    m2 = abs(m2-cur);
    // cout << cur << ' ' << ans << ' ' << m1 << ' ' << m2 << endl;
    ans += max(m2,m1)+2*min(m1,m2);
    cout << ans;
    return EXIT_SUCCESS;
}
