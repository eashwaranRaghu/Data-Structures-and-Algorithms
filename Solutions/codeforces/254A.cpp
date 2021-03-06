// 22-02-2020 23:34:16 badLiver
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

int main (int argc, char const *argv[]) {
	int n, temp;
    map<int, Vi> v;
    scanf("%d", &n);
    for (int i = 0; i < (n*2); i++) {
        cin >> temp;
        v[temp].push_back(i);
    }
    for (auto i = v.begin(); i != v.end(); i++) {
        if(i->second.size()%2==1) {
            cout << -1;
            return 0;
        }
    }
    for (auto i = v.begin(); i != v.end(); i++) {
        for (int j = 0; j < i->second.size(); j+=2)
        {
            cout << i->second[j]+1 << ' ' << i->second[j+1]+1 << endl;
        }
    }
    return EXIT_SUCCESS;
}
