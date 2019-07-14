// Created on 14-07-2019 14:46:28 by necronomicon
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
The algorithm can process all kinds of graphs, provided that
the graph does not contain a cycle with negative length. If the graph contains a
negative cycle, the algorithm can detect this. With an extra cycle which will decrease distance.
    Time Complexity: O(VE);
    Space Complexity: O(V + E); node list and egde list

Initially assign 0 to the source in distance array and run N-1 cycles.
In each cycle iterate the egde-list and improve the distance for each a->b.
To detect a negative cycle we can run it 1 extra cycle which will result in
furthur reduction in distance.
Q Why N-1 cycles?
A Let graph be a LL in worst case, then we have to traverse N-1 times atleat to get answer.
 */

void bellmanFord(Vi &distance, VVi Edg, int source){
    int N = distance.size();
    for (int i = 0; i < N; i++) distance[i] = INF;
    distance[source] = 0;
    for (int i = 1; i < N; i++)
    {
        for (Vi e: Edg)
        {
            int a = e[0],
            b = e[1],
            w = e[2];
            distance[b] = min(distance[b], distance[a]+w);
        }
    }
}

int main (int argc, char const *argv[]) {
    int N = 10; // Distance to all nodes
    int source = 1; // source node
    Vi distance(N);
	VVi Edg; // Edge list
    Edg.push_back({1,3,3});
    Edg.push_back({1,2,5});
    Edg.push_back({1,4,7});
    Edg.push_back({3,4,1});
    Edg.push_back({2,5,2});
    Edg.push_back({4,5,2});
    bellmanFord(distance, Edg, source);
    for (int i = 0; i < distance.size(); i++) cout << distance[i] << ' ';
    cout << endl;
    return EXIT_SUCCESS;
}
