// Created on 15-07-2019 18:51:46 by necronomicon
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
We need 3 vectors : visited, ids and low (explained below)
Slow Algo:
    Run dfs and find number of Connected components
    for each vertex, remove it and run dfs, see if number of Connected Components increase. If it does then its an articulation point.
    for each edge remove it and see if number of Connected Components increase. If it does then its an bridge.
Faster algo takes O(n) check it in single dfs.
    Doesnt count if CC increase
Algo:
    call dfs with 2 params the node to visit and its parent.
    increment the global id/time
    assign this node's id and low with it
    call all the children of this node
        if the node has children as parent skip it
        if the child is already visited and child has lower low than id of current node then this child is an ancestor.
        else child isnt discovered
            if its low is lesser than id of current then this is bridge
            if its low is lesser than or equal to id of current then this is artPoint
    Time Complexity: O(n)
    Space Complexity: O(n)

below links have same implementations
https://cp-algorithms.com/graph/cutpoints.html
https://www.youtube.com/watch?v=aZXi1unBdJA
*/

int id;
vector<bool> visited;
Vi  ids; // stores uniqueId or timestamp based on discovery of node during dfs
Vi low; // stores the minimum uniqueId reachable from that node
VPii bridges; //contains the list of bridge-edges which can break the graph into more sets
Vi articulationPoints; //contains the list of cut-points which can break the graph into more sets

void dfs(VVi Adj, int at, int parent){
    visited[at] = true;
    id++;
    low[at] = ids[at] = id;
    int children = 0;
    for (int to: Adj[at])
    {
        if(to == parent) continue; // if backedge to parent we dont do anything
        if(visited[to]){ // this is backedge to an ancestor and we need its id as our low
            low[at] = min(low[at], ids[to]);
        }
        else{ // a child is discovered which is undiscovered and we need to update our low with its low (not its id)
            dfs(Adj, to, at);
            low[at] = min(low[at], low[to]);
            if(ids[at] < low[to]){ // if child (to) is not linked to an ancestor above (at)
                bridges.push_back({at, to});
            }
            if(ids[at] <= low[to] && parent != -1){ // if the child has lowest 
                articulationPoints.push_back(at);
            }
            children++; // only required for checking if the root can be an articulation point. When dfs starts from root and marks all nodes visited then this remains 1 hence not artPoint.
        }
    }
    if(parent == -1 && children > 1){
        articulationPoints.push_back(at);
    }
}

void find(VVi Adj){
    visited = vector<bool>(Adj.size(), false),
    ids = Vi(Adj.size(), 0),
    low = Vi(Adj.size(), 0),
    id = -1;
    bridges.clear();
    articulationPoints.clear();
    for(int i=0; i<Adj.size(); i++){
        if(!visited[i]){
            dfs(Adj, i, -1);
        }
    }
}

int main (int argc, char const *argv[]) {
    VVi Adj; // Adjency list
    
    Adj = {
        {1,2},
        {0,2},
        {0,1,3,5},
        {2,4},
        {3},
        {2,6,8},
        {5,7},
        {6,8},
        {5,7}
    };

    // Adj = {
    //     {1},
    //     {2,3,4,5},
    //     {1},
    //     {1},
    //     {1, 5},
    //     {1, 4}
    // };

    // Adj = {
    //     {1,2},
    //     {0,2},
    //     {0,1}
    // };

    find(Adj);

    std::for_each(std::begin(bridges), std::end(bridges), [](Pii p) {
      cout << p.first << ' ' << p.second << endl;
    });
    cout << endl;
    std::for_each(std::begin(articulationPoints), std::end(articulationPoints), [](int x) {
      cout << x << ' ';
    });
    return EXIT_SUCCESS;
}
