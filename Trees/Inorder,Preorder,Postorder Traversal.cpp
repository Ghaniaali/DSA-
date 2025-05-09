#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor
    node(int d) {
        data = d;
        left = right = nullptr;  // Corrected from "null" to "nullptr"
    }
};

// Function to insert a new node in BST
node* Insert(node* root, int d) {
    // If tree is empty, create a new node
    if (root == nullptr) {
        return new node(d);
    }

    // Otherwise, recur down the tree
    if (d < root->data) {
        root->left = Insert(root->left, d);
    } else if (d > root->data) {
        root->right = Insert(root->right, d);
    }

    // Return the unchanged root pointer
    return root;
}

// Inorder traversal to print the tree in sorted order
void inorder(node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal to print the tree in sorted order
void preorder(node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

// Postorder traversal to print the tree in sorted order
void postorder(node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}



// Driver Code
int main() {
    node* root = nullptr;

    // Inserting elements
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 70);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 60);
    root = Insert(root, 80);

    cout << "Inorder Traversal of BST: ";
    inorder(root);

    cout<< endl;
    
    cout << "Preorder Traversal of BST: ";
    preorder(root);
    
    cout<<endl;
    
    cout << "Postorder Traversal of BST: ";
    postorder(root);
    
    return 0;
}
