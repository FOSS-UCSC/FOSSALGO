#include<iostream>
using namespace std;
// Merge two subarrays L and R into arr
void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and R ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];
    //copying data to these subarrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i=0;//cuurent index for subarray L
    int j=0;//cuurent index for subarray R
    int k=p;//cuurent index for main array

    // Until we reach either r of either L or R, pick larger among
    // elements L and R and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or R,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/*  l and r are starting and last index of the current array/subarray 
on which the mergeSort function is called  */
int* mergeSort(int arr[], int l, int r) {
    //we repeatedly divide array until when we call function mergeSort on subarray of size l=r
	if(l < r) {
        //mid is where we divide array in two sub arrays
        //we can use mid=l+((r-l)/2) to avoid overflow
		int mid = (l + r) / 2;

		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);
		//merge the sorted arrays
        //
        merge(arr, l, mid, r);
	}
	return arr;
}
int main(){
	int array[]={60,20,75,100,5,45};
	int n = sizeof(array)/sizeof(array[0]);
	cout<<n<<endl;
	int *sortedArr=mergeSort(array,0, n-1);
	for (int i=0;i<n;i++) {
    cout<<sortedArr[i]<<" ";
    }
    cout<<endl;
    return 0;
}