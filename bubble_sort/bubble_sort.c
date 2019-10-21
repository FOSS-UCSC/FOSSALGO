#include<stdio.h> 
 
//Bubble Sort Function 
void Sort(int arr[], int n) 
{ 
   int i, j; 
   for (i=0;i<n-1;i++)       
   	{
       for (j=0;j<n-i-1;j++)  
       	{
       		if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			} 
    	}
		    
	}
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
//Main Function
int main() 
{ 
    int n,i;
	printf("No of Elements: ");
	scanf("%d",&n);
	int arr[n]; 
    for(i=0;i<n;i++)
    {
    	printf("Input number %d :",i+1);
        scanf("%d", &arr[i]);	
	}
	
	printf("Original array: \n"); 
	for (i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
	}
    Sort(arr, n);    
    printf("\nSorted array: \n"); 
    for (i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
	}
	 
    return 0; 
}
