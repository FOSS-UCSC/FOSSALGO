#include <stdio.h>

void sort(int arr[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(arr[j]>=arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int binarySearch(int arr[],int low,int high,int searchVal){
	if(low>high){
		printf("Search is finished. Value not found\n");
		return -1;
	}
	int mid=(low+high)/2;
	if(searchVal==arr[mid]){
		printf("Search is finished. Index is %d\n",mid);
		return mid;
	}else if(searchVal>=arr[mid]){
		low=mid+1;
		return binarySearch(arr,low,high,searchVal);
	}else{
		high=mid-1;
		return binarySearch(arr,low,high,searchVal);
	}
}

int main(){
	int n=8,low=0;
	int arr[]={4,5,1,10,2,7,6,3};
	sort(arr,n);
	binarySearch(arr,low,n-1,7);
	binarySearch(arr,low,n-1,8);
	return 0;
}
