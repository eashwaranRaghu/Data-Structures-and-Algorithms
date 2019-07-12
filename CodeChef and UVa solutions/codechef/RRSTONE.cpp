// Created on 22-06-2019 17:33:43 by necronomicon
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
#include <climits>
#include <cstdint>
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
	int64 n, k, arr[100000], mx=INT_MIN;
    cin >> n >> k;
    for (int64 i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if(k != 0){
        k = (k%2 == 1)? 1:2;
        for (int64 i = 1; i <= k; i++)
        {
            mx = arr[0];
            for (int64 j = 0; j < n; j++)
            {
                mx = max(mx, arr[j]);
            }
            for (int64 j = 0; j < n; j++)
            {
                arr[j] = mx - arr[j];
            }
        }
    }
    for (int64 i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    
    return EXIT_SUCCESS;
}
