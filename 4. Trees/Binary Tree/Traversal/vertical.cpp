// 11-09-2020 16:39:14 necronomicon
#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define ARR_MAX (int)1e5
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

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs (TreeNode *root, int idx, map<int, Vi> &m) {
    if(root == NULL) return;
    m[idx].push_back(root->val);
    dfs(root->left, idx-1, m); // distance decrements on moving left
    dfs(root->right, idx+1, m); // distance increments on moving left
}

void vertical (TreeNode *root) {
    map<int, Vi> m; // map to store elements  against their distance from center
    dfs(root, 0, m); // modified dfs to fill the map
    for (auto x: m) { // print the values.
        for (int y: x.second) cout << y;
        cout << endl;
    }
}

int main () {
	TreeNode root(5);
    root.left = new TreeNode(3);
    root.right = new TreeNode(7);
    root.left->left = new TreeNode(2);
    root.left->right = new TreeNode(4);
    vertical(&root);
    return EXIT_SUCCESS;
}
