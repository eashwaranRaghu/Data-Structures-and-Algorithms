// Created on 14-07-2019 17:54:30 by necronomicon
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
Given Undirected weighted graph in edge list
Algo:
    First add arbitrary node to the tree. And keep hash/track for added nodes.
    Then select a minimum-edge that adds a new node to the tree and add it.
    MST is created.
Uses Adj list because on discovery of a new node we need all its neighbours.
Similarity with Dijkstra: Both uses PQ and get the least costly egde.
In practice, Prim’s and Kruskal’s algorithms are both efficient. use kruskal cuz its simple to implement. no PQ comparator needed
*/


void prim(vector<VPii> Adj, VVi &EdgResult, int &totalWeight, Vi &discovered){
    auto comp = [] (Vi a, Vi b){ return a[0] > b[0];};
    priority_queue<Vi, VVi, decltype(comp)> Q(comp); // w, a, b
    discovered[0] = true;
    Q.push({0,0,0});
    for(Pii p: Adj[0]){
        Q.push({p.second, 0, p.first});
    }
    while(!Q.empty()){
        Vi top = Q.top(); Q.pop();
        if(!discovered[top[2]]){
            discovered[top[2]] = 1;
            totalWeight += top[0];
            EdgResult.push_back(top);
            for(Pii p: Adj[top[2]]){
                Q.push({p.second, top[2], p.first});
            }
        }
    }
}

int main (int argc, char const *argv[]) {
    int N = 10; // total elements;
	Vi discovered(N, 0);
    vector<VPii> Adj; // Edge list
    VVi EdgResult; // stores end result MST created (IMP)
    int totalWeight = 0; // stores total weight of the MST

    Adj = {
        {{3,9}, {1,5}, {4,1}},
        {{2,2}, {0,5}},
        {{3,6}, {1,2}},
        {{4,2}, {0, 9}, {2,6}},
        {{3,2}, {0,1}},
    };

    prim(Adj, EdgResult, totalWeight, discovered);
    cout  << "total weight is: " << totalWeight << endl << endl;
    for(Vi E: EdgResult){
        for(int e: E){
            cout << e << ' ';
        }
        cout << endl;
    } 
    return EXIT_SUCCESS;
}
