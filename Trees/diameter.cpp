// to find the diameter of a binary tree.
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* root) {
  
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), 
                   height(root->right));
}

int diameter(Node* root) {
  
    if (root == nullptr)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max({lheight + rheight, ldiameter, rdiameter});
}

int main() {

    // Constructed binary tree is
    //          5
    //        /   \
    //       8     6
    //      / \   /
    //     3   7 9
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
      root->right->left = new Node(9);
    cout << diameter(root) << endl;

    return 0;
}
