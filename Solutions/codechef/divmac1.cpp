
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

typedef long long int int64;

typedef vector<int64> Vi;
// Function to find the smallest divisor 
int64 Ll(int64 n) 
{ 
    // if divisible by 2 
    if (n % 2 == 0) 
        return 2; 
  
    // iterate from 3 to sqrt(n) 
    for (int64 i = 3; i * i <= n; i += 2) { 
        if (n % i == 0) 
            return i; 
    } 
  
    return 1; 
}


class SegmentTree {
private:
    Vi ST, LAZY, A;
    int64 height, nodes, leaves;

    int64 leftChild(int64 pos){return pos<<1;}

    int64 rightChild(int64 pos){return (pos<<1)+1;}

    int64 combine(int64 a, int64 b){
       // return a+b;
        // return min(a,b);
         return max(a,b);
    }

    void UpdateLazy(int64 pos, int64 i, int64 j, int64 L, int64 R){
        if(LAZY[pos] != 0){push(pos, L, R);}
        if(i>R || j<L){return;}
        if(i <= L && j >= R){
            ST[pos] = ST[pos]/Ll(ST[pos]); // lazy combine
            if(L != R){
                LAZY[leftChild(pos)] =  1 -(LAZY[leftChild(pos)]);
                LAZY[rightChild(pos)] = 1 -(LAZY[rightChild(pos)]);
            }
            return;
        }
        int64 MID = (L+R)/2;
        UpdateLazy(leftChild(pos), i, j, L, MID);
        UpdateLazy(rightChild(pos), i, j, MID+1, R);
        ST[pos] = combine(ST[leftChild(pos)], ST[rightChild(pos)]);
    }

    int64 Query(int64 pos, int64 i, int64 j, int64 L, int64 R){
        if(LAZY[pos] != 0){push(pos, L, R);}
        if(i>R || j<L || R<L){return 0;}
        if(i <= L && j >= R){return ST[pos];}
        int64 MID = (L+R)/2;
        int64 r1, r2;
        r1 = Query(leftChild(pos), i, j, L, MID);
        r2 = Query(rightChild(pos), i, j, MID+1, R);
        return combine(r1, r2);
    }

    void push(int64 pos, int64 L, int64 R){
        ST[pos] = ST[pos]/Ll(ST[pos]);
//         ST[pos] = (R-L+1) - ST[pos];
        if(L != R){
            LAZY[leftChild(pos)] =  1 -(LAZY[leftChild(pos)]);
            LAZY[rightChild(pos)] = 1 -(LAZY[rightChild(pos)]);
        }
        LAZY[pos] = 0;
    }

public:
    SegmentTree(Vi &B){
        A = B; leaves = (int)A.size();
        height = ceil(log2(leaves)) + 1;
        ST.assign(4 * leaves, 0);
        LAZY.assign(4 * leaves, 0);
        buildTree(1, 0, leaves - 1);
    }

    void UpdateTree(int64 i, int64 j){
        UpdateLazy(1, i, j, 0, leaves-1);
    }

    void QueryTree(int64 i, int64 j){
        cout << Query(1, i, j, 0, leaves-1) << " ";
    }
    void buildTree(int pos, int L, int R){
        if(L == R){
            ST[pos] = A[L];
        }
        else{
            int MID = (L+R)/2;
            buildTree(leftChild(pos), L, MID);
            buildTree(rightChild(pos), MID+1, R);
            int r1 = ST[leftChild(pos)];
            int r2 = ST[rightChild(pos)];
            ST[pos] = max(Ll(r1),Ll(r2));
        }
    }
        void QueryTree2(int i, int j){
        cout << Query(1, i, j, 0, leaves-1) << " ";
    }

    void ShowTree(int L, int R){
        QueryTree2(L, R);
        if(L == R){return;}
        int MID = (L+R)/2;
        ShowTree(L, MID);
        ShowTree(MID+1, R);
    }
};

int main () {
    int t;
    cin>>t;
    while(t--){
        Vi A;
  int64 temp, N, Q;
  cin >> N >> Q;
  for(int i=0;i<N;i++){
      int temp;cin>>temp;
      A.push_back(temp);
  }
  int64 typ, Ai, Bi;
  SegmentTree s(A);
  for (size_t i = 0; i < Q; i++)
  {
   //   s.ShowTree(0,N-1);
    //  cout<<endl;
    cin >> typ >> Ai >> Bi;
    if(typ == 0){ // st = st/ll(st)
      s.UpdateTree(Ai-1, Bi-1);
    }
    else{ // query
      s.QueryTree(Ai-1, Bi-1);
    }
  }
  cout<<endl;
    }
  return EXIT_SUCCESS;
} 