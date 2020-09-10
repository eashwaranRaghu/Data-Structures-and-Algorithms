// Created on 12-07-2019 21:44:15 by necronomicon
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
The Interpolation Search is an improvement over Binary Search for instances,
where the values in a sorted array are uniformly distributed.
Binary Search always goes to the middle element to check. On the other hand,
interpolation search may go to different locations according to the value of
the key being searched. For example, if the value of the key is closer to the
last element, interpolation search is likely to start search toward the end side.

pos = low + [ (target-arr[low])*(high-low) / (arr[high]-arr[Low]) ]
when arr[high] == target :: pos = high

    Time Complexity: If elements are uniformly distributed, then O (log log n)). 
                     In worst case it can take upto O(n).
    Auxiliary Space: O(1)
 */
// takes low and high index and decides a pos on each iteration.
int interpolation(Vi &v, int target, int l, int h){
    int pos = l + ((h-l) * (target - v[l]) / (v[h] - v[l]));
    if(pos < 0 || pos >= v.size()) return -1;
    if( l == h){
        if(v[l] == target) return l;
        else return -1;
    }
    if(v[pos] == target) return pos;
    else if(v[pos] < target) return interpolation(v, target, pos+1, h);
    else return interpolation(v, target, l, pos-1); 
}

int main () {
	Vi v = {1,2,3,4,5,6,7,8,9,10};
    int target = 1;
    cout << interpolation(v, target, 0, v.size()-1);
    return EXIT_SUCCESS;
}