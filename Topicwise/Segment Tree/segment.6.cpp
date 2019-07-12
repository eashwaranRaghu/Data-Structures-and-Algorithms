// This is set up for range minimum queries, but can be easily adapted for computing other quantities.
// To enable lazy propagation and range updates, uncomment the following line.
 #define LAZY

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;

#define MP make_pair
#define PB push_back
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
int min2(int a , int b){
  return a+b;
}
struct Segtree {
  int n;
  vector<int> data;
  #ifdef LAZY
  #define NOLAZY 0
  #define GET(node) (lazy[node] == NOLAZY ? data[node] : lazy[node])
  vector<int> lazy;
  #else
  #define GET(node) data[node]
  #endif
  void build_rec(int node, int* begin, int* end) {
    if (end == begin+1) {
      if (data.size() <= node) data.resize(node+1);
      data[node] = *begin;
    } else {
      int* mid = begin + (end-begin+1)/2;
      build_rec(2*node+1, begin, mid);
      build_rec(2*node+2, mid, end);
      data[node] = min2(data[2*node+1], data[2*node+2]);
    }
  }
  #ifndef LAZY
  void update_rec(int node, int begin, int end, int pos, int val) {
    if (end == begin+1) {
      data[node] = val;
    } else {
      int mid = begin + (end-begin+1)/2;
      if (pos < mid) {
        update_rec(2*node+1, begin, mid, pos, val);
      } else {
        update_rec(2*node+2, mid, end, pos, val);
      }
      data[node] = min2(data[2*node+1], data[2*node+2]);
    }
  }
  #else
  void update_range_rec(int node, int tbegin, int tend, int abegin, int aend, int val) {
    if (tbegin >= abegin && tend <= aend) {
      lazy[node] = val;
    } else {
      int mid = tbegin + (tend - tbegin + 1)/2;
      if (lazy[node] != NOLAZY) {
        lazy[2*node+1] = lazy[2*node+2] = lazy[node]; lazy[node] = NOLAZY;
      }
      if (mid > abegin && tbegin < aend)
      update_range_rec(2*node+1, tbegin, mid, abegin, aend, val);
      if (tend > abegin && mid < aend)
      update_range_rec(2*node+2, mid, tend, abegin, aend, val);
      data[node] = min2(GET(2*node+1), GET(2*node+2));
    }
  }
  #endif
  int query_rec(int node, int tbegin, int tend, int abegin, int aend) {
    if (tbegin >= abegin && tend <= aend) {
      return GET(node);
    } else {
      #ifdef LAZY
      if (lazy[node] != NOLAZY) {
        data[node] = lazy[2*node+1] = lazy[2*node+2] = lazy[node]; lazy[node] = NOLAZY;
      }
      #endif
      int mid = tbegin + (tend - tbegin + 1)/2;
      int res = 0; //INT_MAX
      if (mid > abegin && tbegin < aend)
      res = min2(res, query_rec(2*node+1, tbegin, mid, abegin, aend));
      if (tend > abegin && mid < aend)
      res = min2(res, query_rec(2*node+2, mid, tend, abegin, aend));
      return res;
    }
  }

  // Create a segtree which stores the range [begin, end) in its bottommost level.
  Segtree(int* begin, int* end): n(end - begin) {
    build_rec(0, begin, end);
    #ifdef LAZY
    lazy.assign(data.size(), NOLAZY);
    #endif
  }
  #ifndef LAZY
  // Call this to update a value (indices are 0-based). If lazy propagation is enabled, use update_range(pos, pos+1, val) instaed.
  void update(int pos, int val) {
    update_rec(0, 0, n, pos, val);
  }
  #else
  // Call this to update range [begin, end), if lazy propagation is enabled. Indices are 0-based.
  void update_range(int begin, int end, int val) {
    update_range_rec(0, 0, n, begin, end, val);
  }
  #endif
  // Returns minimum in range [begin, end). Indices are 0-based.
  int query(int begin, int end) {
    return query_rec(0, 0, n, begin, end);
  }
};

int main() {
  int a,b,c,d,e,n, arr[100000] = {0};
  vector<int> data;
  //scanf("%d", &n);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  cin>>b;
  //n = 8;
  //for (int i = 0; i < n; ++i) data.push_back(i);
  //for (int i = 0; i < n; ++i) arr[i]=i;
  //for (int i = 0; i < n; ++i) cout<<arr[i]<<" ";
  //cout<<endl;
//  build(0,n);
  //s.Segtree(data.begin(), data.end());
  Segtree s(arr, arr + n);
  for(int i=0;i<b;i++){
    cin>>c>>d>>e;
    //cout<<"Query: "<<c<<d<<e<<endl;
    if(c==0){
      s.update_range(d,e+1,1);
    }
    else if(c == 1){
    //  for (int i = 0; i < 2*n-1; ++i)
    //  cout<<s.query(0, 1)<< " ";
     //cout<<endl;
      cout<<s.query(d, e+1)<<endl;
    }
  }

  //  modify(0, 1);

  //  for(int i=0;i<2*n;i++)cout<<t[i]<<" ";
  //cout<<endl;
  //  printf("%d\n", query(0, 4));
  return 0;
}