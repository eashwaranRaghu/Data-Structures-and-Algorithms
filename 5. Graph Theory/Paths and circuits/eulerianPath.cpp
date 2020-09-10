// Created on 17-07-2019 00:21:08 by necronomicon
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

//global vars
VVi Adj;
Vi in, out;
Vi path;

void countInOut(){
    VPii V(Adj.size(), {0,0});
    for (int i = 0; i < Adj.size(); i++)
    {
        for (int j = 0; j < Adj[i].size(); j++)
        {
            out[i]++;
            in[Adj[i][j]]++;
        }
    }
}

bool hasEulerianPath(){
    int start_nodes =0, end_nodes =0;
    for (int i = 0; i < in.size(); i++)
    {
        int diff = out[i] - in[i];
        if(diff > 1 || diff < -1) return false;
        if(diff == 1) start_nodes++;
        if(diff == -1) end_nodes++;
    }
    return start_nodes == end_nodes;
}

int getSartNode(){
    int start = 0;
    for (int i = 0; i < in.size(); i++)
    {
        if(out[i]-in[i] == 1) return i;
        if(out[i] > 0 ) start = i;
    }
    return start;
}

void travel(int at){
    while(Adj[at].size()){
        int next = Adj[at][Adj[at].size()-1];
        Adj[at].pop_back();
        travel(next);
    }
    path.push_back(at);
}
void eulerianPath(){
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << ':' << out[i] << endl;
    } cout << endl;
    in = out = Vi(Adj.size(), 0);
    path.clear();
    countInOut();
    if(!hasEulerianPath()){
        cout << "graph has no path" << endl;
        return;
    } cout << "graph has a path" << endl;
    int start = getSartNode();
    cout << "start_node : " << start << endl;
    travel(start);
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
    Adj = {
        {1,2},
        {1,3,3},
        {0,4,1},
        {5,2},
        {5},
        {2}
    };
    
    eulerianPath();
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << ':' << out[i] << endl;
    } cout << endl;
    cout<<path.size()<<endl;
    std::for_each(std::begin(path), std::end(path), [](int a) {
      cout << a << '-';
    });
    return EXIT_SUCCESS;
}
