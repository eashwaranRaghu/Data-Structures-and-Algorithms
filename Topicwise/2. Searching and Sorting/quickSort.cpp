// Created on 06-07-2019 18:33:24 by necronomicon
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

Vi v;


/* 
  Partition Principle:
    All elements [l,i-1] are strictly less than pivot
    All elements [i,r] are greater than equal to pivot
  can be divided into 3 parts.
  1) Keep i=l
  2) start loop using j and (if A[j]<pivot swap A[j] with A[i] and advance i)
  3) At the end of loop swap A[i] with pivot cuz A[i] is the real pivot now.
 */

int partition(int l, int r) { // Lomuto partition
  int pivot = r; // last element is picked as pivot
  int i = l;
  for (int j = l+1; j+1 <= r; j++)
  {
    if(v[j] < v[pivot]) {
      swap(v[j], v[i]);
      i++;
    }
  }
  swap(v[i], v[r]);
  return i;
}

void quick(int l, int r) { // calls partition and then split the array into two.
  if(l>=r) return;
  int p = partition(l, r);
  quick(l, p-1);
  quick(p+1, r);
}


int main () {
	
    v = {3,1,4,2};

    std::for_each(std::begin(v), std::end(v), [](int a) {cout << a << ' ';});cout << endl;

    quick(0, v.size()-1);

    std::for_each(std::begin(v), std::end(v), [](int a) {cout << a << ' ';});cout << endl;
    
    return EXIT_SUCCESS;
}
