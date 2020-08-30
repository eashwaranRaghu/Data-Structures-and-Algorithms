// Created on 25-04-2019 23:57:12 by necronomicon
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


class SegmentTree {
private:
    Vi ST, LAZY, A;
    int height, nodes, leaves;

    int leftChild(int pos){return pos<<1;}

    int rightChild(int pos){return (pos<<1)+1;}

    int combine(int a, int b){
        // return a+b;
        // return min(a,b);
        return max(a,b);
    }

    int combineLazy(int a, int b, int c){
        return a+b; // for min or max
        return a+(b*c); // for sum
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

    void UpdateLazy(int pos, int i, int j, int L, int R, int value){
        if(i>R || j<L){return;}
        if(LAZY[pos] != 0){push(pos, L, R);}
        if(i <= L && j >= R){
            ST[pos] = combineLazy(ST[pos], value, (R-L+1)); // lazy comvine
            if(L != R){
                LAZY[leftChild(pos)] = value;
                LAZY[rightChild(pos)] = value;  
            }
            return;
        }
        int MID = (L+R)/2;
        UpdateLazy(leftChild(pos), i, j, L, MID, value);
        UpdateLazy(rightChild(pos), i, j, MID+1, R, value);
        ST[pos] = combine(ST[leftChild(pos)], ST[rightChild(pos)]);
    }

    int Query(int pos, int i, int j, int L, int R){
        if(i>R || j<L){return -1;}
        if(LAZY[pos] != 0){push(pos, L, R);}
        if(i <= L && j >= R){return ST[pos];}
        int MID = (L+R)/2;
        int r1, r2;
        r1 = Query(leftChild(pos), i, j, L, MID);
        r2 = Query(rightChild(pos), i, j, MID+1, R);
        if(r1 == -1 && r2 == -1){return 0;}
        if(r1 == -1){return r2;}
        if(r2 == -1){return r1;}
        return combine(r1, r2);
    }

    void push(int pos, int L, int R){
        int val = LAZY[pos];
        LAZY[pos] = 0;
        ST[pos] = combineLazy(ST[pos], (val), (R-L+1)); // lazy combine
        if(L != R){
            LAZY[leftChild(pos)] += val;
            LAZY[rightChild(pos)] += val;
        }
    }

public:

    SegmentTree(Vi &B){
        A = B; leaves = (int)A.size();
        height = ceil(log2(leaves)) + 1;
        ST.assign(4 * leaves, 0);
        LAZY.assign(4 * leaves, 0);
        buildTree(1, 0, leaves - 1);
    }

    void UpdateTree(int i, int j, int value){
        UpdateLazy(1, i, j, 0, leaves-1, value);
    }

    void QueryTree(int i, int j){
        cout << Query(1, i, j, 0, leaves-1) << endl;
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

    void ShowVector(){
        for_each(std::begin(A), std::end(A), [](int i) {
            cout << i <<  '\t';
        });
    }

};

int main () {
	Vi A;
    int temp;
    // A = {11,4,11,11,11,4,11,11,11,5,11,11};
    // A = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    A = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree s(A);
    s.ShowTree(0, A.size()-1); cout << endl;
    s.UpdateTree(0, 7, 1);
    s.ShowTree(0, A.size()-1); cout << endl;
    s.UpdateTree(1, 2, 10);
    s.ShowTree(0, A.size()-1); cout << endl;
    
    return EXIT_SUCCESS;
}