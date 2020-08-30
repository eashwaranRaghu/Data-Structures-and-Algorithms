// 15-07-2020 02:33:19 necronomicon
#include <bits/stdc++.h>
using namespace std;

#define ARR_MAX (int)1e5 //Max array length
#define INF (int)1e9 //10^9
#define MOD 1000000007 //10^9+7
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

// COmplexity: < 8!

bitset<30> rw, ld, rd;
int N;

int nqueen(int col=0) { // n signifies column
    if(col == N) return 1;
    int total = 0;
    // add to total on every iteration
    for(int row =0; row<N; row++) {
        // i signifies row, we try every row of current column n
        if(!rw[row] && !ld[row+col] && !rd[row-col+N-1]) {
            // place
            rw[row] = ld[row+col] = rd[row-col+N-1] = 1;
            total += nqueen(col+1);
            // revert
            rw[row] = ld[row+col] = rd[row-col+N-1] = 0;
        }
    }
    return total;
}

int main () {
    N = 8;
    cout << nqueen();
    return EXIT_SUCCESS;
}
