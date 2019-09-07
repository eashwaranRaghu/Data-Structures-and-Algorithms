// Created on 30-07-2019 14:58:27 by necronomicon
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

/* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive. */

int N;
Vi arr;
VVi DP;

void dpTopDown(){
    for (int i = 0; i < N; i++) DP.push_back(Vi(N, 0));
    for (int i = 0; i < N; i++)
    {
        DP[i][i] = arr[i];
        for (int j = i+1; j < N; j++)
        {
            DP[i][j] = DP[i][j-1] + arr[j];
        }
    }
}

int dpTopDown(int l, int r){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << DP[i][j] << ' ';
        }
        cout << endl;
    }
    return DP[l][r];
}

int main (int argc, char const *argv[]) {
	N = 6;
    arr = {-2, 0, 3, -5, 2, -1};
    DP.clear();
    dpTopDown();
    cout << dpTopDown(0,2) << endl;
    cout << dpTopDown(2,5) << endl;
    cout << dpTopDown(0,5) << endl;
    return EXIT_SUCCESS;
}
