// Created on 12-05-2019 06:52:14 by necronomicon
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

int col[30], row[30], diag1[30], diag2[30], n = 8, Sol[100][8], A[8];
int t, xx, yy, temp, c;

void rec(int y){
    if(y == n){
        for (size_t i = 0; i < n; i++)
        {
            row[col[i]-1] = i+1;
        }
        for (size_t i = 0; i < n; i++)
        {
            Sol[c][i] = row[i];
        }
        c++;
        return;
    }
    for (int i=0; i<n; i++)
    {
        if(col[i] || diag1[y+i] || diag2[i-y+n-1]) continue;
        // if(i == yy-1 && y+1 != xx) continue;
        col[i] = y+1;
        diag1[i+y] = diag2[i-y+n-1] = 1;
        rec(y+1);
        col[i] = 0;
        col[i] = diag1[i+y] = diag2[i-y+n-1] = 0;
    }
    return;
}


int main () {
    c = 0;
    int mini = 1000, temp;
    for (int i = 0; i < 30; i++)
    {
        col[i]=0; diag1[i]=0; diag2[i]=0;
    }
    rec(0);
    int CASE = 1;
    while(cin >> A[0]){
        for (int i = 1; i < 8; i++)
        {
            cin >> A[i];
        }
        mini =1000; temp =0;
        for (int i = 0; i < 92; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if(Sol[i][j] != A[j]) temp++;
            }
            mini = min(mini, temp);
            temp =0;
        }
        printf("Case %d: %d\n", CASE, mini);
        CASE++;
    }
    
    return EXIT_SUCCESS;
}
