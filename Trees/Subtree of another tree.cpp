#include <iostream>
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

// Function to build tree using preorder input
node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    node* newNode = new node(val);
    newNode->left = buildTree();
    newNode->right = buildTree();
    return newNode;
}

// Function to check if two trees are identical
bool isIdentical(node* root1, node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;

    return (root1->data == root2->data &&
            isIdentical(root1->left, root2->left) &&
            isIdentical(root1->right, root2->right));
}

// Function to check if subRoot is a subtree of root
bool isSubtree(node* root, node* subRoot) {
    if (!subRoot) return true;      // Empty tree is always a subtree
    if (!root) return false;        // Big tree is empty, small tree isn't

    if (isIdentical(root, subRoot)) return true;

    // Recur for left and right subtree of main tree
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// Preorder traversal (for verification)
void preorder(node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    cout << "Enter main tree (preorder, -1 for NULL):\n";
    node* root = buildTree();

    cout << "Enter subtree (preorder, -1 for NULL):\n";
    node* subRoot = buildTree();

    cout << "\nMain Tree (Preorder): ";
    preorder(root);
    cout << "\nSubtree (Preorder): ";
    preorder(subRoot);

    cout << "\n\nIs Subtree: " << (isSubtree(root, subRoot) ? "Yes" : "No") << endl;

    return 0;
}
