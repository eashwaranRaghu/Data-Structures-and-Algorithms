// Created on 28-06-2019 22:38:34 by necronomicon
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
	int t;
    cin >> t;
    while (t--){
        int m, x , y,a=0;
        cin >> m >> x >> y;
        int arr[100000], temp;
        for (int i = 1; i <= 100; i++) arr[i]=0;
        for (int i = 1; i <= m; i++)
        {
            cin >> temp;
            arr[temp] = 1;
            for (int j = 1; j <= x*y; j++)
            {
                if(i+j<=100)arr[i+j] = 2;
                if(i-j>0)arr[i-j] = 2;
            }
        }
        for (int i = 1; i <= 100; i++)
        {
            if(arr[i]==0) a++;
        }
        cout << a << endl;
    }
    return EXIT_SUCCESS;
}
