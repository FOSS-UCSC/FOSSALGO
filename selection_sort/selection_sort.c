#include<stdio.h>
#include<stdlib.h>

//For pre-hacktoberfest under SAG4X team

void swap(int *x, int *y) //swap function using pointers
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

void selection_sort(int array[],int size);

int main(){
	
	int i;
	int a[]={1,88,2,56,56,5,56,2,5,65,8}; //sample array
	int n = sizeof(a)/sizeof(a[0]); //get number of elements
	
	printf("Original array:\n ");
	for(i=0;i<n-1;i++){
    	printf("%d ", a[i]); //print original array
	}
	printf("\n");
	
    selection_sort(a,n);
    
    printf("Array sorted using selection sort:\n ");
    for(i=0;i<n-1;i++){
    	printf("%d ", a[i]);
	}
	printf("\n");
	
}

void selection_sort(int array[],int size){
	
	int i,j, min;
	for(i=0;i<size-1;i++){
		min= i; 
        for(j =i+1;j<size;j++){
		
          if(array[j] < array[min]){
		  	min=j;
		  }        
  		}
        // Swap minimum element with 1st element 
        swap(&array[min],&array[i]);
	}
}
