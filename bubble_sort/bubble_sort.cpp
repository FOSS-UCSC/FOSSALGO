#include <iostream>
using namespace std;

int main(){
	int N, i, j, val;
	cout << "Size of array = ";
	cin >> N;
	int arr[N];
	for(i=0; i<N; i++){
		cin >> arr[i];
	}

    for (i=0; i<N; i++)
    {
        for (j=0; j<N-1; ++j)
        {
            if (arr[j]>arr[j+1])
            {
                val = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = val;
            }
        }
    }	
	for(i=0; i<N; i++){
		cout << " " << arr[i];
	}	
	return 0;
}
