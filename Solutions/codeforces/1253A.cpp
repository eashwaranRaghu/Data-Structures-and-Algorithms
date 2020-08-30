// 16-11-2019 20:06:51 badLiver
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
        int n;
        USi s;
        cin >> n;
        Vi arr(n), brr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
            s.insert(arr[i]-brr[i]);
        }
        s.erase(0);
        if(s.size() == 0) cout << "YES" << endl;
        else if(s.size()>1) cout << "NO" << endl;
        else {
            int l=-1, r;
            for (int i = 0; i < n; i++)
            {
                if(arr[i]!=brr[i]) {
                    if(l==-1) l=i;
                    r =i;
                }
            }
            int diff = arr[l]-brr[l];
            if(diff > 0) cout << "NO" << endl;
            else {
                for (int i = l; i <= r; i++)
                {
                    if(arr[i]-brr[i] != diff) {
                        cout << "NO" << endl;
                        break;
                    }
                    if(i == r) cout << "YES" << endl;
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
