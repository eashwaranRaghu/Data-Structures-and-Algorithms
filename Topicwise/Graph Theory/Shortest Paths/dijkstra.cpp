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
Like the Bellman–Ford algorithm, Dijkstra’s algorithm maintains distances
to the nodes and reduces them during the search. Dijkstra’s algorithm is efficient,
because it only processes each edge in the graph once, using the fact that there
are no negative edges.
A remarkable property in Dijkstra’s algorithm is that whenever a node is
selected, its distance is final.
    Time Complexity: O(E*log(E+V)); log(E+V) because same node can be added multiple times in heap with diff distances.
    Space Complexity: O(); distance of nodes + processedNodes vector + min heap for nodes
Q Why cant work with -ve edges?
A Because it selects minimum weight node over other and may ignore the -ve edge which may reduce distance.

 */

void dijkstra(Vi &distance, vector<vector<Pii>> Adj, int source){
    int N = distance.size();
    priority_queue <Pii> heap;
    Vi processed(N, 0);
    for (int i = 0; i < N; i++) distance[i] = INF; // distance to all nodes is infinity except source
    distance[source] = 0;
    heap.push({0, source}); // initially we put source to min-heap
    while(!heap.empty()){
        int top = heap.top().second; heap.pop();
        if(processed[top] != 0) continue;
        processed[top] = 1;
        for(Pii x: Adj[top]){
            int b = x.first,
            w = x.second;
            if(distance[b] > distance[top]+w){
                distance[b] = distance[top]+w;
                heap.push({distance[b], b});
            }
        }
    }
}

int main (int argc, char const *argv[]) {

    int N = 5; // Distance to all nodes
    int source = 4; // source node
    Vi distance(N); // contains distance of all nodes from source
	vector<vector<Pii>> Adj; // Adjency list contains egdes with weights in pair
    Adj = {
        {{3,9}, {1,5}, {4,1}},
        {{2,2}, {0,5}},
        {{3,6}, {1,2}},
        {{4,2}, {0, 9}, {2,6}},
        {{3,2}, {0,1}}
    };

    dijkstra(distance, Adj, source);

    for (int i = 0; i < distance.size(); i++) cout << i << ':' << distance[i] << endl;
    cout << endl;

    return EXIT_SUCCESS;
}
