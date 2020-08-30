// Created on 25-06-2019 21:53:03 by necronomicon
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

int main () {
	int t;
    cin >> t;
    while (t--){
        int n,m, arr[100000], temp;
        cin >> n >> m;
        USi s;
        for (int i = 0; i < m; i++)
        {
            cin >> temp;
            s.insert(temp);
        }
        Vi v, u;
        bool f = false;
        for (int i = 1; i <= n; i++)
        {
            if(s.count(i) == 0){
                if(f){
                    v.push_back(i);
                    f = !f;
                }
                else{
                    u.push_back(i);
                    f=!f;
                }
            }
        }
        std::for_each(std::begin(u), std::end(u), [](int o) {
          cout << o << ' ';
        }); cout << endl;
        std::for_each(std::begin(v), std::end(v), [](int o) {
          cout << o << ' ';
        }); cout << endl;
        
    }
    return EXIT_SUCCESS;
}
