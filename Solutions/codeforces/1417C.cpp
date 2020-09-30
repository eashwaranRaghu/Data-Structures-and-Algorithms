// 30-09-2020 02:57:52 necronomicon
#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define ARR_MAX (int)1e5
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
	int t=0;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Vi A(n);
        for(int &a: A) cin >> a;
        map<int,Vi> AV;
        for (int i = 0; i < n; i++) AV[A[i]].push_back(i);
        for(auto av: AV) {
            //cout << av.first << '|';
            //for(int v: av.second) cout << v << ',';
            //cout << ' ';
        } //cout << endl;
        Mii LA;
        for(auto av: AV) {
            int ml = av.second[0]+1;
            av.second.push_back(n);
            for (int i = 0; i+1 < av.second.size(); i++)
            {
                ml = max(ml, abs(av.second[i] - av.second[i+1])+1);
            }
            if(LA[ml]) LA[ml] = min(LA[ml], av.first);
            else LA[ml] = av.first;
        }
        for(auto la: LA) cout << la.first << '-' << la.second << ' ';   cout << endl;
        int cach = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            auto itr = LA.lower_bound(i);
            if(itr == LA.end()) itr--;
            while(true) {
                if(itr == LA.begin()) break;
                if(itr->first >i) itr--;
                else break;
            }

            if(itr->first > i) {
                if(itr == LA.begin()) cout << -1 << ' ';
                else {
                    itr--;
                    cout << (cach = min(cach, itr->second))<< ' ';
                }
            }
            else cout << (cach = min(cach, itr->second)) << ' ';
        }
        cout << endl;
        //cout << endl;
    }
    return EXIT_SUCCESS;
}
