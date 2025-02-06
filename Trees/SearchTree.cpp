// to find minimum value in BST using inorder traversal
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

// Recursive function to solve and store elements in a vector
void inorder(Node* root, vector<int>& sortedInorder) {
  
    // Base Case
    if (root == nullptr) return;

    // Traverse left subtree
    inorder(root->left, sortedInorder);

    // Store the current node's data
    sortedInorder.push_back(root->data);

    // Traverse right subtree
    inorder(root->right, sortedInorder);
}

// Function to find the minimum value in BST
int minValue(Node* root) {
    if (root == nullptr) {
        return -1;
    }
    
    vector<int> sortedInorder;
    
    // Call the recursive inorder function
    inorder(root, sortedInorder);
    
    // Return the first element, which is the minimum
    return sortedInorder[0];
}

int main() {

    // Representation of input binary search tree
    //        5
    //       / \
    //      4   6
    //     /     \
    //    3       7
    //   / 
    //  1
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->left->left->left = new Node(1);

    cout << minValue(root) << "\n";

    return 0;
}
