// Quick Sort
#include<iostream>
using namespace std;

void quickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);
void printArr(int arr[], int length);

int main(){
	
	int arr[] = {4,5,6,8,7,2,9,1,5,3,6,4};
	int length = sizeof(arr)/sizeof(arr[1]);
	
	printArr(arr, length);
	quickSort(arr, 0, length-1);
	printArr(arr, length);
	
}

void quickSort(int arr[], int l, int r){
	if(l<r){
		int pivot = partition(arr, l, r);
	
		quickSort(arr, l, pivot-1);
		quickSort(arr, pivot+1, r);
	}
	
}

int partition(int arr[], int l, int r){
	int pivot = arr[r];
	
	int i=l-1;
	for(int j=l; j<r; j++){
		if(pivot>arr[j]){
			i++;
			int temp1 = arr[i];
			arr[i] = arr[j];
			arr[j] = temp1;
		}
	}
	int temp2 = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp2;
	
	return i+1;
}

void printArr(int arr[], int length){
	for(int i=0; i<length; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
