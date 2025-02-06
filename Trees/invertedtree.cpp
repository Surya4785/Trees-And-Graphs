// C++ Program Invert a Binary Tree using Recursive Postorder

#include <iostream>
#include <queue>
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

// function to return the root of inverted tree
void mirror(Node* root) {
    if (root == nullptr)
        return ;
    
    // Invert the left and right subtree
    mirror(root->left);
    mirror(root->right);
  
    // Swap the left and right subtree
    swap(root->left, root->right);
}

// Print tree as level order
void levelOrder(Node *root) {
    if (root == nullptr) {
          cout << "N ";
          return ;
    }

    queue<Node*> qq;
    qq.push(root);

    while (!qq.empty()) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        cout << (curr->data) <<  " ";
        qq.push(curr->left);
        qq.push(curr->right);
    }
}

int main() {

    // Input Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    mirror(root);
  
    // Mirror Tree:
    //       1
    //      / \
    //     3   2
    //        / \
    //       5   4
    levelOrder(root);
    return 0;
}
