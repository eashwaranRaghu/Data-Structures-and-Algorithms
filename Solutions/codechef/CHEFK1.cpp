// Created on 07-09-2019 18:51:26 by necronomicon
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

int64 solve() { 
    int64 n,m;
    cin >> n >> m;
    if(m == 0 && n == 1) return 0;
    int64 l, r;
    l = n-1;
    r = (n*(n+1))/2;
    if(m < l || m > r) return -1;
    int64 total = 0, ans = 0;
    for (int64 i = n-1; i > 0; i--)
    {
        total += i;
        ans++;
        if(total >= m) return ans;
        
        if(i == n-1) {
            total += n;
            ans ++;
            if(total >= m) return ans;
        }
    }
    if(total >= m) return n;
    return -1;
}

int main (int argc, char const *argv[]) {
	int t;
    cin >> t;
    while (t--){
        cout << solve() << endl;
    }
    return EXIT_SUCCESS;
}
