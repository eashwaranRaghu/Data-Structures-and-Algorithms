// Created on 20-06-2019 12:32:35 by necronomicon
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

int64 kadane(Vi v){
    int64 sum=0, SUM=-922337203685477580;
    for (int64 i = 0; i < v.size(); i++)
    {
        if(sum > sum + v[i]){
            sum = 0;
        }
        else{
            sum+=v[i];
            SUM = max(SUM, sum);
        }
    }
    return SUM;

    int64 max_so_far = -922337203685477580, max_ending_here = 0; 
  
    for (int64 i = 0; i < v.size(); i++)
    { 
        max_ending_here = max_ending_here + v[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 

}

int main () {
	int64 t, n, k, temp, sum, mx;
    cin >> t;
    while (t--){
        cin >> n >> k;
        Vi v, u;
        sum =0, mx = -922337203685477580;
        for (int64 i = 0; i < n; i++)
        {
            cin >> temp;
            sum += temp;
            mx = max(mx, temp);
            v.push_back(temp);
        }
        u.insert(u.end(), v.begin(), v.end());
        int64 one = kadane(u);
        u.insert(u.end(), v.begin(), v.end());
        int64 two = kadane(u);
        u.insert(u.end(), v.begin(), v.end());
        int64 three = kadane(u);
        int64 ans =0;
        if(mx <= 0){
            ans = mx;
        }
        else{
            if(k == 1){
                ans = one;
            } else if (k == 2){
                ans = max(one, two);
            } else if (k == 3) {
                ans = max(one, max(two, three));
            } else {
                ans = max(one, max(two, max(three, three + (k-3)*sum)));
            }
        }
        cout << ans << endl;
    }
    return EXIT_SUCCESS;
}
