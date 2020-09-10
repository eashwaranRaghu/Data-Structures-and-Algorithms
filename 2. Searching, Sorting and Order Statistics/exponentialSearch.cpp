// Created on 13-07-2019 01:22:43 by necronomicon
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

/* 
1. Find range where element is present
2. Do Binary Search in above found range.

Time Complexity : O(Log n)
Auxiliary Space : The above implementation of Binary Search is recursive
and requires O(Log n) space.
With iterative Binary Search, we need only O(1) space.
 */
int binary(Vi &v, int target, int l, int r){
    int mid = (l+r)/2;
    if(v[mid] == target) return mid;
    if( l == r) return -1;
    else if(v[mid] < target) return binary(v, target, mid+1, r);
    else return binary(v, target, l, mid-1);
}
int exponential(Vi &v, int target, int l, int r){
    int i = 1, n=v.size();
    if(target < v[0] || target > v[n-1]) return -1;
    while(i<n && target >= v[i]){
        i<<=1;
    }
    if(i >= n) i = n-1;
    return binary(v, target, i/2, i);
}
int main (int argc, char const *argv[]) {
	Vi v = {1,2,3,4,5,6,7,8,9,10};
    cout << exponential(v, -4, 0, v.size()-1);
    return EXIT_SUCCESS;
}
