// Created on 25-06-2019 12:31:27 by necronomicon
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
string s;
int n, ans;
Pii p, pp;
void bfs (vector<Vi> v){
    Vi visited;
    visited.assign(n, 0);
    queue <Pii> q;
    p.first = 0;
    p.second = 0;
    q.push(p);
    while(!q.empty()){
        Pii front = q.front();
        q.pop();
        if(front.first == n-1){
            ans = front.second+1;
            return;
        }
        if(visited[front.first]) continue;
        else{
            visited[front.first] = 1;
            for (int i = 0; i < v[front.first].size(); i++)
            {
                pp.first = v[front.first][i];
                pp.second = front.second+1;
                if(visited[pp.first]) continue;
                q.push(pp);
            }
        }
    }

}

int main () {
    cin >> s;
    n = s.size();
    vector <Vi> v;
    unordered_map <int, Vi> m;
    for (int i = 0; i < s.size(); i++)
    {   Vi u;
        if(i>0) u.push_back(i-1);
        if(i+1<s.size()) u.push_back(i+1);
        v.push_back(u);
        m[s[i]].push_back(i);
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int  j = 0; j < m[s[i]].size(); j++)
        {
            if(m[s[i]][j] != i){
                v[i].push_back(m[s[i]][j]);
            }
        }
        
    }
    bfs(v);
    cout << ans-1;
    return EXIT_SUCCESS;
}
