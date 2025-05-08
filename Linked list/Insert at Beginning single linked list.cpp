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
	
	int length(){
		int len = 0;
		node* current = head;
		while(current != nullptr){
			len++;
			current= current->next;
		}
		return len;
	}
	
	void insertAtBeg(int data){
		node* newnode = new node(data);
		
		newnode->next = head;
		head = newnode;
	}
	
};

int main(){
	
	singlylinkedlist list;
	
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	
	cout<<"linked List before inserting: ";
	list.traverse();
	
	list.insertAtBeg(5);
	
	cout<<"linked List after inserting: ";
	list.traverse();
	
	
	 return 0;
}
	