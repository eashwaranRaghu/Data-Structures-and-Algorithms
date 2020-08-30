// Created on 01-08-2019 20:14:37 by necronomicon
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

class TreeNode{
public:
    int val;
    TreeNode *left = NULL, *right = NULL;

    TreeNode(int val) {
        this->val = val;
    }

    void insert(int val){
        TreeNode *root = this;

        while(root != NULL) {
            if(root->val > val) {
                if(root->left == NULL) {
                    root->left = new TreeNode(val);
                    return;
                }
                else    root = root->left;
            }
            else if(root->val < val) {
                if(root->right == NULL) {
                    root->right = new TreeNode(val);
                    return;
                }
                else    root = root->right;
            }
            else return;
        }
    }

    bool find(int val) {
        TreeNode * root = this;
        while(root != NULL) {
            if(root->val > val) root = root->left;
            else if(root->val < val) root = root->right;
            else return true;
        }
        return false;
    }

    void drop(int val) {
        return;
    }

    void dfs(TreeNode *root) {
        if(root == NULL) return;
        dfs(root->left);
        cout << root->val << endl;
        dfs(root->right);
    }
};

int main (int argc, char const *argv[]) {
	Vi v = {1,2,10,4,11,5};
    TreeNode T(0);
    for(int x: v) T.insert(x);
    
    T.dfs(&T);
    cout << endl;
    return EXIT_SUCCESS;
}
