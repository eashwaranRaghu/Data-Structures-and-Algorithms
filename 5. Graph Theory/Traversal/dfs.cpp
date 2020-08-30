// Created on 14-07-2019 11:10:00 by necronomicon
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

// dfs using recursion
void dfsRecursion(VVi adj, vector<bool> &visited, int k){
    if(visited[k]) return;
    visited[k] = true;
    cout << k << ' ';
    for(int x: adj[k]) dfsRecursion(adj, visited, x);
}

// dfs using stack
void dfsStack(VVi adj, vector<bool> &visited, int k){
    stack <int> S;
    S.push(k);
    while(!S.empty()){
        int top = S.top();
        S.pop();
        if(visited[top]) continue;
        else{
            cout << top << ' ';
            visited[top] = true;
            for(int x: adj[top]) S.push(x);
        }
    }
}

int main (int argc, char const *argv[]) {
    int N = 6; // number of nodes
	VVi adj;
    vector<bool> visited(N, false);
    adj = {
        {},
        {2},
        {0, 5},
        {2},
        {4, 3},
        {}
    }; 
    for(int i=0; i<N; i++) visited[i]=false;
    dfsRecursion(adj, visited, 1);
    cout << endl;
    for(int i=0; i<N; i++) visited[i]=false;
    dfsStack(adj, visited, 1);
    return EXIT_SUCCESS;
}
