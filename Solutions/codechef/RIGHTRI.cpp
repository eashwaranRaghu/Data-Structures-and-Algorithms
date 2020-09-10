// Created on 21-06-2019 12:43:11 by necronomicon
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

float distance(int x1, int y1, int x2, int y2) 
{ 
    // Calculating distance 
    return (pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) * 1.0); 
}

bool isR(int x1, int x2, int x3, int  y1, int y2, int y3){
    int one = distance(x1, y1, x2, y2);
    int two = distance(x1, y1, x3, y3);
    int thr = distance(x2, y2, x3, y3);
    if(one + two == thr || one + thr == two || thr + two == one) return true;
    return false;
}

int main () {
	int n, x1,x2,x3, y1,y2,y3, c=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >>  y1 >> x2 >>  y2 >> x3 >>  y3;
        if(isR(x1,x2,x3, y1,y2,y3)) c++;
    }
    cout << c;
    return EXIT_SUCCESS;
}
