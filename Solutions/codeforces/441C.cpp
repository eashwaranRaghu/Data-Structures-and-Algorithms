// 10-11-2019 08:38:21 badLiver
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


int64 n, m, k;



int main (int argc, char const *argv[]) {
    
    cin >> n >> m >> k;
    VVi v;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i%2!=0) v.push_back({i+1, m-j});
            else v.push_back({i+1, j+1});
        }
    }
    
    for (int i = 0; i < k; i++)
    {
        if(i+1<k) {
            cout << 2 << ' ';
            cout << v[i*2][0] << ' ' << v[i*2][1] << ' ';
            cout << v[i*2+1][0] << ' ' << v[i*2+1][1];
        }
        else {
            cout << v.size()-(2*i) << ' ';
            for (int j = i*2; j < v.size(); j++)
            {
                cout << v[j][0] << ' ' << v[j][1];
                if(j != v.size()-1) cout << ' ';
            }
        }
        cout << endl;
    }
    
    

    return EXIT_SUCCESS;
}
