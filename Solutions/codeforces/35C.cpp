// 14-11-2019 09:04:33 badLiver
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

Vi xa = {-1, 1, 0, 0}, ya = {0, 0, -1, 1};
bool visited[2009][2009];
int M[2009][2009];

int main (int argc, char const *argv[]) {
	int n, m, k, x, y, z;
    cin >> n >> m >> k;
    for (int ii = 0; ii < n; ii++) for (int jj = 0; jj < m; jj++) M[ii][jj]=numeric_limits<int>::max();
    for (int i = 0; i < k; i++)
    {
        for (int ii = 0; ii < n; ii++) for (int jj = 0; jj < m; jj++) visited[ii][jj]=false;
        cin >> x >> y;
        x--; y--;
        visited[x][y]=true;
        queue<Vi> Q;
        Q.push({x,y, 0});

        while(!Q.empty()) {
            x = Q.front()[0], y = Q.front()[1], z = Q.front()[2];
            Q.pop();
            if(M[x][y] > z) {
                M[x][y] = z;
                for (int j = 0; j < xa.size(); j++)
                {
                    if(x+xa[j] >= 0 && x+xa[j] < n && y+ya[j]>=0 && y+ya[j] < m) {
                        if(visited[x+xa[j]][y+ya[j]] == 0) {
                            visited[x+xa[j]][y+ya[j]] = 1;
                            Q.push({x+xa[j], y+ya[j], z+1});
                        }
                    }
                }
            }
        }
    }
    int mx=numeric_limits<int>::min();
    int a=1, b=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mx < M[i][j]) {
                mx = M[i][j];
                a=i, b=j;
            }
        }
    }
    cout << a+1 << ' ' << b+1;
    return EXIT_SUCCESS;
}
