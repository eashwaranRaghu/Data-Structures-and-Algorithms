// Created on 30-06-2019 02:13:22 by necronomicon
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
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cctype>
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
    string line, temp;
    getline(cin, line);
    stringstream l(line);
	int t;
    l >> t;
    while (t--){
        getline(cin, line);
        stringstream ll(line);
        string r = "";
        vector<string>v;
        while(ll >> temp){
            v.push_back(temp);
        }
        for (int i = 0; i+1 < v.size(); i++)
        {
            r+= (toupper(v[i][0]));
            r+= ". ";
        }
        for (int i = 0; i < v[v.size()-1].size(); i++)
        {
            v[v.size()-1][i] = tolower(v[v.size()-1][i]); 
        }
        v[v.size()-1][0] = toupper(v[v.size()-1][0]);
        r+=v[v.size()-1];
        cout << r << endl;
    }
    return EXIT_SUCCESS;
}
