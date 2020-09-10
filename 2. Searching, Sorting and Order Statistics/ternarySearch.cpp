// Created on 13-07-2019 02:10:30 by necronomicon
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
Same as binary search. Has 2 mids at 1/3 and 2/3.
Slower than binary search.
Time Complexity for Binary search = 2clog2n + O(1)
Time Complexity for Ternary search = 4clog3n + O(1)
It is clear that ternary makes more comparisons hence its slower.
 */

int ternary(Vi &v, int target, int l, int r){
    int n = v.size(), mid1 = l+((r-l)/3), mid2 = r-((r-l)/3);
    if(l > r){
        return -1;
    }
    if(mid1 >= 0 && mid1 < n && target == v[mid1]) return mid1;
    else if(mid2 >= 0 && mid2 < n && target == v[mid2]) return mid2;
    else if(target < v[mid1]) return ternary(v, target, l, mid1-1);
    else if(target > v[mid2]) return ternary(v, target, mid2+1, r);
    else return ternary(v, target, mid1+1, mid2-1);
}

int main (int argc, char const *argv[]) {
	Vi v = {1,2,3,4,5,6,7,8,9,10};
    cout << ternary(v, 101, 0, v.size()-1);
    return EXIT_SUCCESS;
}
