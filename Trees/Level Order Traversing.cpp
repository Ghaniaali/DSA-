#include<iostream>
#include<queue> // For using queue
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

// Level Order Traversal Function
void levelOrder(node* root) {
    if (!root) return; // Empty tree case

    queue<node*> q;     // Create a queue to store nodes level-wise
    q.push(root);       // Start with root

    while (!q.empty()) {
        node* current = q.front(); // Get the front node
        q.pop();                   // Remove it from the queue
        cout << current->data << " "; // Print the node's data

        if (current->left)  // If left child exists
            q.push(current->left);  // Add it to the queue

        if (current->right) // If right child exists
            q.push(current->right); // Add it to the queue
    }
}

int main() {
    // Sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}
