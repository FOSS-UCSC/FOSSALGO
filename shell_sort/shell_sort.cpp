#include <iostream>

using namespace std;

void printArray(int arr[], int n);
int shellSort(int arr[], int n);

int main()
{
    int sizeArr;
    cout<<"Enter Array Size:"<<endl;
    cin>>sizeArr;
    int arr[sizeArr];

    for(int i=0;i<sizeArr;i++)
    {
        cout<<"Enter Value for array["<<i<<"]"<<endl;
        cin>>arr[i];

    }


    shellSort(arr, sizeArr);
    cout<<"Array after sorting:"<<endl;
    printArray(arr, sizeArr);
    return 0;
}


void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout<<arr[i]<<endl;
}

int shellSort(int arr[], int n)
{

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}
