#include<iostream>
#include<list>
#include<cmath>
using namespace std;
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void radixSort(int *arr, int n, int max) {

   list<int> pocket[10];      //radix of decimal number is 10
   for(int i = 0; i< max; i++) {
      int m = pow(10, i+1);
      int p = pow(10, i);
      for(int j = 0; j<n; j++) {
         int temp = arr[j]%m;
         int index = temp/p;      //find index for pocket array
         pocket[index].push_back(arr[j]);
      }
      int count = 0;
      for(int j = 0; j<10; j++) {
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}
int main() {
   int n, max;
   cout << "Enter the number of elements: ";
   cin >> n;
   cout << "Enter the maximum digit of elements: ";
   cin >> max;
   int arr[n]; //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Data before Sorting: ";
   display(arr, n);
   radixSort(arr, n, max);
   cout << "Data after Sorting: ";
   display(arr, n);
}
