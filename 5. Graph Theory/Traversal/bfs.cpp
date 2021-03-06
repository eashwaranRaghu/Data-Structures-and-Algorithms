// Created on 14-07-2019 11:56:14 by necronomicon
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

void bfsStack(Vi adj[], bool visited[], int k){
    queue <int> S;
    S.push(k);
    while(!S.empty()){
        int front = S.front();
        S.pop();
        if(visited[front]) continue;
        else{
            cout << front << ' ';
            visited[front] = true;
            for(int x: adj[front]) S.push(x);
        }
    }
}

int main (int argc, char const *argv[]) {
    int N = 6; // number of nodes
	Vi adj[N];
    bool visited[N];
    adj[1] = {2,3};
    adj[2] = {0, 5};
    adj[3] = {2};
    adj[5] = {4, 3};
    for(int i=0; i<N; i++) visited[i]=false;
    bfsStack(adj, visited, 1);
    return EXIT_SUCCESS;
}
