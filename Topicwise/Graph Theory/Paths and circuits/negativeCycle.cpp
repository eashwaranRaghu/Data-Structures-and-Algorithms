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
vector<VPii> Adj;
Vi visited;
Vi weight;

// unvisited = 0, visited=1, finished=2

bool hasNegativeCycle(int k, int sum){
    // cout << k << ' ';
    if(visited[k] == 1){
        if(sum-weight[k] < 0) return true;
        else return false;
    }
    if(visited[k] == 2) return false; 
    else{
        visited[k] = 1;
        weight[k] = sum;
        bool ans = false;
        for (Pii b: Adj[k])
        {
            ans = ans || hasNegativeCycle(b.first, sum + b.second);
        }
        visited[k] = 2;
        return ans;
    }
}


int main (int argc, char const *argv[]) {
	
    // adjacency list

    Adj = {
        {{1, 0}},
        {{2, 0}},
        {{3, -1}},
        {{2, 1}},
    };

    visited = Vi(Adj.size(), 0);
    weight = Vi(Adj.size(), 0);

    cout << hasNegativeCycle(0, 0); // should use forloop in case of disconnected components

    return EXIT_SUCCESS;
}
