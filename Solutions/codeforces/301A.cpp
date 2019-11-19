// 15-11-2019 06:30:11 badLiver
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
	int n, temp, sum=0, mn = numeric_limits<int>::max(), neg=0;
    cin >> n;
    Vi v(2*n-1);
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
        sum += abs(v[i]);
        mn = min(abs(v[i]), mn);
        if(v[i] < 0) neg++;
    }
    if(neg >= n) {
        if(neg == n) cout << sum;
        else if((neg-n-1)%2==1) cout << sum;
        else {
            cout << sum << ' ' << mn << endl;
            cout << sum - 2*abs(mn);
        }
    }
    else {
        if(neg%2==0) cout << sum;
        else cout << sum - 2*abs(mn);
    }
    return EXIT_SUCCESS;
}