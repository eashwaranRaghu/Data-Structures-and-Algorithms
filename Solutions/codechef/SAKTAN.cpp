// Created on 13-10-2019 16:10:08 by necronomicon
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
	int t;
    cin >> t;
    while (t--){
        int64 N, M, Q, x, y;
        cin >> N >> M >> Q;
        vector<int64> n(N,0), m(M,0);
        for (int i = 0; i < Q; i++)
        {
            cin >> x >> y;
            n[x-1]++;
            m[y-1]++;
        }
        int64 o1=0, o2=0, e1=0, e2=0;
        for (int c: n) {
            if(c%2) o1++;
            else e1++;
        }
        for (int c: m) {
            if(c%2) o2++;
            else e2++;
        }
        cout << (e1*o2 + e2*o1) << endl;
    }
    return EXIT_SUCCESS;
}
