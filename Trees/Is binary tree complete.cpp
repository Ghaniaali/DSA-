#include<iostream>
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

// Count total number of nodes in the binary tree
int countnodes(node* root) {
    if (!root) {
        return 0;
    }
    return 1 + countnodes(root->left) + countnodes(root->right);
}

// Check if tree is complete
bool iscomplete(node* root, int index, int totalnodes) {
    if (!root) {
        return true; // Empty node is complete
    }

    if (index >= totalnodes) {
        return false; // Node index exceeds total count — not complete
    }

    // Recursively check left and right children
    return iscomplete(root->left, 2 * index + 1, totalnodes) &&
           iscomplete(root->right, 2 * index + 2, totalnodes);
}

// Wrapper function to check completeness
bool iscompletetree(node* root) {
    int totalnodes = countnodes(root);
    return iscomplete(root, 0, totalnodes);
}

int main() {
    // Sample Tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);

    if (iscompletetree(root)) {
        cout << "The binary tree is COMPLETE.\n";
    } else {
        cout << "The binary tree is NOT complete.\n";
    }

    return 0;
}
