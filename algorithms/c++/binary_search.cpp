#include <iostream>
#include<conio.h>
#include<stdlib.h>

#define MAX_SIZE 5

using namespace std;

int main()
{
    int arr_search[MAX_SIZE], i, element;
    int f = 0, r = MAX_SIZE, mid;

    cout << "Simple C++ Binary Search Example - Array\n";
    cout << "\nEnter " << MAX_SIZE << " Elements for Searching : " << endl;
    for (i = 0; i < MAX_SIZE; i++)
        cin >> arr_search[i];

    cout << "\nYour Data   :";
    for (i = 0; i < MAX_SIZE; i++) {
        cout << "\t" << arr_search[i];
 }

    cout << "\nEnter Element to Search : ";
    cin>>element;


    while (f <= r) {
        mid = (f + r) / 2;

        if (arr_search[mid] == element) {
            cout << "\nSearch Element  : " << element << " : Found :  Position : " << mid + 1 << ".\n";
            break;
        } else if (arr_search[mid] < element)
            f = mid + 1;
        else
            r = mid - 1;
    }

    if (f > r)
        cout << "\nSearch Element : " << element << "  : Not Found \n";

    getch();
}
