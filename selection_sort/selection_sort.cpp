#include<iostream>

using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selectionSort(int arr[],int n){
	int min;
	for(int k=0; k<n-1;k++){
		min =k;
		for(int j=k+1;j<n;j++){
			if(arr[j]<arr[min]){
				min =j;
			}
		}
		swap(&arr[min],&arr[k]);
	}
}


int main(){
	int a[] = { 12, 34, 8, 11, 89, 45, 27, 55};
	selectionSort(a,8);
	
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
}



