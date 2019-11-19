// 09-11-2019 06:16:47 badLiver
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
    int64 n, temp, score;
    cin >> n;
    vector<int64> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(begin(v), end(v));
    vector<pair<int64, int64>> V;
    V = {{-1,0},{0,0}};
    for (int i = 0; i < n; i++)
    {
        if(V[V.size()-1].first!=v[i]) V.push_back({v[i], 1});
        else V[V.size()-1].second++;
    }
    vector<int64> M(V.size()), dp(V.size());
    M[0] = 0; M[1] = 0;
    for (int i = 2; i < V.size(); i++)
    {
        score = V[i].first * V[i].second;
        if(V[i-1].first < V[i].first-1) score += M[i-1];
        else score += M[i-2];
        M[i] = max(M[i-1], score);
        dp[i] = score;
    }
    cout << *max_element(dp.begin(), dp.end());
    return EXIT_SUCCESS;
}
