// to count leaf nodes in a binary tree using recursion
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to count the leaf nodes in a binary tree
int countLeaves(Node* root) {
  
    // If the root is null, return 0
    if (root == nullptr) {
        return 0;
    }
    
    // If the node has no left or right child,
    // it is a leaf node
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    
    // Recursively count leaf nodes in left 
    // and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
  
    // Representation of input binary tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << countLeaves(root) << "\n";  

    return 0;
}
