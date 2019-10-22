#include <iostream>
using namespace std;

int binSearch(int arr[], int left, int right, int num) ;

int main(){ 
	int N,index,num;
	cout << "Enter Size of ARRAY : ";
	scanf("%d",&N);
	int i,arr[N];
	for (i=0;i<N;i++){
		cout << "Enter Element of index " << i << " : ";
		cin >> arr[i];
	}
	cout << "Enter the Number For Search :";
	cin >> num;
	index = binSearch(arr, 0, N - 1, num); 
	if (index==-1)
		cout << "There are no element called "<< num;
	else
		cout << "Element found! Index of " << num << " Is " << index;
	return 0; 
}

int binSearch(int arr[], int left, int right, int num){
	
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
