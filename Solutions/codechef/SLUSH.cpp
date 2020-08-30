// Created on 23-06-2019 22:02:46 by necronomicon
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

int main () {
	int t;
    cin >> t;
    while (t--){
        int n, m, M[100000], ans[100000], d, f, b;
        pair <int, int> p;
        cin >> n >> m;
        vector <int> u(4);
        vector <Vi> v;
        for (int i = 1; i <= m; i++)
        {
            cin >> M[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> u[0] >> u[1] >> u[2];
            u[3] = i;
            v.push_back(u);
        }
        std::sort(std::begin(v), std::end(v), [] (Vi a, Vi b) {
            if(a[1] == b[1]) return a[2] < b[2];
            return a[1] > b[1];
        });
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < 4; j++)
        //     {
        //         cout << v[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        int profit = 0;
        for (int i = 0; i < n; i++)
        {
            if(M[v[i][0]] > 0){
                M[v[i][0]]--;
                ans[v[i][3]] = v[i][0];
                profit += v[i][1];
                cout << v[i][1] << ' ';
            }
        }
        int idx=0;
        for (int i = 0; i < n; i++)
        {
            while(M[idx] == 0) idx++;
            M[idx]--;
            ans[i] = idx;
            profit += v[i][2];
        }
        cout << profit << endl;
    }
    return EXIT_SUCCESS;
}
