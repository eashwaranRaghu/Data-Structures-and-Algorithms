// 19-11-2019 21:07:01 badLiver
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
	int n, a,b,c;
    cin >> n;
    VVi p(n);
    map<int, Vi> M;
    VVi neigh(n);
    for (int i = 0; i+2 < n; i++)
    {
        cin >> a >> b >> c;
        p[i] = {a,b,c};
        M[a].push_back(i);
        M[b].push_back(i);
        M[c].push_back(i);
    }
    for (int i = 0; i+2 < n; i++)
    {
        a = p[i][0], b = p[i][1], c = p[i][2];

        for (int j = 0; j < M[a].size(); j++)
        {
            if(M[a][j] == i) continue;
            for (int k = 0; k < M[b].size(); k++)
            {
                if(M[b][k] == i) continue;
                for (int l = 0; l < M[c].size(); l++)
                {
                    if(M[c][l] == i) continue;

                    if(M[a][j] == M[b][k]) {
                        neigh[i].push_back(M[a][j]);
                        neigh[M[a][j]].push_back(i);
                    }
                    else if(M[b][k] == M[c][l]) {
                        neigh[i].push_back(M[b][k]);
                        neigh[M[b][k]].push_back(i);
                    }
                    else if(M[a][j] == M[c][l]) {
                        neigh[i].push_back(M[a][j]);
                        neigh[M[a][j]].push_back(i);
                    }
                }
            }
        }
        
    }
    
    Vi order;
    int head=0;
    for (int i = 0; i+2 < n; i++)
    {
        if(neigh[i].size() == 1) {
            head = i;
            break;
        }
    }
    order.push_back(head);
    int prev = head;
    head = neigh[head][0];
    while(true)
    {
        order.push_back(head);
        if(neigh[head].size() == 1) {
            break;
        }
        if(neigh[head][0] != prev) {
            prev = head;
            head = neigh[head][0];
        }
        else {
            prev = head;
            head = neigh[head][1];
        }
    }
    
    Vi ans;
    for (int i = 1; i+1 < order.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num = p[order[i]][j];
            if((p[order[i-1]][0]==num || p[order[i-1]][1]==num || p[order[i-1]][2]==num) && (p[order[i+1]][0]==num || p[order[i+1]][1]==num || p[order[i+1]][2]==num)) {
                ans.PB(num);
                j=10;
            }
        }
    }
    int z;
    for (int i = 0; i < 3; i++)
    {
        int num = p[order[0]][i];
        if(num != p[order[1]][0] && num != p[order[1]][1] && num != p[order[1]][2]) {
            cout << num << ' ';
            z=num;
            break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if(p[order[0]][i] != ans[0] && p[order[0]][i] != z) cout << p[order[0]][i] << ' ';
    }
    for (int x: ans) cout << x << ' ';
    for (int i = 0; i < 3; i++)
    {
        int num = p[order[order.size()-1]][i];
        if(num != p[order[order.size()-2]][0] && num != p[order[order.size()-2]][1] && num != p[order[order.size()-2]][2]) {
            z = num;
            break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if(p[order[order.size()-1]][i]!=z && p[order[order.size()-1]][i] != ans[ans.size()-1]) cout << p[order.size()-1][i] << ' ';
    }
    cout << z;
    return EXIT_SUCCESS;
}
