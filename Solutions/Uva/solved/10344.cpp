// Created on 12-05-2019 15:04:50 by necronomicon
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
int A[5];
int * ptr;
int f;
void rec(int k, int sum){
    if(k == 5) {
        if(sum == 23) {f= 1;}
        return;
    }
    for (size_t i = 0; i < 5; i++)
    {
        if(A[i] == 0){
            A[i] = 1;
            rec(k+1, sum+ptr[i]);
            rec(k+1, sum*ptr[i]);
            rec(k+1, sum-ptr[i]);
            A[i] = 0;
        }
    }
}

int main () {
	int a,b,c,d,e;
    while(cin >> a >> b >> c >> d >> e && (a || b || c || d || e)){
        int arr[5] = {a,b,c,d,e};
        ptr = arr;
        
        f=0;
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t i = 0; i < 5; i++)
            {
                A[i] =0;
            }
            A[i] = 1;
            rec(1, arr[i]);
        }
        cout << ((f)? "Possible":"Impossible") << endl;
    }
    return EXIT_SUCCESS;
}
