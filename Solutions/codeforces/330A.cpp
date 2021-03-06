// 06-11-2019 23:42:56 badLiver
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

int main (int argc, char const *argv[]) {
    int r,c,temp;
    char ch;
    cin >> r >> c;
    	VVi M(r, Vi(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> ch;
            if(ch=='S') M[i][j] = 1;
        }
    }
    int ans=0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(M[i][j] == 0) {
                bool f1=true,f2=true;
                for (int k = 0; k < r; k++) if(M[k][j]==1) f1=false;
                for (int l = 0; l < c; l++) if(M[i][l]==1) f2=false;
                if(!f1 && !f2) ans++;
            }
            else ans++;
        }
    }
    cout << (r*c)-ans;
    return EXIT_SUCCESS;
}
