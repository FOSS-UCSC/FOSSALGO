#include <iostream>
using namespace std;

void sort(int array[], int size=10){
    int i,j,temp;
    for(i=0; i<9; i++){
        for (j = 0; j < 10-i-1; j++){
            if(array[j]>array[j+1]){
                temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
    }

    cout << "\n" << "Sorted list  :";
    for(i=0; i<10; i++)
        cout << " " << array[i];


}

int main(){
    int array[10], i;
    for(i=10; i>0; i--){
    cout << "Input number :\"You have " << i << " numbers remaining!\"" << endl;
    cin >> array[10-i];
}

    cout << "\n" << "Original list:";
    for(i=0; i<10; i++)
        cout << " " << array[i];

    sort(array);
}
