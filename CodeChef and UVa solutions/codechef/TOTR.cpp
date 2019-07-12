// Created on 26-06-2019 00:56:53 by necronomicon
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
	int t;
    string s, line, line2;
    getline(cin, line);
    stringstream ss(line);
    ss >> t >> s;
    map <char, char> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[i + 'a'] = s[i];
        m[i + 'a' - 32] = s[i] - 32;
    }
    while (t--){
        getline(cin, line);
        // cout << t << ':' << line << ':';
        for (int i = 0; i < line.size() && line[i]!='\0'; i++)
        {
            if(line[i] == '_') line[i] = ' ';
            else if(line[i] == '.' || line[i] == ',' || line[i] == '?' || line[i] == '!'){
                continue;
            }
            else{
                line[i] = m[line[i]];
            }
        }
        cout << line << endl;
    }
    return EXIT_SUCCESS;
}
