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
		
	void reverse() {
        node* prev = nullptr;
        node* current = head;
        node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
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
	
	
    list.reverse();
    cout << "Reversed Linked List: ";
    list.traverse();
}