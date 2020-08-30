// 21-07-2020 06:12:13 necronomicon
#include <bits/stdc++.h>
using namespace std;

#define ARR_MAX (int)1e5 //Max array length
#define INF (int)1e9 //10^9
#define MOD 1000000007 //10^9+7
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
    int cnt=0;
    for (int64 i = 1; 4*i < 2000; i++)
    {
        for (int64 j = i; i+3*j < 2000; j++)
        {
            for (int64 k = j; i+j+2*k < 2000; k++)
            {
                int sum = (i+j+k);
                int pro = (i*(j*k));
                int64 l = (sum*1e6)/(pro-1e6);

                bool cond1 = (l >= k) && (l > 0 && l < 20*1e6);
                bool cond2 = pro > 1e6 && sum+l <= 2000;
                bool cond3 =  ((sum+l)*1e6 == pro*l) && (sum+l <= 20*1e6);

                if( cond1 && cond2 && cond3 ) {
                    cout << setprecision(2) << ((double)i)/100 << ' ' << ((double)j)/100 << ' ' << ((double)k)/100 << ' ' << ((double)l)/100 << endl;
                    cnt++;
                }
            }
        } 
    }
    //cout << cnt;
    return EXIT_SUCCESS;
}

// ref https://github.com/ackoroa/UVa-Solutions/commit/8f3cbf4cf4ab1fef1df00699055e00d3093bcd19