// Created on 06-07-2019 18:33:24 by necronomicon
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

void merge(Vi &v, int l, int mid, int r) {
    Vi u;
    int i=l, j=mid;
    while(i<mid && j<=r) {
        if(v[i] == v[j]) {
            u.push_back(v[i]);
            u.push_back(v[j]);
            i++;
            j++;
        }
        else if(v[i] < v[j]) {
            u.push_back(v[i]);
            i++;
        }
        else {
            u.push_back(v[j]);
            j++;
        }
    }
    while(i<mid) {
        u.push_back(v[i]);
            i++;
    }
    while(j <= r) {
        u.push_back(v[j]);
        j++;
    }
    for (int idx = l, idy=0; idx <= r; idx++, idy++) {
        v[idx] = u[idy];
    }
}

void merge(Vi &v, int l, int r){
    if(l == r) return;
    int mid = (l+r)/2;
    merge(v, l, mid);
    merge(v, mid+1, r);
    // inplace_merge(v.begin()+l, v.begin()+mid+1, v.begin()+r+1);
    merge(v, l, mid+1, r);
}

int main () {
	Vi v;
    v.push_back(3);
    v.push_back(-1);
    v.push_back(3);
    v.push_back(0);
    v.push_back(3);
    v.push_back(-1);
    v.push_back(3);
    v.push_back(0);
    merge(v, 0, v.size()-1);
    std::for_each(std::begin(v), std::end(v), [](int a) {cout << a << ' ';});cout << endl;
    return EXIT_SUCCESS;
}
