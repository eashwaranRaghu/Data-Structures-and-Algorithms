// Created on 19-06-2019 20:37:20 by necronomicon
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
        int temp1, temp2, e, col[1000];
        Vi v[1000];
        cin >> e;
        for (int i = 0; i < e; i++)
        {
            cin >> temp1 >> temp2;
            v[temp1].push_back(temp2);
            v[temp2].push_back(temp1);
        }
        for (int i = 0; i < 1000; i++) col[i] = 0;
        queue <int> q;
        q.push(0);
        int colour = 1;
        col[0] = colour;
        int flag = 1;
        while(!q.empty()){
            temp1 = q.front();
            q.pop();
            colour *= -1;
            // cout << temp1 << ':' << colour << endl;
            for(auto d : v[temp1]){
                if(col[d] == 0){ 
                    q.push(d);
                    col[d] = colour;
                }
                else{
                
                    if(col[d] != colour) {cout << d << ':' << colour << endl; flag = 0;}
                }
            }
        }
        cout << endl;
        for(int i=0; i<n; i++) cout << col[i];
        cout <<endl << flag << endl << endl;
    }
    return EXIT_SUCCESS;
}
