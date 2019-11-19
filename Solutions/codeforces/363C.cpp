// 07-11-2019 00:20:21 badLiver
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
string s;
bool check1(int idx) {
    if(idx+2 < s.size() && s[idx]==s[idx+1] && s[idx]==s[idx+2]) {
        s.erase(s.begin()+idx);
        return true;
    }
    else return false;
}
bool check2(int idx) {
    if(idx+3 < s.size() && s[idx] == s[idx+1] && s[idx+2] == s[idx+3]) {
        s.erase(s.begin()+idx+2);
        return true;
    }
    return false;
}
int main (int argc, char const *argv[]) {
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if(check1(i)) i--;
        if(check2(i)) i--;
    }
    cout << s;
    return EXIT_SUCCESS;
}
