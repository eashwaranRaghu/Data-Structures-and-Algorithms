// Created on 10-05-2019 18:59:02 by necronomicon
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
	int a,b,c,x,y,z,temp;
    int n, arr[100000], q;
    int t=0;
    while(cin >> n && n!=0){
        t++;
        for (size_t i = 0; i < n; i++)
        {
            cin >> temp;
            arr[i] = temp;
        }
        cin >> q;
        printf("Case %d:\n", t);
        sort(arr, arr+n);
        int *ptr1;
        int *ptr2;
        for (size_t i = 0; i < q; i++)
        {
            cin >> temp;
            ptr1 = arr;
            ptr2 = arr+n-1;
            int closest = MOD, diff;
            while(ptr1 != ptr2 && ptr1 != NULL && ptr2 != NULL){
                diff = (*ptr1 + *ptr2) - temp;
                if(abs(closest)>abs(diff)) closest = diff;
                if(diff > 0){
                    ptr2--;
                } else if (diff < 0){
                    ptr1++;
                } else {
                    break;
                }
            }
            printf("Closest sum to %d is %d.\n", temp, temp+closest);
        }
    }
    return EXIT_SUCCESS;
}
