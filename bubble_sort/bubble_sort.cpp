#include<iostream>

using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubbleSort(int arr[],int n){
	bool swapped;
	for(int i=0;i<n-1;i++){
		swapped = false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				swapped = true;
			}
		}
		if(swapped = false)
			break;
	}
}


int main(){
	int a[] = { 12, 34, 8, 11, 89, 45, 27, 55};
	bubbleSort(a,8);
	
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
}
