// 30-10-2019 22:08:40 badLiver
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

bool great(string a, string b) {
    if(a.size() > b.size()) return true;
    else if(b.size() > a.size()) return false;
    else {
        if(a >= b) return true;
        else return false;
    }
}

int main (int argc, char const *argv[]) {
	int vol, maxLen=0, minCost=numeric_limits<int>::max();
    cin >> vol;
    
    Vi cost(10), w(10, vol);
    vector<string> u(10), uu;

    for (int i = 1; i < 10; i++) {
        cin >> cost[i];
        minCost = min(minCost, cost[i]);
        for (int j = 0; j < (vol/cost[i]); j++) {
            u[i] += ('0'+i);
            w[i] -= cost[i];
        }
        maxLen = max(maxLen, (int)u[i].size());
    }
    for (int i = 1; i < 10; i++) if(u[i].size() == maxLen) uu.push_back(u[i]);
    u = uu;
    for (int i = 0; i < u.size(); i++) {
        // selected u[i] to be maxed
        for (int j = 0; j < u[i].size(); j++) {
            // selected u[i][j]th pos to be maxed;
            int digit = (u[i][j]-'0');
            if(w[i]+cost[digit] < minCost) continue;
            for (int k = 1; k < 10; k++) {
                // replace with kth digit v[k]
                if(w[i]+cost[digit]-cost[k] >= 0) {
                    string temp = u[i];
                    temp[j] = '0'+k;
                    if(great(temp, u[i])) {
                        w[i] = w[i]+cost[digit]-cost[k];
                        u[i] = temp;
                    }
                }
            }
        }
    }
    string x = "";
    for (int i = 1; i < 10; i++)
    {
        if(great(u[i], x)) {
            x = u[i];
        }
    }
    if(x.size() == 0) cout << -1;
    else cout << x;
    return EXIT_SUCCESS;
}
