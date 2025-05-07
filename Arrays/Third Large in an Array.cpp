#include<iostream>
using namespace std;

int ThirdMax(int arr[],int size){
	
	int max = 0;
	int second = 0;
	int third = 0;
	
	for(int i=0; i<size; i++){
		if (arr[i] > max){
			third = second;
			second = max;
			max = arr[i];
		}
		else if(arr[i] > second && arr[i] != max){
			third = second;
			second = arr[i];
		}
			
		else if(arr[i] > third && arr[i] != second && arr[i] != max){
			third = arr[i];
		}

	}
	
	return third ;

}

int main(){
	
	int arr[] = {10,324,45,80,90,100};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Third Largest Element: "<<ThirdMax(arr,size)<<endl;
		
	return 0;	
}