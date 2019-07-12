// Created on 12-05-2019 13:46:26 by necronomicon
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

int n, temp, maxi;
Vi v;

bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
}

void rec(int k){
    maxi = max(k, maxi);
    if(k >= 1000){return;}
    for (size_t i = 0; i < n; i++)
    {
        if(isPerfectSquare(v[i]+k) || v[i] == 0){
            // for (size_t i = 0; i < n; i++)
            // {
            //     cout << v[i] << ' ';
            // }
            // cout << endl;
            temp = v[i];
            v[i] = k;
            rec(k+1);
            v[i] = temp;
        }
    }
    return;
}

void rec2(){
    for (int j = 0; j < 10000; j++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if(isPerfectSquare(v[i]+j) || v[i] == 0){
                maxi = j;
                v[i] = j;
                break;
            }
            if(i == n-1) return;
        }
    }
}
int main () {
	int t;
    cin >> t;
    while (t--){
        cin >> n;
        maxi = 0;
        v.assign(50, 0);
        // rec(1);
        rec2();
        cout << maxi << endl;
    }
    return EXIT_SUCCESS;
}
