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
Lemma: In a DAG there is atleast 1 node with indegree 0 and 1 with outdegree 0.
In a DAG there is always atleast 1 source and 1 sink
Modified BFS cuz uses que and it travels top to bottom along DAG.
Algo
		○ find indegree of all nodes. in inDegree
		○ enque all nodes with 0 indegree. in Q
		○ deque a node and for all its neignbours dec indegree. If indegree hits 0 enque it.
    Time Complexity: O(n) just like bfs
    Space Complexity: O(n) uses queue
 */

void kahn(VVi adj, Vi &inDegree, int source, Vi &result){
    Qi Q;
    for(int i=0; i<adj.size(); i++){
        for(int j=0; j<adj[i].size(); j++){
            inDegree[adj[i][j]]++;
        }
    }
    for(int i=0; i<inDegree.size(); i++) if(inDegree[i] == 0) Q.push(i);
    while(!Q.empty()){
        int top = Q.front(); Q.pop();
        result.push_back(top);
        for(int i=0; i<adj[top].size(); i++){
            inDegree[adj[top][i]]--;
            if(inDegree[adj[top][i]] == 0) Q.push(adj[top][i]);
        }
    }
}


int main (int argc, char const *argv[]) {
    int N = 10; // number of nodes
	VVi adj;
    Vi inDegree(N, 0);
    Vi result;
    int source = 0;

    adj = {
        {1,2},
        {4},
        {4},
        {},
        {5},
        {6},
        {7,8},
        {9},
        {9},
        {3},
    };
    kahn(adj, inDegree, source, result);
    for(int i=0; i<result.size(); i++) cout << result[i] << ' '; cout << endl;
    return EXIT_SUCCESS;
}
