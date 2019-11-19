// Created on 05-05-2019 08:53:03 by necronomicon
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


int arr[1009][1009];

int main () {
	int t;
    cin >> t;
    while (t--){
        int r = 0;
        int n;
        cin >> n;
        int arr[1009];
        for (size_t i = 0; i < n; i++){arr[i] =0;}
        
        for (size_t i = 0; i < n-1; i++)
        {
            for (size_t j = i+1; j < n; j++)
            {
                if((arr[i]<1 || arr[j]<1) && (arr[i]<n && arr[j]<n)){
                    arr[i]++; arr[j]++; r++;
                    cout << i << ':' << j << ' ';
                }
            }
            if(r>= 8*n) break;
        }
        cout << endl;
        for (size_t i = 0; i < n; i++){cout << arr[i] << ' ';}
        cout << endl;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if(arr[i]>0){
                    cout << 1;
                    arr[i]--;
                }
                else{
                    cout << 0;
                }
            }
            cout << endl;
        }
    }
    return EXIT_SUCCESS;
}
