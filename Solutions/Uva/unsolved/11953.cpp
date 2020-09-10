// Created on 19-06-2019 12:08:16 by necronomicon
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
	int t, n, visited[1000][1000], flood[1000][1000];
    string temp, arr[1000];
    cin >> t;
    for (int i = 1; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            arr[i] = temp;
            for (int k = 0; k < n; k++)
            {
                visited[i][j] = 0;
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if(arr[j][k] == 'x' && visited[j][k] == 0){

                    if(arr[i+1][j] != '.' && visited[j][k] == 0){
                        for (int l = 0; l < n/2; l++)
                        {
                            visited[j+l][k] = 1;
                        }
                    }
                    else if(arr[i][j+1] != '.' && visited[j][k] == 0){
                        for (int l = 0; l < n/2; l++)
                        {
                            visited[j][k+l] = 1;
                        }  
                    }

                }
            }
            
        }
        
        
    }
    
    return EXIT_SUCCESS;
}
