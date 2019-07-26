// Created on 17-07-2019 00:21:08 by necronomicon
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

//global vars
VVi Adj;
Vi visited;

// unvisited = 0, visited=1, finished=2

bool hasCycle(int k){
    if(visited[k] == 1) return true;
    else if(visited[k] == 2) return false;
    else{
        visited[k] = 1;
        bool ans = false;
        for (int b: Adj[k])
        {
            ans = ans || hasCycle(b);
        }
        visited[k] = 2;
        return ans;
    }
}


int main (int argc, char const *argv[]) {
	
    // adjacency list

    // Adj = {
    //     {1,2},
    //     {0,2},
    //     {0,1,3,5},
    //     {2,4},
    //     {3},
    //     {2,6,8},
    //     {5,7},
    //     {6,8},
    //     {5,7}
    // };

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
    
    // Adj = {
    //     {1,2,3},
    //     {0,4,5},
    //     {0},
    //     {0,6},
    //     {1},
    //     {1},
    //     {3}
    // };
    // Adj = {
    //     {1,2},
    //     {1,3,3},
    //     {0,4,1},
    //     {5,2},
    //     {5},
    //     {2}
    // };
    Adj = {
        {1},
        {2},
        {3},
        {0},
    };

    visited = Vi(Adj.size(), 0);
    cout << hasCycle(0); // should use forloop in case of disconnected components
    return EXIT_SUCCESS;
}
