// 18-11-2019 20:44:37 badLiver
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


int64 n, a, b, sum, ans=0;
vector<int64> fact(1000009, 1);

bool isGood(int64 x) {
    while(x) {
        if(x%10 !=a && x%10 != b) return false;
        x/=10;
    }
    return true;
}

void fac() {
    int64 f=1;
    for (int64 i = 1; i <= n; i++)
    {
        f = (f%MOD * i%MOD)%MOD;
        fact[i] = f;
    }
}

long long binpow(long long val, long long deg, long long mod) {
        if (!deg) return 1 % mod;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
        long long res = binpow(val ,deg >> 1, mod);
        return (res*res) % mod;
}

int64 inv(int64 val, int64 deg) {
    if(deg==0) return 1;
    if(deg&1) return ((inv(val, deg-1)%MOD)*(val)%MOD)%MOD;
    int64 res = inv(val, deg >> 1)%MOD;
    return (res*res)%MOD;
}

int main (int argc, char const *argv[]) {
    cin >> a >> b >> n;
    fac();
    for (int64 i = 0; i <= n; i++)
    {
        sum = (i*a)+((n-i)*b);
        if(isGood(sum)) {
            int64 res = fact[n];
            // int64 div = binpow((fact[i]*fact[n-i])%MOD, MOD-2, MOD);
            ans += (res*inv((fact[i]*fact[n-i])%MOD, MOD-2))%MOD;
            ans%=MOD;
        }
    }

    cout << ans;
    
    return EXIT_SUCCESS;
}
// eulers toient fncn