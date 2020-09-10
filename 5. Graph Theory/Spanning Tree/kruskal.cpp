// Created on 14-07-2019 17:54:30 by necronomicon
#include <bits/stdc++.h>
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
    Sort the edge list based on weight
    Keep adding edges to graph and skip if it forms a cycle.
    Result is a MST in nlogn

    Time Complexity: O(Elog(E)) due to sorting and UFDS
    Space Complexity: O(V+E) storing edge list and graph in array
*/

int find(Vi &DS, int p){
    while(p!=DS[p]){
        p = DS[p];
    }
    return p;
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

void kruskal(VVi Edg, VVi &EdgResult, int &totalWeight, Vi &DS, Vi &size){
    sort(Edg.begin(), Edg.end(), [] (Vi a, Vi b) {return a[2] < b[2];}); // sorting edges based on their weights
    for(int i = 0; i<DS.size(); i++) cout << DS[i] << ' '; cout << endl; 
    for (Vi E: Edg)
    {
        if(!same(DS, E[0], E[1])){
            unite(DS, size, E[0], E[1]);
            totalWeight += E[2];
            EdgResult.push_back(E);
        }
    }
}

int main (int argc, char const *argv[]) {
    int N = 10; // total elements;
	Vi DS(N), size(N); // DS stores the sets (UFDS) in O(V), size stores size of each set in hash table
    for(int i=0; i<N; i++){
        DS[i] = i;
        size[i] = 1;
    }
    VVi Edg; // Edge list
    VVi EdgResult; // stores end result MST created (IMP)
    int totalWeight = 0; // stores total weight of the MST
    Edg.push_back({1,3,3});
    Edg.push_back({1,2,5});
    Edg.push_back({1,4,7});
    Edg.push_back({3,4,1});
    Edg.push_back({2,5,2});
    Edg.push_back({4,5,2});

    kruskal(Edg, EdgResult, totalWeight, DS, size);

    for(int i = 0; i<DS.size(); i++) cout << DS[i] << ' '; cout << endl << endl; 
    cout  << "total weight is: " << totalWeight <<endl << endl;
    for(Vi E: EdgResult){
        for(int e: E){
            cout << e << ' ';
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
