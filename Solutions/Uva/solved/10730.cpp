// Created on 10-05-2019 19:59:35 by necronomicon
#include <bits/stdc++.h>
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
	int n, arr[100000];
    
    while(scanf("%d: ", &n) && n!=0){
        
        bitset <10001> b;
        int temp, diff, flag = 1;
        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            arr[i] = temp;
        }
        for (size_t i = 0; i < n-1; i++)
        {
            b[arr[i]] = true;
            for (size_t j = i+1; j < n; j++)
            {
                if(i>0){
                    diff = arr[j]-arr[i];
                    if(arr[i]-diff >= 0 && arr[i]-diff < n && b[arr[i]-diff] == true){flag = 0;}
                }
            }
        }
        cout << (flag ? "yes":"no") << endl;
    }
    return EXIT_SUCCESS;
}
