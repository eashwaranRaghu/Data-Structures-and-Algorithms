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

// 1. Initialize current as root 
// 2. While current is not NULL
//    If the current does not have left child
//       a) Print current’s data
//       b) Go to the right, i.e., current = current->right
//    Else
//       a) Find the rightmost node in current's left subtree
//       IF the rightmost node points back to current then its already explored territory
//          a) clear the backlinks
//          b) print current node and move right
//       ELSE
//          a) Make current as the right child of the rightmost 
//          node in current's left subtree
//          b) Go to this left child, i.e., current = current->left

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void morris (TreeNode *root) {
    TreeNode* current = root; // Initialize current as root 
    TreeNode* temp;
    if (current == NULL) return;
    while(current != NULL) {
        if (current->left == NULL) { // If the current does not have left child
            cout << current->val; // Print current’s data
            current = current->right; // Go to the right, i.e., current = current->right
        }
        else {
            temp = current->left;
            while(temp->right != NULL && temp->right != current) temp = temp->right;
            if(temp->right == NULL) {
                temp->right = current; // Make current as the right child of the rightmost node in current's left subtree
                current = current->left; // Go to this left child, i.e., current = current->left
            }
            else { // left already explored so remove backlinks and move right.
                temp->right = NULL; // set right child back to null
                cout << current->val; // print the node
                current = current->right; // Goto the right child as left is already explored.
            }
        }
    }
}

int main () {
	TreeNode root(5);
    root.left = new TreeNode(3);
    root.right = new TreeNode(7);
    root.left->left = new TreeNode(2);
    root.left->right = new TreeNode(4);
    morris(&root);
    return EXIT_SUCCESS;
}
