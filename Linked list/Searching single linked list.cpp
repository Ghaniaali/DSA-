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
	
	bool searching(int target){
		node* current = head;
		while(current != nullptr){
		 if(current->data == target){
		 	return true;
		 }
		 current = current->next;
	}
	return false;
}
	
};

int main(){
	
	singlylinkedlist list;
	
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	
	cout<<"linked List: ";
	list.traverse();
	
	
	int target = 30;
	if(list.searching(target)){
		cout<<"Element "<<target<<" found in the list."<<endl;
	} else {
		cout<<"Element "<<target<<" not found in the list."<<endl;
	}
	 return 0;
}