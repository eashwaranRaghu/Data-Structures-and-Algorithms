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

int sD(int n) 
{
    if(n < 2) return 1;
    // if divisible by 2 
    if (n % 2 == 0) 
        return 2; 
  
    // iterate from 3 to sqrt(n) 
    for (int i = 3; i * i <= n; i += 2) { 
        if (n % i == 0) 
            return i; 
    }
    return n; 
}

class SegmentTree {
private:
    Vi ST, LAZY, A;
    int height, nodes, leaves;
    int leftChild(int pos){return pos<<1;}
    int rightChild(int pos){return (pos<<1)+1;}
    void buildTree(int pos, int L, int R){
        if(L == R){
            ST[pos] = L;
            LAZY[pos] = A[L];
        }
        else{
            int MID = (L+R)/2;
            buildTree(leftChild(pos), L, MID);
            buildTree(rightChild(pos), MID+1, R);
            int p1 = ST[leftChild(pos)], p2 = ST[rightChild(pos)];
            ST[pos] = (sD(A[p1]) >= sD(A[p2])) ? p1 : p2;
            LAZY[pos] = A[p1] | A[p2];
        }
    }
    void Update(int pos){
        int p = pos;
        if(A[p] == 0 || A[p] == 1){return;}
        pos = (1<<height-1) + pos;
            LAZY[pos] = A[p];
            A[p] = A[p]/sD(A[p]);
            pos/=2;
            while(pos > 0){
                int p1 = ST[leftChild(pos)], p2 = ST[rightChild(pos)];
                ST[pos] = (sD(A[p1]) >= sD(A[p2])) ? p1 : p2;
                LAZY[pos] = A[p1] | A[p2];
                pos/=2;
            }
    }
    int Query(int pos, int i, int j, int L, int R){
        if(i>R || j<L){return -1;}
        if(A[ST[pos]] == 1 || A[ST[pos]] == 0){return 1;}
        if(i <= L && j >= R){return ST[pos];}
        int MID = (L+R)/2;
        int r1, r2;
        r1 = Query(leftChild(pos), i, j, L, MID);
        r2 = Query(rightChild(pos), i, j, MID+1, R);
        if(r1 == -1){return r2;}
        if(r2 == -1){return r1;}
        return (sD(A[r1]) >= sD(A[r2])) ? r1 : r2;
    }
public:
    SegmentTree(Vi &B){
        A = B; leaves = (int)A.size();
        height = ceil(log2(leaves)) + 1;
        ST.assign(4 * leaves, 0);
        LAZY.assign(4 * leaves, 0);
        buildTree(1, 0, leaves - 1);
    }
    void UpdateTree(int pos){
        Update(pos);
    }
    void QueryTree(int i, int j){
        cout << A[Query(1, i, j, 0, leaves-1)] << ' ';
    }
    void ShowTree(){
        for_each(std::begin(ST), std::end(ST), [](int i) {
            cout << i <<  '\t';
        });
        cout << endl;
    }
    void ShowVector(){
        for_each(std::begin(A), std::end(A), [](int i) {
            cout << i <<  '\t';
        });
        cout << endl;
    }
};
int main () {
	int t, n, m, temp;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> A(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            A[i] = temp;
        }
        SegmentTree S(A);
        // S.ShowTree();
        int typ, l,r;
        for (size_t i = 0; i < m; i++)
        {
            cin >> typ >> l >> r;
            l--; r--;
            if(typ == 0){ // update
                for (size_t j = l; j <= r; j++)
                {
                    S.UpdateTree(j);
                    // S.ShowVector();
                }
                // S.ShowTree();
            } else { //get
                S.QueryTree(l,r);
                // cout << endl;
            }
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}