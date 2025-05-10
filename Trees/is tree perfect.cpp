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
        left = right = nullptr;
    }
};

int finddepth(node* root) {
    int d = 0;
    while (root) {
        d++;
        root = root->left;
    }
    return d;
}

bool isperfectbinarytree(node* root, int d, int level = 0) {
    if (!root) {
        return true;
    }

    if (!root->left && !root->right) {
        return d == level + 1;
    }

    if (!root->left || !root->right) {
        return false;
    }

    return isperfectbinarytree(root->left, d, level + 1) &&
           isperfectbinarytree(root->right, d, level + 1);
}

int main() {
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int depth = finddepth(root);
    if (isperfectbinarytree(root, depth)) {
        cout << "The tree is a Perfect Binary Tree.\n";
    } else {
        cout << "The tree is NOT a Perfect Binary Tree.\n";
    }

    return 0;
}
