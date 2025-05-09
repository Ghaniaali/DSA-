#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
		
	node(int d){
		data = d;
		left = right = nullptr;
	}
		
};

node* buildpreorder(){
	int val;
	cin>>val;
	
	if(val == -1 ){
		return nullptr;
	}
	
	node* newnode = new node(val);
	newnode->left = buildpreorder();
	newnode->right = buildpreorder();
	
	return newnode;
}

void preorder(node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    cout << "Enter nodes in preorder (-1 for NULL):\n";
    node* root = buildpreorder();

    cout << "Preorder traversal of constructed tree:\n";
    preorder(root);

    return 0;
}





