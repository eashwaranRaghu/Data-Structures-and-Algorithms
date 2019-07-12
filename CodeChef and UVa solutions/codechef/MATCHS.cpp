// Created on 04-05-2019 01:27:42 by necronomicon
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

bool player = false;
int player2 = 0;

void maxmin(int64 &a, int64 &b){
    int64 temp;
    temp = min(a,b);
    b = max(a,b);
    a = temp;
}

int64 game(int64 a , int64 b){
    cout << a << ':' << b << ' ';
    player = !player;
    maxmin(a,b);
    if(b%a == 0){return 0;}
    int64 times = b/a;
    b = b%a;
    if(times>1){
        if(max(a,b)%min(a,b) == 1){return 0;}
        b+=a;
        // if(max(a,b)%min(a,b) == 0){b+=a;}
        // else{}
    }
    return game(a, b);
}

int game3(int64 a, int64 b){
    cout << a << ':' << b << ' ';
    if (b%a == 0 || b >= 2*a) return 1;
    return 1 - game3(b%a, a);
}

int main () {
	int64 t,i=0;
    cin >> t;
    while (t--){
        player = false;
        player2 =0;
        int64 m, n;
        cin >> n >> m;
        // game(n, m);
        // cout << ((player)? "Ari":"Rich") << endl;
        // cout << ++i << ' ' << n << ' ' << m << ' '  << ((player)? "Ari":"Rich") << endl;
        maxmin(n,m);
        cout << ((game3(n,m))? "Ari":"Rich") << endl;
        // cout << ++i << ' ' << n << ' ' << m << ' '  << ((game3(n,m))? "Ari":"Rich") << endl;
    }
    return EXIT_SUCCESS;
}
