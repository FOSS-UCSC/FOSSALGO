#include <stdio.h>
   
int search(int arr[], int n, int searchElement){
	int i;
    for (i = 0; i < n; i++){
	    if (arr[i] == searchElement){
	    	return i;
		}
	}
    return -1;
}


void main(){
	int n;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	int i;
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int searchElement;
	printf("Enter number to search : ");
	scanf("%d",&searchElement);
	printf("%d",search(arr,n,searchElement));
}
