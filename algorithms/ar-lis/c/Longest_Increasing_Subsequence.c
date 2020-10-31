//https://www.geeksforgeeks.org/c-c-program-for-longest-increasing-subsequence/
//use binary search to reduce the complexity from N^2 to N(LOG(n)

#include <stdio.h>
#include <stdlib.h>

#define INT_INF 10000

int search_replace(int *lis, int left, int right, int key) {
        int mid;

        for (mid = (left+right)/2; left <= right; mid = (left+right)/2) {
                if (lis[mid] > key) {
                        right = mid - 1;
                } else if (lis[mid] == key) {
                        return mid;
                } else if (mid+1 <= right && lis[mid+1] >= key) {
                        lis[mid+1] = key;
                        return mid+1;
                } else {
                        left = mid + 1;
                }
        }
        if (mid == left) {
                lis[mid] = key;
                return mid;
        }
        lis[mid+1] = key;
        return mid+1;
}

int main(void) {
        int i, tmp, size = 7, lis_length = -1; 
        int *answer;
        int A[7] = {1,8,4,12,6,6,1},
            LIS[7],
            index[7] = {0};

        LIS[0] = A[0];
        for (i = 1; i < size; ++i) {
                LIS[i] = INT_INF;
        }

        for (i = 1; i < size; ++i) {
                index[i] = search_replace(LIS, 0, i, A[i]);
                if (lis_length < index[i]) {
                        lis_length = index[i];
                }
        }

        answer = (int*) malloc((lis_length+1) * sizeof(int));
        for (i = size-1, tmp = lis_length; i >= 0; --i) {
                if (index[i] == tmp) {
                        answer[tmp] = A[i];
                        --tmp;
                }
        }

        printf("LIS: ");
        for (i = 0; i < lis_length+1; ++i) {
                printf("%d ", answer[i]);
        }
        printf("\n");

        return 0;
}
