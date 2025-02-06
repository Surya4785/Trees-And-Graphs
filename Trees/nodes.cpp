// c++ of find all nodes that are at distance k from the root of a binary tree usign recursion.

#include<bits/stdc++.h> 
using namespace std;

class Node  { 
public:
    int data; 
    Node* left; 
    Node* right; 
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; 

void KdistanceUill(Node *root, int k, vector<int> &result) { 
  
      // If root is null and k is not zero return it
    if(root == NULL|| k < 0 ) 
        return; 
  
      // if k is zero then store the data and return
    if( k == 0 ) { 
          result.push_back(root->data);
        return;
    } 
  
      // Make recursive call on left and right pointer
    KdistanceUill(root->left, k - 1, result) ; 
    KdistanceUill(root->right, k - 1, result) ; 
} 

// Function to result all nodes at kth distance from root
vector<int> Kdistance(struct Node *root, int k) {
    vector<int> result;
      KdistanceUill(root, k, result);
      return result;
}
int main() { 

    // Constructed binary tree:
    //         1 
    //       /   \ 
    //      2     3 
    //     / \   / 
    //    4   5 8 
    
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(8); 
    
    vector<int> result = Kdistance(root, 2);
      for(int i : result) {
         cout << i << " "; 
    }
    return 0; 
}
