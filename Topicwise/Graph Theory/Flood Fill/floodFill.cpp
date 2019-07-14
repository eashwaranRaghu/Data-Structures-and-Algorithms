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

/* 
Replace one given intial color with final color connected to the position.
eg. bucket fill in paint/photoshop
 */

// Flood-Fill on implicit graph using Adj-Matrix
void dfsImplicit(VVi &adj, int x, int y, int initialColor, int finalColor){
    if(adj[x][y] == finalColor) return;
    else if(adj[x][y] != initialColor) return;
    else{
        adj[x][y] = finalColor;
        if(x+1 < adj.size()) dfsImplicit(adj,x+1,y,initialColor,finalColor);
        if(x-1 > -1) dfsImplicit(adj,x-1,y,initialColor,finalColor);
        if(y+1 < adj.size()) dfsImplicit(adj,x,y+1,initialColor,finalColor);
        if(y-1 > -1) dfsImplicit(adj,x,y-1,initialColor,finalColor);
    }
}
void floodFillImplicit(){
    int N = 5; // number of nodes
    VVi adj= {
        {1,0,0,1,0},
        {0,1,0,0,0},
        {0,1,0,0,1},
        {1,0,0,0,1},
        {0,0,1,0,0},
    };
    int x=2, y=2;
    for (Vi v: adj){
        for(int x: v) cout << x << ' ';
        cout << endl;
    }
    cout << endl;
    dfsImplicit(adj, x, y, 0, 3);
    for (Vi v: adj){
        for(int x: v) cout << x << ' ';
        cout << endl;
    }
}


// Flood-Fill on directed explicit graph using Adj-List
void dfsExplicit(Vi adj[], bool visited[], int k){
    if(visited[k]) return;
    visited[k] = true;
    cout << k << ' ';
    for(int x: adj[k]) dfsExplicit(adj, visited, x);
}
void floodFillExplicit(){
    int N = 6; // number of nodes
	Vi adj[N];
    bool visited[N];
    adj[1] = {2};
    adj[2] = {0, 5};
    adj[3] = {2};
    adj[5] = {4, 3};
    for(int i=0; i<N; i++) visited[i]=false;
    for(int i=0; i<N; i++){
        dfsExplicit(adj, visited, i);
        cout << ':';
    }
}

int main (int argc, char const *argv[]) {
    floodFillExplicit();
    cout << endl << endl;;
    floodFillImplicit();
    return EXIT_SUCCESS;
}
