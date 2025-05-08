#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int d){
			data=d;
			next=nullptr;
		}
};

class singlylinkedlist{
	public:
		node* head;
		
		singlylinkedlist(){
			head = nullptr;
		}
		
		//function to add at the end
		void append(int data){
			node* newnode= new node(data);
			
			if(head == nullptr){
				head = newnode;
			}
			else{
				node* temp = head;
				while(temp->next != nullptr){
					temp = temp->next;
				}
				temp->next = newnode;
			}
		}
	
	void traverse(){
		node* current = head;
		while(current != nullptr){
			cout<<current->data<<" ";
			current = current->next;
		}
		cout<<endl;
	}	
	
	void insertAtposition(int data, int position){
		node* newnode = new node(data);
		
		if (position == 1){
			newnode->next = head;
			head = newnode;
			return;
		}
		
		node* current = head;
		int count = 1;
		
		
		while(current != nullptr && count < position - 1 ){
			current = current->next;
			count++;
		}
		
		if(current == nullptr){
			cout<<"position is out of range! "<<endl;
			return;
		}
		
		newnode->next = current->next;
		current->next = newnode;
	
	}
	
};

int main(){
	
	singlylinkedlist list;
	
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	
	cout<<"linked List before inserting at position 3: ";
	list.traverse();
	
	list.insertAtposition(25,3);
	
	cout<<"linked List before inserting at position 3: ";
	list.traverse();
	
	 return 0;
}