// Created on 10-05-2019 06:54:21 by necronomicon
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

Vi col(10), diag1(10), diag2(10);
int c, n;
void rec(int j){
    if(n == j){
        c++;
    }
    else{
        for (int i = 0; i < n; i++)
        {
            if(col[i] || diag1[i+j] || diag2[i-j+n-1]) continue;

            col[i] =diag1[i+j] = diag2[i-j+n-1] = 1;
            rec(j+1);
            col[i] =diag1[i+j] = diag2[i-j+n-1] = 0;
            rec(j+1);
        }
    }
}

int arr[10][10];

bool rec2(int x, int y, int c){
    if(x>=8 || y>=8){
        if(c == 8){
            return true;
        }
        else{
            return false;
        }
    }
    else {
        
    }
}

int main () {
    c =0;
    n = 4;
    col.reserve(n);
    diag1.reserve(2*n);
    diag2.reserve(2*n);
    rec(0);
    cout << c;
    return EXIT_SUCCESS;
}
