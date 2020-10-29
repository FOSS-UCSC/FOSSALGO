#include<iostream>
using namespace std;

int* insertionSort(int arr[], int n){
	int position,valueToInsert;
	for(int i=1;i<n;i++){
		valueToInsert=arr[i];
		position=i;
		while(position>0&&arr[position-1]>valueToInsert){
			arr[position]=arr[position-1];
			position=position-1;
		}
		arr[position]=valueToInsert;
	}
	return arr;
}
int main(){
	int array[]={60,20,75,100,5,45};
	int n = sizeof(array)/sizeof(array[0]);
	cout<<n<<endl;
	int *sortedArr=insertionSort(array, n);
	for (int i=0;i<n;i++) {
    cout<<sortedArr[i]<<" ";
    }
    cout<<endl;
    return 0;
}