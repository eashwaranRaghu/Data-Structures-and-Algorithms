// Created on 14-07-2019 15:39:57 by necronomicon
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
First, distances are calculated only using direct edges between
the nodes, and after this, the algorithm reduces distances by using intermediate
nodes in paths.
Its equivalent to running BellmanFord for each node.

    Time Complexity: O(n³);
    Space Complexity: O(n²);

1. initially distance to all is i (infity);
2. use adj list or edge list to get the distances
3. run n³ algorithm which uses dynamic programming and updated distances based on intermediate edges.
    It check if there exists a path to a and b through node c. In worst case the c can be N-2
    hence we have to run the n² algorithm n times which makes it n³
[i i i i i] -> [0 5 i 9 1] -> [0 5 7 3 1] 
[i i i i i] -> [5 0 2 i i] -> [5 0 2 8 6] 
[i i i i i] -> [i 2 0 6 i] -> [7 2 0 6 8] 
[i i i i i] -> [9 i 6 0 2] -> [3 8 6 0 2] 
[i i i i i] -> [1 i i 2 0] -> [1 6 8 2 0]
 */

void floydWarshall(VVi &distance){
    int N = distance.size();
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) for(int k = 0; k < N; k++) distance[j][k] = min(distance[j][k], distance[j][i]+distance[i][k]);
}

int main (int argc, char const *argv[]) {

    int N = 5; // Distance to all nodes
    int source = 4; // source node
    VVi distance; // contains distance of all nodes from source
	vector<VPii> Adj; // Adjency list contains egdes with weights in pair
    distance.resize(N, Vi(N,99));
    Adj = {
        {{3,9}, {1,5}, {4,1}},
        {{2,2}, {0,5}},
        {{3,6}, {1,2}},
        {{4,2}, {0, 9}, {2,6}},
        {{3,2}, {0,1}}
    };
    
    for (int i = 0; i < N; i++) distance[i][i] = 0;
    for (int i = 0; i < Adj.size(); i++)
    {
        for (int j = 0; j < Adj[i].size(); j++)
        {
            distance[i][Adj[i][j].first] = Adj[i][j].second;
        }
    }
    for (int i = 0; i < distance.size(); i++){
        for (int j = 0; j < distance.size(); j++){
            cout << distance[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl << endl;;
    floydWarshall(distance);

    for (int i = 0; i < distance.size(); i++){
        for (int j = 0; j < distance.size(); j++){
            cout << distance[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    return EXIT_SUCCESS;
}
