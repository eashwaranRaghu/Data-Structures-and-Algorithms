// Created on 11-05-2019 17:07:40 by necronomicon
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

int n, m, temp, arr[ARR_MAX], maxi;

Vi A,B;

void rec(int k, int sum){
    if(k >= n){
        if(sum > maxi && sum <= m){
            maxi = sum;;
            B.empty();
            B = A;
        }
        return;
    }
    A.push_back(arr[k]);
    rec(k+1, sum+arr[k]);
    A.pop_back();
    rec(k+1, sum);
    return;
}


int main () {
    while(cin >> m >> n){
        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            arr[i] = temp;
        }
        maxi = 0;
        A.empty(); B.empty();
        rec(0, 0);
        std::for_each(std::begin(B), std::end(B), [](int val) {
          cout << val << ' ';
        });
        printf("sum:%d\n", maxi);
    }
    return EXIT_SUCCESS;
}
