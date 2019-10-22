#include <stdio.h> 
/**********************/
/*Binary Sreach In C */
/**********************/
int binSearch(int arr[], int left, int right, int num) ;

int main(void) 
{ 
	int N,index,num;
	printf("Enter Size of ARRAY : ");
	scanf("%d",&N);
	int i,arr[N];
	for (i=0;i<N;i++){
		printf("Enter %d Element:",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter the Number For Search :");
	scanf("%d",&num);
	index = binSearch(arr, 0, N - 1, num); 
	if (index==-1){
		printf("There are no element called %d",num);
	}
	else{
		printf("Element found.Index of %d num : %d ",num,index);
	}
	return 0; 
}
/* binary SEARCH FUNCTION */
int binSearch(int arr[], int left, int right, int num)
{ 
	while (left <= right) { 
		int mid = left + (right - left) / 2; 
		if (arr[mid] == num) 
			return mid; 
		if (arr[mid] < num) 
			left = mid + 1; 
		else
			right = mid - 1; 
	} 

	return -1; 
} 
