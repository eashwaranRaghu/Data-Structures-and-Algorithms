// Created on 05-05-2019 08:53:03 by necronomicon
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


int arr[1009][1009];

int main () {
	int t;
    cin >> t;
    while (t--){
        int r = 0;
        int n;
        cin >> n;
        int k =0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j]=0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                arr[i][((n/8+1)*j)+k] = 1;
            }
            k++;
            if( i %8 == 0)k = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //cout << arr[i][j];
                if(arr[i][j] == 1)cout<<"O";
                else cout<<".";
            }
            cout << endl;
        }
    }
    return EXIT_SUCCESS;
}

