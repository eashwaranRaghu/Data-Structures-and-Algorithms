// 18-10-2019 11:01:41 badLiver
#include <bits/stdc++.h>
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

#define N 1000000007

int64 exponentiation(int64 base, 
                        int64 exp) 
{ 
    if (exp == 0) 
        return 1; 
  
    if (exp == 1) 
        return base % N; 
  
    int64 t = exponentiation(base, exp / 2); 
    t = ((t%N) * (t%N)) % N; 
  
    if (exp % 2 == 0) 
        return t; 
  
    else
        return ((base % N) * t) % N; 
} 


int main (int argc, char const *argv[]) {
	int64 n, m, ans;
    cin >> n >> m;
    ans = exponentiation(2, m);
    ans--;
    ans = exponentiation(ans, n);
    cout << ans;
    return EXIT_SUCCESS;
}
