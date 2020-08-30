// Created on 21-07-2019 17:09:13 by necronomicon
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

Vi V, FT;
int N;

int rangeSum(int l, int r){
    return prefixSum(r) - prefixSum(l-1);
}
int prefixSum(int i){
    int sum =0;
    while(i>0){
        sum += FT[i];
        i -= LSB(i);
    }
    return sum;
}
int LSB(int n){
    return n - (n & n - 1); // rightmost set bit
}
void preProcess(){
    N = V.size();
    FT = Vi(N, 0);
}
void update(int idx, int val){
    int diff = val - V[idx];
    V[idx] += diff;
    while(idx < N){
        FT[idx] += diff;
        idx += LSB(idx);
    }
}
int main (int argc, char const *argv[]) {
	
    return EXIT_SUCCESS;
}
