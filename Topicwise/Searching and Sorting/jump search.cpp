// Created on 12-07-2019 21:44:15 by necronomicon
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

/* 
Jump Search is a searching algorithm for sorted arrays.
The basic idea is to check fewer elements (than linear search)
by jumping ahead by fixed steps or skipping some elements in place of searching all elements.
    Time Complexity : O(√n)
    Auxiliary Space : O(1)

Works only sorted arrays.
The optimal size of a block to be jumped is (√ n). This makes the time complexity of Jump Search O(√ n).
The time complexity of Jump Search is between Linear Search ( ( O(n) ) and Binary Search ( O (Log n) ).
Binary Search is better than Jump Search, but Jump search has an advantage that we traverse back only
 once (Binary Search may require up to O(Log n) jumps, consider a situation where the element to be
  search is the smallest element or smaller than the smallest). So in a systems where jumping back is
   costly, we use Jump Search.
 */

int jump(Vi &v, int target, int blockSize){
    int i;
    for(i=0; i<v.size(); i+=blockSize){
        if(v[i] == target) return i;
        if(v[i] > target) break;
    }
    for (int j = i-blockSize; j < i; j++)
    {
        if(j < 0) j = 0;
        if(v[j] == target) return j;
    }
    return -1;
}

int main () {
	Vi v = {1,2,3,4,5,6,7,8,9,10};
    int blockSize = 2; // best block size is √n;
    int target = 1;
    cout << jump(v, target, blockSize);
    return EXIT_SUCCESS;
}
