#include<iostream>
using namespace std;

int Max(int arr[],int size){
	
	int max = arr[0];
	
	for(int i=1; i<size; i++){
		if (arr[i]> max){
			max = arr[i];
		}
	}
	
	return max;

}

int main(){
	
	int arr[] = {10,324,45,80,90,100};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Largest Element: "<<Max(arr,size)<<endl;
		
	return 0;	
}