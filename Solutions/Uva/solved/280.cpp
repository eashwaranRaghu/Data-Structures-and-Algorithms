// Created on 17-06-2019 15:59:38 by necronomicon
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

int main () {
	int n;
    while(cin >> n && n){
        int temp, t;
        Vi v[109], u;
        int idx;
        while(cin >> idx && idx){
            while(cin >> temp && temp){
                v[idx].push_back(temp);
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     int idx;
        //     cin >> idx;
        //     if(idx == 0) break;
        //     while(cin >> temp && temp){
        //         // cout << temp;
        //         v[idx].push_back(temp);
        //     }        
        // }
        cin >> t;
        // cout << ' ' << t << ' ';
        for (int j = 0; j < t; j++)
        {
            cin >> temp;
            // cout << temp;
            u.push_back(temp);
        }   
        for (int i = 0; i < u.size(); i++)
        {
            Vi axs, visited(n);
            visited.assign(n, 0);
            //bfs
            Qi q;
            int count = 0;
            for (int j = 0; j < v[u[i]].size(); j++)
            {
                q.push(v[u[i]][j]);
            }
            while(!q.empty()){
                int front = q.front();
                q.pop();
                if(visited[front-1] == 1) continue;
                else{
                    visited[front-1] = 1;
                    count++;
                    for (int j = 0; j < v[front].size(); j++)
                    {
                        q.push(v[front][j]);
                    }
                }
            }
            cout << n - count;
            for (int j = 0; j < visited.size(); j++)
            {
                if(visited[j] == 0) cout << ' ' << j+1;
            }
            cout << endl;
        }
        

    }
    return EXIT_SUCCESS;
}
