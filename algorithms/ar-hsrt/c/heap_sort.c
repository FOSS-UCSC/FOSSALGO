//Implementing HeapSort in C
#include <stdio.h>
#include <stdlib.h>

struct MaxHeap  {
    int size;
    int* array;
};

void swap(int* a, int* b) {
    int t = *a; *a = *b;  *b = t;
    }

void maxHeapify(struct MaxHeap* maxHeap, int i)
{
    int max = i;
    int left = (i << 1) + 1;
    int right = (i + 1) << 1;

    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[max])
        max = left;

    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[max])
        max = right;

    if (max != i) {
        swap(&maxHeap->array[max], &maxHeap->array[i]);
        maxHeapify(maxHeap, max);
    }
}

struct MaxHeap* HEAP(int *array, int size)    {
    int i;
    struct MaxHeap* maxHeap =
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;
    maxHeap->array = array;

    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);

    return maxHeap;
}

void heapSort(int* array, int size) {
    struct MaxHeap* maxHeap = HEAP(array, size);
    while (maxHeap->size > 1)
    {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;
        maxHeapify(maxHeap, 0);
    }
}

void printArray(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

int main()  {
    int arr[] = {92, 34, 23, 45, 69};
    int size = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, size);

    for(int i = 0; i < size; i++)   {
        printf("%d\n",arr[i]);
    }
    return 0;
}

