// Created on 19-06-2019 02:43:28 by necronomicon
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

int n, c;
string arr[1000], temp;
int arr2[1000][1000];
int col;

void fire(int i, int j){
    if(i<0 || j <0) return;
    if(i==n || j == n) return;
    if(arr[i][j] == '0') return;
    if(arr2[i][j] == 1) return;

    arr2[i][j] = 1;

    fire(i+1,j);
    fire(i-1,j);
    fire(i,j+1);
    fire(i,j-1);

    fire(i+1,j+1);
    fire(i-1,j+1);
    fire(i-1,j-1);
    fire(i+1,j-1);
}

int main () {
	int number =1;
    while(cin >> n && n){
        c =0, col=0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            arr[i] = temp;
            for (int j = 0; j < n; j++)
            {
                arr2[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(arr[i][j] == '1' && arr2[i][j] == 0){
                    col++;
                    // cout << col << ' ' << i << ':' << j << endl;
                    c++;
                    fire(i, j);
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << endl;
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << arr2[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        printf("Image number %d contains %d war eagles.\n", number, c);
        number++;
    }
    return EXIT_SUCCESS;
}
