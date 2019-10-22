#include<stdio.h>

int main()
{	
	int N, i, j, k;
	printf("Number of elements in list : ");
	scanf("%d", &N);
	
	int list[N];
	printf("Enter the values in list : ");
	for(i=0; i<N; i++){
		scanf("%d", &list[i]);
	}
    
    int min;
    for(j=0; j<N-1; j++){
    	min=j;
	    for(i=j+1; i<N; i++){
			if(list[min]>list[i]){
    			min=i;
			}   	
		}
		int val;
		val=list[min];
		list[min]=list[j];
		list[j]=val;
	}
	
	for(i=0; i<N; i++){
		printf("%d ", list[i]);
	}	
	
    return 0;
}
