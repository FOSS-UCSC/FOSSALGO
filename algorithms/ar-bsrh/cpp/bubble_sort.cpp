#include <iostream>
using namespace std;

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

void bubbleSort(int arr[], int n) {
	bool swapped;
	for (int i = 0; i < n-1; i++) {
		swapped = false;
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements space separated: ";
    for(int& i : arr) {
        cin >> i;
    }
    bubbleSort(arr, (sizeof(arr) / sizeof(arr[0])));

	cout << "Array after sorting is: ";
	for(int i : arr) {
		cout << i << ' ';
	}
	cout << '\n';
    return 0;
}
