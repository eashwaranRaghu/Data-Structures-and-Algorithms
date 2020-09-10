// Created on 12-05-2019 15:52:07 by necronomicon
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
int m,n,x,y;
string s,temp,A[10000];
char B[8] = {'@', 'I', 'E', 'H', 'O', 'V', 'A', '#'};
vector <string> v,u;
void rec(int k){
    if(k == 8){
        u=v;
        return;
    }
    if(A[x-1][y] == B[k] && x >= 0){
        x--;
        v.push_back("forth");
        rec(k+1);
        x++;
        v.pop_back();
    }
    if(A[x][y+1] == B[k] && y+1 <n){
        y++;
        v.push_back("right");
        rec(k+1);
        y--;
        v.pop_back();
    }
    if(A[x][y-1] == B[k] && y-1 >=0){
        y--;
        v.push_back("left");
        rec(k+1);
        y++;
        v.pop_back();
    }
}

int main () {
	int t;
    cin >> t;
    while (t--){
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            cin >> temp;
            A[i] = temp;
        }
        for (int i = 0; i < n; i++)
        {
            if(A[m-1][i] == '@'){
                x = m-1; y=i;
            }
        }
        rec(1);
        for (auto i = u.begin(); i != u.end(); i++)
        {
            if(i != u.begin()) cout << ' ';
            cout << (*i);
        } cout << endl;
        v.clear(); u.clear();
    }
    return EXIT_SUCCESS;
}
