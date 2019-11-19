// 12-11-2019 14:47:19 badLiver
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
typedef vector<int64> Vi;
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


int64 d1[4000009], d2[4000009];
int64 v[2009][2009];
 
int main (int argc, char const *argv[]) {
	
    int64 n, temp;
    scanf("%I64d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%I64d", &temp);
            v[i][j] = temp;
            d1[i+j] += temp;
            d2[i-j+n-1] += temp;
        }
    }
 
    int64 x1,x2,y1,y2;
    int64 am=-1, bm=-1, sum;
    x1=x2=y1=0, y2=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum = d1[i+j]+d2[i-j+n-1]-v[i][j];
            if((i+j)%2==0) {
                if(am < sum) {x1=i, y1=j, am=sum;}
            }
            else {
                if(bm < sum) {x2=i, y2=j, bm=sum;}
            }
        }
    }
 
    cout << am+bm << endl;
    cout << x1+1 << ' ' << y1+1 << ' ' << x2+1 << ' ' << y2+1;
 
    return EXIT_SUCCESS;
}