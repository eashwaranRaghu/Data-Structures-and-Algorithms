// Created on 29-06-2019 18:33:07 by necronomicon
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

int main () {
	int t;
    cin >> t;
    while (t--){
        int64 n, temp, arr[3]={0,0,0}, brr[3]={0,0,0};
        Vi a, b;
        bool ans = false;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if(temp >=0){
                if(temp==1) arr[1]++;
                else if(temp==0) arr[0]++;
                else if(temp>1){
                    arr[2]++;
                    a.push_back(temp);
                }
            } else{
                if(temp == -1) brr[1]++;
                else if(temp < -1){
                    brr[2]++;
                    b.push_back(temp);
                }
            }
        }
        if((arr[2]==0 && brr[2]==0) || n==1) ans = true;
        else{
            if(arr[2]==0 && brr[2]!=0 && b.size()==1) ans = true;
            else if(arr[2]!=0 && brr[2]==0 && a.size()==1) ans = true;
            else{
                if((arr[2]!=0 && brr[2]!=0) && ((a.size()==1 && b.size()==1 && a[0] == -1*b[0]))) ans = true;
                else ans = false;
            }
        }
        cout << (ans? "yes":"no") << endl;
    }
    return EXIT_SUCCESS;
}
