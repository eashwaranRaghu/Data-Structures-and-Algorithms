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

int solution(string &S1, string &S2) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map <char, int> M;

}


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int SUM= -2147483640, SUMI=0, sum=0, pos=0, pO2=0;
    while(pos < A.size()){
        sum=0;
        for (int i = pos; i < (pos + pow(2, pO2)); i++)
        {
            if(i < A.size()){
                sum += A[i];
            }
        }
        if(sum > SUM){
            SUM = sum;
            SUMI = pO2;
        }
        pos += pow(2,pO2);
        pO2++;
    }
    return SUMI;

}

int main () {
	
    return EXIT_SUCCESS;
}
