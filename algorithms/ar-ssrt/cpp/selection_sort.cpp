// Selection Sort
#include<iostream>
using namespace std;

void printArr(int arr[], int length);
void sortArr(int arr[], int length);

int main(){
	int length;
	int arr[] = {5,6,8,9,7,4,6,2,1,3,1,8,9};
	length = sizeof(arr)/sizeof(arr[1]);
	
	printArr(arr, length);
	sortArr(arr, length);
	printArr(arr, length);
	
}

void sortArr(int arr[], int length){
	for(int i=0; i<length-1; i++){
		int index = i;
		for(int j=i; j<length; j++){
			if(arr[j]<arr[index]){
				index = j;
			}
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
}

void printArr(int arr[], int length){
	for(int i=0; i<length; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
