// Created on 10-05-2019 16:19:31 by necronomicon
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
	int K,a,b,c,x,y,z;
    while(cin >> K){
        Pii p;
        VPii v;
        int kplus1 = K*(K+1);
        for (size_t i = K+1; i <  2*K+1 ; i++)
        {
            int j = (K*i)/(i-K);
            if((i+j)*K == i*j){
                p.first = i;
                p.second = (int)j;
                v.push_back(p);
            }
        }
        sort(v.begin(), v.end(), [](Pii r1 ,Pii r2){
            if(r1.first > r2.first) return false;
            if(r1.first > r2.first){
                if(r1.second > r2.second) return false;
            }
            return true;
        });
        for (auto i = v.begin(); i != v.end(); i++)
        {
            if(i->first < i->second){
                int temp = i->second;
                i->second = i->first;
                i->first = temp;
            }
        }
        cout << v.size() << endl;
        for (auto i = v.begin(); i != v.end(); i++)
        {
            cout << "1/" << K << " = 1/" << i->first << " + 1/" << i->second << endl;
        }
    }
    return EXIT_SUCCESS;
}
