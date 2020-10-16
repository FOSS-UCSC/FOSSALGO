#include <stdio.h>

int cont = 0;

void coin(int n, int i, int sum, int *arr, int len){

    sum += *(arr + i); //sums the number of the index i to the last value in sum

    //if the sum is higher then the number n, then stops to check with this number in index i
    if(sum > n){
        return;
    }

    //if the sum is equal to the number n, then it increments the counter and returns
    //because if he continues to increment the sum with this number, it will stop in the
    //first stop condition
    if(sum == n){
        cont++;
        return;
    }

    //loops through the array and uses recursion to increment the variable sum with arr[k]
    //example: arr[1,2,3], i = 0, n = 2, sum = 0
    //- enters in coin function with k = 0, n = 2 and sum = 0
    //- sum = 1, because its sum += arr[0]
    //- the stop conditions are false, because sum < n
    //- tries again with k = 0
    //- sum = 2, because its sum += arr[0] and the sum had the value 1
    //- stops in the second condition
    //- try with k = 1 because its still inside the loop (k = 1 and k = 2 will not work, because sum is 1
    // and arr[1] = 2 and arr[2] = 3)
    int k;
    for(k = i; k < len; k++){
        coin(n, k, sum, arr, len);
    }
}

int main() {

    //with n = 8 and the array with numbers [2,3,6] the result must be 3
    //because 8=2+2+2+2, 8=2+3+3, 8=2+6
    int n = 8, i, sum = 0;
    int arr[] = {6,2,3};
    int len = sizeof(arr) / sizeof(int);

    //repeats the process describe above with all the numbers of the array
    for(i = 0; i < len; i++){
        coin(n, i, sum, arr, len);
    }

    printf("Number of combinations: %d", cont);

    return 0;
}
