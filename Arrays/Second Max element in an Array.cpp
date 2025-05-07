#include<iostream>
using namespace std;

int secondMax(int arr[],int size){
	
	int max = 0;
	int second = 0;
	
	for(int i=0; i<size; i++){
		if (arr[i] > max){
			second = max;
			max = arr[i];
		}
		else if(arr[i] > second && arr[i] != max){
			second = arr[i];
		}	
	}
	
	return second;

}

int main(){
	
	int arr[] = {10,324,45,80,90,100};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Second Largest Element: "<<secondMax(arr,size)<<endl;
		
	return 0;	
}