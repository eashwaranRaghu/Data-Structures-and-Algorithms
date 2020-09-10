// Created on 25-04-2019 23:57:12 by necronomicon
#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define INF (int)1e9 //10^9
#define EPS 1e-9 //10^-9
#define MOD 1000000007 //10^9+7
#define PI 3.1415926535897932384626433832795

typedef long long int int64;

typedef vector<int64> Vi;



class SegmentTree {
private:
    Vi ST, LAZY, A;
    int64 height, nodes, leaves;

    int64 leftChild(int64 pos){return pos<<1;}

    int64 rightChild(int64 pos){return (pos<<1)+1;}

    int64 combine(int64 a, int64 b){
        return a+b;
        // return min(a,b);
        // return max(a,b);
    }

    void UpdateLazy(int64 pos, int64 i, int64 j, int64 L, int64 R){
        if(LAZY[pos] != 0){push(pos, L, R);}
        if(i>R || j<L){return;}
        if(i <= L && j >= R){
            ST[pos] = (R-L+1) - ST[pos]; // lazy combine
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
        ST[pos] = (R-L+1) - ST[pos];
        if(L != R){
            LAZY[leftChild(pos)] =  1 -(LAZY[leftChild(pos)]);
            LAZY[rightChild(pos)] = 1 -(LAZY[rightChild(pos)]);
        }
        LAZY[pos] = 0;
    }

public:

    SegmentTree(int64 N){
        leaves = N;
        height = ceil(log2(leaves)) + 1;
        ST.assign(4 * leaves, 0);
        LAZY.assign(4 * leaves, 0);
    }

    void UpdateTree(int64 i, int64 j){
        UpdateLazy(1, i, j, 0, leaves-1);
    }

    void QueryTree(int64 i, int64 j){
        cout << Query(1, i, j, 0, leaves-1) << endl;
    }

};

int main () {
  int64 temp, N, Q;
  cin >> N >> Q;
  int64 typ, A, B;
  SegmentTree s(N);
  for (size_t i = 0; i < Q; i++)
  {
    cin >> typ >> A >> B;
    if(typ == 0){ // flip
      s.UpdateTree(A, B);
    }
    else{ // query
      s.QueryTree(A, B);
    }
  }
  return EXIT_SUCCESS;
} 