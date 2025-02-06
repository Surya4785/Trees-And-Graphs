// C++ Program to check children sum property
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node (int x) {
            data = x;
            left = nullptr;
            right = nullptr;
        }
};

// returns 1 if children sum property holds
// for the given node and both of its children
int isSumProperty(Node* root) {

    // If root is NULL or it's a leaf node
    // then return true
    if (root == nullptr
        || (root->left == nullptr && root->right == nullptr))
        return 1;
        
    int sum = 0;
    
    // If left child is not present then 0
    // is used as data of left child
    if (root->left != nullptr)
        sum += root->left->data;

    // If right child is not present then 0
    // is used as data of right child
    if (root->right != nullptr)
        sum += root->right->data;

    // if the node and both of its children
    // satisfy the property return 1 else 0
    return ((root->data == sum)
            && isSumProperty(root->left)
            && isSumProperty(root->right));
    
}

int main() {
    
    // Create a hard coded tree.
    //         35
    //       /   \
    //      20    15
    //     /  \  /  \
    //   15   5 10   5
    Node* root = new Node(35);
    root->left = new Node(20);
    root->right = new Node(15);
    root->left->left = new Node(15);
    root->left->right = new Node(5);
    root->right->left = new Node(10);
    root->right->right = new Node(5);

    cout << isSumProperty(root) << endl;
    return 0;
}
