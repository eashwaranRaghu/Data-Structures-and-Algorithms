#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node *&root, int data) {
      fun(root, data);
      return root;
    }
    void fun(Node *&root, int data) {
      Node n(data);
      if (root == NULL){
        root = &n;
        return;
      }
      if (root->data > data) {
        if (root->left == NULL) {
          root->left = &n;
          return;
        } else {
          fun(root->left, data);
        }
      } else if (root->data < data) {
        if (root->right == NULL) {
          root->right = &n;
          return;
        } else {
          fun(root->right, data);
        }
      }
      return;
    }
};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	cout << root->data << endl;
    myTree.preOrder(root);
  
    return 0;
}
