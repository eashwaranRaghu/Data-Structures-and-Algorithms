// 19-11-2019 20:16:16 badLiver
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
	int64 t, n, m, sum, m1, m2;
    int64 arr[1009];
    cin >> t;
    while (t--){
        cin >> n >> m;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        sum *= 2;

        m1 = 0, m2 = 1;
        for (int i = 0; i < n; i++) if(arr[i] < arr[m1]) m1 = i;
        if(m1 == m2) m2 = 0;
        for (int i = 0; i < n; i++) if(arr[i] < arr[m2] && i != m1) m2 = i;
        
        if(m < n+1 || n <= 2) {
            cout << -1 << endl;
        }
        else {
            sum += (max(0LL, m-n)*(arr[m1]+arr[m2]));
            cout << sum << endl;
            for (int i = 1; i < n; i++)
            {
                cout << i << ' ' << i+1 << endl;
            }
            cout << n << ' ' << 1 << endl;
            for (int i = 0; i < (m-n); i++)
            {
                cout << m1+1 << ' ' << m2+1 << endl;
            }
        }
    }
    return EXIT_SUCCESS;
}
