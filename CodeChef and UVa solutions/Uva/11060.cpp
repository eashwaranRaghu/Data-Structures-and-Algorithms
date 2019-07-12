// Created on 19-06-2019 17:50:14 by necronomicon
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
    int n, ca = 0;
	while(cin >> n){
        ca++;
        printf("Case #%d: Dilbert should drink beverages in this order: ", ca);
        vector <string> v, u;
        int e;
        string temp, temp1, temp2;
        unordered_map <string, vector <string>> M;
        unordered_map <string, int> degree;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            M[temp] = v;
            u.push_back(temp);
        }
        cin >> e;
        for (int i = 0; i < e; i++)
        {
            cin >> temp1 >> temp2;
            M[temp1].push_back(temp2);
            degree[temp2]++;
        }
        queue <string> q;
        vector <string> aa;
        for (auto d : u)
        {
            if(degree[d] == 0) q.push(d);
        }
        while(!q.empty()){
            temp = q.front();
            q.pop();
            for(auto d : M[temp]){
                degree[d]--;
                if(!degree[d]) q.push(d);
            }
            cout << temp << ' ';
        }
        cout << endl << endl;
    }
    return EXIT_SUCCESS;
}
