// Created on 14-07-2019 11:10:00 by necronomicon
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
Replace one given intial color with final color connected to the position.
eg. bucket fill in paint/photoshop
 */

void bfsStackImplicit(VVi &adj, Pii p, int initialColor, int finalColor){
    queue <Pii> S;
    S.push(p);
    while(!S.empty()){
        Pii front = S.front();
        S.pop();
        if(adj[front.first][front.second] == finalColor) continue;
        else if(adj[front.first][front.second] != initialColor) continue;
        else{
            adj[front.first][front.second] = finalColor;
            if(front.first+1 < adj.size()) S.push({front.first+1, front.second});
            if(front.first-1 > -1) S.push({front.first-1, front.second});
            if(front.second+1 < adj.size()) S.push({front.first, front.second+1});
            if(front.second-1 > -1) S.push({front.first, front.second-1});
        }
    }
}
void forestFireImplicit(){
    int N = 5; // number of nodes
    VVi adj= {
        {1,0,0,1,0},
        {0,1,0,0,0},
        {0,1,0,0,1},
        {1,0,0,0,1},
        {0,0,1,0,0},
    };
    int x=2, y=2;
    for (Vi v: adj){
        for(int x: v) cout << x << ' ';
        cout << endl;
    }   cout << endl;
    bfsStackImplicit(adj, {x,y}, 0, 3);
    for (Vi v: adj){
        for(int x: v) cout << x << ' ';
        cout << endl;
    }   cout << endl;
}

int main (int argc, char const *argv[]) {
    forestFireImplicit();
    return EXIT_SUCCESS;
}
