// 23-02-2020 00:48:52 badLiver
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
	int N, K, temp, sum=0, cnt=0;
    Vi x, y, z;
    Si s, t;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        x.PB(temp);
    }
    sort(x.begin(), x.end(), greater<int>());
    for (int len = 0; len <= N && cnt < K; len++)
    {
        y.clear();
        t.clear();
        sum =0;
        for (int l = 0; l < len; l++)
        {
            y.push_back(x[l]);
            sum += x[l];
            t.insert(x[l]);
        }
        for (int i = 0; i < N && cnt < K; i++)
        {
            sum += x[i];
            if(s.count(sum) == 0 && t.count(x[i]) == 0 && sum != 0) {
                s.insert(sum);
                cnt++;
                y.PB(x[i]);
                cout << y.size() << ' ';
                for(int yy: y) cout << yy << ' '; cout << endl;
                y.pop_back();
            }
            sum -= x[i];
        }
    }
    
    return EXIT_SUCCESS;
}
