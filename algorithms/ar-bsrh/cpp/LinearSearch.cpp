#include <iostream>
using namespace std;

bool linearSearch(int arr[], int x, int n) {
    for(int i = 0; i < n; ++i) {
        if(arr[i] == x) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, x, q;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements space separated: ";
    for(int& i : arr) {
        cin >> i;
    }
    
    cout << "Enter number of queries you want: ";
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cout << "Enter a number to search in array: ";
        cin >> x;
        if(linearSearch(arr, x, n)) {
            cout << x << " is present in the array.\n";
        }else {
            cout << x << " is not present in the array.\n";
        }
    }
    return 0;
}
