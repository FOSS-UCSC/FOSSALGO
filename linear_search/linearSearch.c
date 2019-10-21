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
