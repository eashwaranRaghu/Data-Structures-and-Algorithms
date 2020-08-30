// Created on 10-05-2019 13:58:25 by necronomicon
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
#define SP <<' '
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
	int mini, temp;
    int B[3], G[3], C[3];
    char arr[3] = {'B', 'G', 'C'};
    string s, temps;
    while(cin >>B[0]>>G[0]>>C[0] >>B[1]>>G[1]>>C[1] >>B[2]>>G[2]>>C[2]){
        mini=MOD;
        s = "CCC";
        temps = "CCC";
        for (size_t i = 0; i < 3; i++) //brown
        {
            for (size_t j = 0; j < 3; j++) // green
            {
                for (size_t k = 0; k < 3; k++) //clear
                {
                    temp = (B[j]+B[k])+(G[i]+G[k])+(C[i]+C[j]);
                    temps[i] = 'B';
                    temps[j] = 'G';
                    temps[k] = 'C';
                    if(j != i && j!=k && i!=k){                
                        if(mini>temp){
                            mini = temp;
                            s = temps;
                        }
                        else if(mini == temp){
                            s = min(s, temps);
                        }
                    }
                }
            }
        }
        cout << s << ' ' << mini<< endl;;
    }
    return EXIT_SUCCESS;
}
