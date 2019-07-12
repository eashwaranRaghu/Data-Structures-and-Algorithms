// Created on 10-05-2019 21:27:42 by necronomicon
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
#include <iomanip>
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
	int f,r,temp;
    while(scanf("%d %d", &f, &r) && f!=0){
    double F[100000],R[100000];
        vector <double> v;
        for (size_t i = 0; i < f; i++)
        {
            cin >> temp;
            F[i] = temp;
        }
        for (size_t i = 0; i < r; i++)
        {
            cin >> temp;
            R[i] = temp;
        }
        for (size_t i = 0; i < f; i++)
        {
            for (size_t j = 0; j < r; j++)
            {
                v.push_back(R[j]/F[i]);
            }
        }
        sort(v.begin(), v.end());
        double maxi = 0;
        double spread;
        for (auto i = v.begin(); i != v.end()-1; i++)
        {
            spread = (*(i+1))/(*i);
            // cout << spread << ' ';
            if(maxi<(spread)){maxi = spread;}
        }
        cout << fixed << setprecision(2) << maxi << endl;
             
    }
    return EXIT_SUCCESS;
}
