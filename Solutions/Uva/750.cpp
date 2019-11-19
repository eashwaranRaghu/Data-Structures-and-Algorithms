// Created on 12-05-2019 06:52:14 by necronomicon
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
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

int col[30], row[30], diag1[30], diag2[30], n = 8;
int t, xx, yy, temp, c;

void rec(int y){
    if(y == n){
        c++;
        if(c < 10) cout << ' ';
        cout << c << "      ";
        for (size_t i = 0; i < n; i++)
        {
            row[col[i]-1] = i+1;
        }
        for (size_t i = 0; i < n; i++)
        {
            if(i) cout << ' ';
            cout << row[i];
        }
        cout << endl;
        return;
    }
    for (int i=0; i<n; i++)
    {
        if(col[i] || diag1[y+i] || diag2[i-y+n-1]) continue;
        if(i == yy-1 && y+1 != xx) continue;
        col[i] = y+1;
        diag1[i+y] = diag2[i-y+n-1] = 1;
        rec(y+1);
        col[i] = 0;
        col[i] = diag1[i+y] = diag2[i-y+n-1] = 0;
    }
    return;
}


int main () {
    cin >> t;
    while (t--){
        c = 0;
        for (size_t i = 0; i < 30; i++)
        {
            col[i]=0; diag1[i]=0; diag2[i]=0;
        }
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8"<<endl<<endl;
        cin >> yy >> xx;
        rec(0);
        if(t) cout << endl;
    }
    return EXIT_SUCCESS;
}
