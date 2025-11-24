// Binary Tree 

#include <iostream>
using namespace std;

// Node struct

struct Node {
  
  int data;
  Node* left;
  Node* right;
  
  Node(int value){
    
    data = value;
    left = nullptr;
    right = nullptr;
    
  }
};

// Insert Node into Binary Seacrh Tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Traversal

void inorder(Node* root) {
  
  if (root != nullptr) {
     inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
    }
}

int main() {
  
    Node* root = nullptr;

    int values[] = {1, 11, 15, 3, 7, 12, 18, 2, 6};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    cout << "Inorder Traversal (Sorted Order): ";
    inorder(root);
    cout << endl;
    cout << "Root : "<< root->data;
    return 0;
}