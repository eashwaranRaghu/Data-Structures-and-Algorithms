// Created on 28-04-2019 06:35:58 by necronomicon
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <map>
#include <functional>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cmath>
#include <cstring>
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

class SegmentTree {
private:
    Vi ST, LAZY, A;
    int height, nodes, leaves;
    
    int leftChild(int pos){return pos<<1;}
    
    int rightChild(int pos){return (pos<<1)+1;}
    
    int combine(int a, int b){
        return a+b;
        return max(a,b);
        return min(a,b);
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
            ST[pos] = combine(r1, r2);
        }
    }

    void Update(int pos, int value){
        pos = (1<<height-1) + pos;
        ST[pos]  = value;
        pos/=2;
        while(pos > 0){
            ST[pos] = combine(ST[leftChild(pos)] , ST[rightChild(pos)]);
            pos/=2;
        }
    }

    int Query(int pos, int i, int j, int L, int R){
        if(i>R || j<L){return -1;}
        if(i <= L && j >= R){return ST[pos];}
        int MID = (L+R)/2;
        int r1, r2;
        r1 = Query(leftChild(pos), i, j, L, MID);
        r2 = Query(rightChild(pos), i, j, MID+1, R);
        if(r1 == -1){return r2;}
        if(r2 == -1){return r1;}
        return combine(r1, r2);
    }

public:
    SegmentTree(){
        iota(std::begin(A), std::begin(A) + 10, 10);
        leaves = (int)A.size();
        height = ceil(log2(leaves)) + 1;
        ST.assign(4 * leaves, 0);
        buildTree(1, 0, leaves - 1);
    }

    void UpdateTree(int pos, int value){
        Update(pos, value);
    }

    void QueryTree(int i, int j){
        cout << Query(1, i, j, 0, leaves-1) << endl;
    }

    void ShowTree(){
        for_each(std::begin(ST), std::end(ST), [](int i) {
            cout << i <<  '\t';
        });
    }
    
};

int main () {
	SegmentTree();
    return EXIT_SUCCESS;
}
