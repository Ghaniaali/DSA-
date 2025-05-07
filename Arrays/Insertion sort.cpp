#include<iostream>
using namespace std;

void insertionsort (int arr[], int n){
	
	for(int i=1; i<n; i++){
		int temp = arr[i];
		int j;
		for(int j=i-1; j >= 0 && arr[j]>temp; j--){
			arr[j+1]= arr[j];
			cout<<arr[j] <<" swapped: " <<arr[j+1];
		}
		  arr[j+1]=temp;
	}
}

void printarray(int arr[], int n){
	
	for (int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	
	int arr[]={45, 12, 8, 33, 17, 25, 19, 2, 50, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Original Array: "<<endl;
	printarray(arr,n);
	
	insertionsort(arr,n);
	
	cout<<"Sorted Array: "<<endl;
	printarray(arr,n);
	
	
	return 0;
}