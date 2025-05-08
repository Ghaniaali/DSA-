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
		
		void deleteAtEnd(){
			if (head == nullptr){
			 cout<<"List is empty! "<<endl;
			 return;
			}
			
			if(head->next == nullptr){
				delete head;
				head = nullptr;
				return ;
			}
			
			node* secondlast = head;
			while(secondlast->next->next != nullptr){
				secondlast = secondlast->next;
			}
			
			delete secondlast->next;
			secondlast->next = nullptr;
		}
	
	void traverse(){
		node* current = head;
		while(current != nullptr){
			cout<<current->data<<" ";
			current = current->next;
		}
		cout<<endl;
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
	
	list.deleteAtEnd();
	cout<<"After deleting: "<<endl;
	list.traverse();
}