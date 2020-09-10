// 16-11-2019 20:24:57 badLiver
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
	int n;
    cin >> n;
    Vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    USi s;
    Vi arr = {-1};
    int total=0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] > 0) {
            if(s.count(v[i]) > 0) {
                cout << -1;
                // cout << "up";
                return 0;
            }
            else {
                s.insert(v[i]);
            }
        }
        else {
            if(s.count(abs(v[i])) == 0) {
                cout << -1;
                // cout << "down" << v[i];
                return 0;
            }
            else {
                s.erase(abs(v[i]));
            }
        }
        if(s.size() == 0) {
            arr.push_back(i);
            total++;
        }
    }
    if(total == 0 || arr[arr.size()-1] != n-1) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i+1 < arr.size(); i++)
    {
        UMii ss;
        for (int j = arr[i]+1; j <= arr[i+1]; j++)
        {
            if(v[j] > 0) ss[v[j]]++;
            if(ss[v[j]] > 1) {
                cout << -1;
                return 0;
            }
        }
        
    }
    cout << total << endl;
    for (int i = 1; i < arr.size(); i++)
    {
        cout << arr[i] - arr[i-1] << ' ';
    }
    
    return EXIT_SUCCESS;
}
