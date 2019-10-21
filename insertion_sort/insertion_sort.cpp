//insertion sorting algorithm bt c++


#include<iostream>

using namespace std;

//swapping the elements
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
//sorting by insertion sort
void insertionSort(int arr[],int n){
	int i,j;
	for(i=1;i<n;i++){
		j=i;
		while(j>0 && arr[j-1]>arr[j]){
			swap(&arr[j],&arr[j-1]);
			j=j-1;
		}
	}
}


int main(){
	int a[] = { 12, 34, 8, 11, 89, 45, 27, 55};
	insertionSort(a,8);
	
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
}

