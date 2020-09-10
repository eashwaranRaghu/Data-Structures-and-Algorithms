// Created on 06-07-2019 18:33:24 by necronomicon
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

// reusing the quick sort code and making modifications to follow one path when array is partitioned
int partition(int l, int r, Vi &v) {
  int pivot = r;
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

int quick(int l, int r, int k, Vi &v) { // the kth order is passed in
  if(l==r) return v[l]; // when only 1 element is obtained it is the kth order number.
  int p = partition(l, r, v); // obtain from Lomuto partition
  if(k==p) return v[p]; // when the pivot index equals k, return element
  if(p > k) return quick(l, p-1, k, v); // pivot index greater than k, look on the left partition
  else return quick(p+1, r, k, v); // otherwise look on the right partition
}


int main () {
	
    Vi v = {3,1,4,2};
    int k = 1; // kth order

    int ans = quick(0, v.size()-1, k, v);
    cout << ans << endl;
    
    return EXIT_SUCCESS;
}
