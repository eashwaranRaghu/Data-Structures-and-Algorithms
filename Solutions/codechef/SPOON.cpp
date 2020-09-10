// Created on 24-06-2019 17:25:29 by necronomicon
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

int r, c;
string temp, v[100000];

bool f(int i, int j){
    if(i+4 < r && ((v[i+1][j] == 'P' || v[i+1][j] == 'p') && (v[i+2][j] == 'O' || v[i+2][j] == 'o') && (v[i+3][j] == 'O' || v[i+3][j] == 'o') && (v[i+4][j] == 'N' || v[i+4][j] == 'n'))){
        return true;
    }
    if(j+4 < c && ((v[i][j+1] == 'P' || v[i][j+1] == 'p') && (v[i][j+2] == 'O' || v[i][j+2] == 'o') && (v[i][j+3] == 'O' || v[i][j+3] == 'o') && (v[i][j+4] == 'N' || v[i][j+4] == 'n'))){
        return true;
    }
    return false;
}

int main () {
	int t;
    cin >> t;
    while (t--){
        cin >> r >> c;
        for (int i = 0; i < r; i++)
        {
            cin >> temp;
            v[i] = temp;
        }
        bool x = false;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if(v[i][j] == 'S' || v[i][j] == 's'){
                    // cout << i << j << ' ';
                    x = x || f(i, j);
                }
            }
        }
        cout << (x ? "There is a spoon!" : "There is indeed no spoon!") << endl;
    }
    return EXIT_SUCCESS;
}
