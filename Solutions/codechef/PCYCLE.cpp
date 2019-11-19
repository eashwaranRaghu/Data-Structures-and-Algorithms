// Created on 22-06-2019 09:49:18 by necronomicon
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
	int n, arr[100000], arr2[100000], visited[10000], idx, start, flag;
    vector <Vi> V;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr2[arr[i]] = i;
        visited[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        Vi v;
        v.push_back(i);
        start = arr2[i];
        idx = arr[start];
        flag = 0;
        for (int j = 0; j < n; j++)
        {
            if(idx == start){
                v.push_back(arr[idx]);
                flag = 1;
                break;
            }
            v.push_back(arr[idx]);
            idx = arr[idx];
        }
        if(flag == 1){
            V.push_back(v);
            std::for_each(std::begin(v), std::end(v), [&](int x) {
                visited[x] = 1;
            });
        }
    }
    cout << V.size() << endl;
    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V[i].size(); j++)
        {
            cout << V[i][j] << ' ';
        }
        cout << endl;
    }
    
    return EXIT_SUCCESS;
}
