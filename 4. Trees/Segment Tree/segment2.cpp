// this tree stores the new the value to be incremented in leaves
// in its nodes. Donot build this tree. It only updates.
// Created on 27-04-2019 00:07:49 by necronomicon
#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ARR_MAX (int)1e+5  // limit for array size
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

// Segment Tree without lazy propagation.
class SegmentTree {
  public:
  int n;
  int t[2 * ARR_MAX];
  int h = sizeof(int) * 8 - __builtin_clz(n);
  int d[ARR_MAX];

  int combine(int a, int b) {
    return a + b;
    // return min(a,b);
    // return max(a,b);
  }

  void build() {
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1] , t[i<<1|1]);
  }

  void modify(int l, int r, int value) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) t[l++] += value;
      if (r&1) t[--r] += value;
    }
  }

  int query(int p) {
    int res = 0;
    for (p += n; p > 0; p >>= 1) {cout << t[p] << '\t'; res += t[p];}
    return res;
  }
  void push() {
    for (int i = 1; i < n; ++i) {
      t[i<<1] += t[i];
      t[i<<1|1] += t[i];
      t[i] = 0;
    }
  }
  void showTree(){
      for (size_t i = 0; i < 2*n; i++)
      {
          cout << t[i] << '\t';
      }
      cout << endl;
  }
  SegmentTree(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
    // build();
  }
};

int main() {
  SegmentTree S;
  int n = S.n;
  S.showTree();
  S.modify(0,9,5);
  S.showTree();
  printf("%d\n", S.query(2));
  S.push();
  S.showTree();
  printf("%d\n", S.query(2));
  // printf("%d\n", S.query(1));
  // printf("%d\n", S.query(2));
  // printf("%d\n", S.query(3));
  // printf("%d\n", S.query(4));
  // printf("%d\n", S.query(5));
  // printf("%d\n", S.query(6));
  // printf("%d\n", S.query(7));
  // printf("%d\n", S.query(8));
  return 0;
}