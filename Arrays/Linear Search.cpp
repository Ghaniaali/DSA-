#include<iostream>
using namespace std;

int linearsearch(int arr[], int size, int x){
	
	for (int i=0; i<size; i++){
		if(arr[i]==x){
			return i;
		}
	}
	
	return -1;
}

int main(){
	
	int arr[6] = {2,3,4,5,6,10};
	int size = sizeof(arr)/sizeof(arr[0]);
	int x= 6;
	
	int result = linearsearch(arr,size,x);
	
	if(result == -1){
		cout<<"Not Present"<<endl;
	}
	else {
		cout<<"Present at index: "<<result<<endl;
	}
		
	return 0;	
}
