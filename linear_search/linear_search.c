#include<stdio.h>

int linearSearch(int a[],int n,int x){
	
	int i;
    for (i = 0; i < n; i++){
            if (a[i] == x)
                return i;
        
	}
        return -1;
}

int main(){
	
	int i,key,n;
	
	printf("Enter number of elements in array: ");
	scanf("%d",&n);
	
	int array[n]; //array has 10 elements
	printf("Enter %d elements in array: \n",n);
	
	for(i=0;i<n;i++){
		scanf("%d",&array[i]); // get elements one by one
	}
	
	printf("Enter element to find:");
	scanf("%d",&key);
	int result=linearSearch(array,n,key);
	
	if(result==-1){
		printf("Element is not present in array");
	}
	else{
		printf("Element is present at index %d",result);
	}
	return 0;
}
