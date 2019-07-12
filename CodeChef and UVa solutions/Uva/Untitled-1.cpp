// Created on 21-05-2019 06:30:07 by necronomicon
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


int ans, test, n, arr[20], X, options, c, m, k, temp, diff, A[20];
string ss;

void fun(int k, int s){
    if(k == n || options == 2){
        if(abs(X-s) < diff){
            ans = s;
            diff = abs(X - s);
        }else if(abs(X-s) == diff && s < ans){
            ans = s;
            diff = abs(X - s);
        }
        return;
    }
    options ++;
    fun(k+1, s+arr[k]);
    options --;
    fun(k+1, s);
    return;
}

int main () {
    cin >> c;
    test = 0;
    while(c--){
        test++;
        cin >> X >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> ss >> A[i];
        }
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ss >> arr[i];
        }
        ans = A[0];
        diff = MOD;
        for (int i = 0; i < m; i++)
        {
            options = 0;
            fun(0, A[i]);
        }
        printf("Case #%d: %d\n", test, ans);
    }
    return EXIT_SUCCESS;
}
