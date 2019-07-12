// Created on 05-05-2019 07:01:30 by necronomicon
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
#include <iomanip>
#include <ctime>
// #include <cmath>
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


int arr1[100000];
int arr2[100000];

int main () {
	int64 t, n, y, x;
    cin >> t;
    while (t--){
        cin >> n;
        for (int64 i = 0; i < n; i++)
        {
            cin >> x >> y;
            arr1[i] = y-x;
            arr2[i] = y+x;
        }
        int64 mind = MOD, d;
        sort(arr1, arr1+n);
        sort(arr2, arr2+n);
        for (int64 i = 0; i < n-1; i++)
        {
            d = abs(arr1[i] - arr1[i+1]);
            if(mind > d) mind = d;
            d = abs(arr2[i] - arr2[i+1]);
            if(mind > d) mind = d;
        }
        cout << fixed << setprecision(6);
        cout << (double)mind/2 << endl;
        
    }
    return EXIT_SUCCESS;
}
