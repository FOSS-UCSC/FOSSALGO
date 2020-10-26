// C++ program for implementation of linear search.
#include <iostream>

using namespace std;

int linear_search(int array[], int size, int key)
{
    for(int i = 0; i < size; i++)
    {
        if(key == array[i])
        {
            // return it's location
            return i;
        }
    }
    // return -1 if key is not found
    return -1;


}

int main()
{
    // created an array with size 6.
    int array[] = {4, 13, 25, 32, 68, 94};
    int key;
    cout << "Enter a key" << endl;
    cin >> key;

    int result = linear_search(array, 6, key);

    if(result >= 0)
    {
        cout << "The number " << array[result] << " is found at the  index " << result << endl;
    }
    else
    {
      cout << "The key " << key << " is not found." << endl;
    }

}
