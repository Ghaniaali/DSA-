#include <iostream>
#include <algorithm>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = right = nullptr;
    }
};

// Function to build a binary tree in preorder from user input
node* buildTree() {
    int val;
    cin >> val;

    if (val == -1) return nullptr; // -1 means NULL node

    node* root = new node(val);
    root->left = buildTree();     // Recursively build left subtree
    root->right = buildTree();    // Recursively build right subtree

    return root;
}

// Function to calculate height and update diameter in one go
int height(node* root, int& dia) {
    if (!root) return 0;

    int lh = height(root->left, dia);   // left height
    int rh = height(root->right, dia);  // right height

    dia = max(dia, lh + rh);  // update the max diameter
    return 1 + max(lh, rh);   // return height of current node
}

// Function to compute diameter
int diameter(node* root) {
    int dia = 0;
    height(root, dia);  // fills dia during traversal
    return dia;
}

// Preorder Traversal for verification
void preorder(node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    cout << "Enter tree nodes in preorder (-1 for NULL):\n";
    node* root = buildTree();

    cout << "\nPreorder traversal of tree:\n";
    preorder(root);

    int dia = diameter(root);
    cout << "\n\nDiameter of the tree: " << dia << endl;

    return 0;
}
