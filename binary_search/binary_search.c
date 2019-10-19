#include<stdio.h>

int binarySearch(int a[],int left,int right,int x){   
	while (left <= right) { 
        int mid = left + (right - left) / 2; 
  
        // Check if x is the mid value
        if (a[mid] == x) 
            return mid;	 
  
        // If x is greater, ignore the left part 
        if (a[mid] < x) 
            left = mid + 1; 
  
        // If x is smaller, ignore the right pRT 
        else
            right = mid - 1; 
    } 
  
    // if element is not present return -1
    return -1; 
}

int main(){
	
	int key,i; 
	int array[10]; //array has 10 elements
	printf("Enter 10 elements in array: ");
	
	for(i=0;i<10;i++){
		scanf("%d",&array[i]); // get elements one by one
	}
	
	printf("Enter element to find:");
	scanf("%d",&key);
	int result=binarySearch(array,0,9,key);
	
	if(result==-1){
		printf("Element is not present in array");
	}
	else{
		printf("Element is present at index %d",result);
	}
	return 0;
	
}
