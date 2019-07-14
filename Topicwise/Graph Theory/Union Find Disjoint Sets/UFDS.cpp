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
A union-find structure maintains a collection of sets. The sets are disjoint,
so no element belongs to more than one set. Two O(logn) time operations are
supported:
    UNITE operation joins two sets, and 
    FIND operation finds the representative of the set that contains a given element2.
    Initially each element represents itself.
Use an array(vector) in which we store pointer(iterator/index) of set's representitive or itself.
RULE: Always connect the representative of the smaller set to the representative of the larger set and chain will be O(logn).
    UNITE calls SAME and finds each sets representative and joins smaller set to larger set in O(log(n)).
    FIND now follows the chain to the node which represents itself in O(log(n)).
    FINDPRO uses recursion/(stack) and updates the representative of each node that falls in path to final value. This speeds up followinig searches.
    SAME runs FIND on 2 nodes and checks if their representative is same or not in O(log(n));
    COUNTSETS iterates the UFDS and counts all nodes which represent themselves.
 */

int find(Vi &DS, int p){
    while(p!=DS[p]){
        p = DS[p];
    }
    return p;
}

int findPro(Vi &DS, int p){
    if(p == DS[p]) return p;
    int result = findPro(DS, DS[p]);
    DS[p] = result;
    return result;
}

bool same(Vi &DS, int i, int j){
    return find(DS, i) == find(DS, j);
}

void unite(Vi &DS, Vi &size, int i, int j){
    if(!same(DS, i, j)) {
        i = find(DS, i);
        j = find(DS, j);
        if(size[i] < size[j]) swap(i,j);
        DS[j] = i;
        size[i] += size[j];
        size[j] = 0;
    }
}

int countSets(Vi &DS){
    int total = 0;
    for (int i = 0; i < DS.size(); i++) if(DS[i] == i) total++;
    return total;
}

int main (int argc, char const *argv[]) {
    int N = 10; // total elements;
	Vi DS(N), size(N);
    for(int i=0; i<N; i++){
        DS[i] = i;
        size[i] = 1;
    }
    for(int i = 0; i<DS.size(); i++) cout << DS[i] << ' '; cout << endl; 
    cout << find(DS, 1) << ' ' << countSets(DS) << endl;
    unite(DS, size, 1, 2);
    cout << find(DS, 2) << ' ' << countSets(DS) << endl;
    for(int i = 0; i<DS.size(); i++) cout << DS[i] << ' '; cout << endl;
    unite(DS, size, 1, 3);
    cout << find(DS, 3) << ' ' << countSets(DS) << endl;
    for(int i = 0; i<DS.size(); i++) cout << DS[i] << ' '; cout << endl;
    unite(DS, size, 1, 4);
    cout << find(DS, 7) << ' ' << countSets(DS) << endl;
    for(int i = 0; i<DS.size(); i++) cout << DS[i] << ' '; cout << endl;
    unite(DS, size, 8, 9);
    cout << find(DS, 9) << ' ' << countSets(DS) << endl;
    for(int i = 0; i<DS.size(); i++) cout << DS[i] << ' '; cout << endl;
    return EXIT_SUCCESS;
}
