// Created on 08-09-2019 00:22:11 by necronomicon
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

Vi P; // dimensions
int N; // total matrices
VVi DP;


int bruteForce(int i, int j) {
    if(i == j) return 0;
    
}

int dpBottomUp() {

    for (int i = 0; i < N; i++) DP[i][i] = 0;
    for (int l = 1; l < N; l++)
    {
        for (int i = 0; i < N; i++)
        {
            int j = i+l-1;
            Vi v;
            for (int k = i; k < j-1; k++)
            {
                v.push_back(dpBottomUp(i, k)+dpBottomUp(k+1, j) + (P[i-1]*P[k])*P[j]);
            }
            DP[i][j] = *min_element(v.begin(), v.end());
        }
        
    }
    

    return 1;
}

int main (int argc, char const *argv[]) {
	
    P = {1,2,3,1,2,1};
    N = P.size()-1;



    return EXIT_SUCCESS;
}
