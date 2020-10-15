#include<stdio.h>
//function for swapping 2 numbers
void swap(int *xp,int *yp)
{
    int temp;
    temp=*xp;
    *xp=*yp;
    *yp=temp;

}
//function for printing the array
void printArray(int arr[],int size)
{
    int i;
    printf("***Sorted array is**\n");
    for(i=0;i<size;i++)
    {

        printf("%d\n",arr[i]);
    }

    printf("\n");
}


//main logic for bubble sort
void bubble_sort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }

}


//the main driver code
int main()
{
    int i,arr[50],n;
    printf("Enter array size\n");
    scanf("%d",&n);
    printf("Enter array\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    bubble_sort(arr,n);//calling bubble_sort

    printArray(arr,n);//calling printArray
    printf("\nArray is sorted");
    return 0;

}
