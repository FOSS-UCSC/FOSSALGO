# Merge Sort

## Introduction

Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.

## Algorithm

MergeSort(arr[], l,  r) <br>
If r > l <br>
&emsp;&emsp; 1. Find the middle point to divide the array into two halves:  <br>
&emsp;&emsp;&emsp;&emsp; middle m = l+ (r-l)/2 <br>
&emsp;&emsp; 2. Call mergeSort for first half: <br>
&emsp;&emsp;&emsp;&emsp; Call mergeSort(arr, l, m) <br>
&emsp;&emsp; 3. Call mergeSort for second half: <br>
&emsp;&emsp;&emsp;&emsp; Call mergeSort(arr, m+1, r) <br>
&emsp;&emsp; 4. Merge the two halves sorted in step 2 and 3: <br>
&emsp;&emsp;&emsp;&emsp; Call merge(arr, l, m, r) <br>

<br>[Learn more about Merge Sort Algorithm](https://www.geeksforgeeks.org/merge-sort/)

<br>![alt text](../../doc-assets/imgs/ar-msrt/merge-sort.png)

## Implementations

Below are some examples of how the Merge Sort Algorithm is implemented using different programming languages.


-   [C](https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/ar-msrt/c/merge_sort.c)
-   [CPP](https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/ar-msrt/cpp/merge_sort.cpp)
-   [Go](https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/ar-msrt/golang/merge_sort.go)
-   [Java](https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/ar-msrt/java/MergeSort.java)
-   [JavaScript](https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/ar-msrt/javascript/merge_sort.js)
-   [Python 3](https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/ar-msrt/python3/merge_sort.py)
