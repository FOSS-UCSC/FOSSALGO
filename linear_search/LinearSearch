#include <iostream>
using namespace std;
class LS
{
    public:
        void LinearSearch(int arr[], int value, int i, int n)
        {   int found = 0;
            for (i = 0; i < n ; i++)
            {
                if (value == arr[i] )
                {
                    found = 1;
                    break;
                }
            }
            if (found == 1)
            {
                cout<<"Element is present in the array at position   "<<i+1;
            }
            else
            {
                cout<<"Element is not present in the array.";
            }
        }
};
int  main()
{  int num;
    int i,  keynum, found = 0;
    cout<<"Enter the number of elements   ";
    cin>>num;
    int array[num];
    cout<<"Enter the elements one by one \n";
    for (i = 0; i < num; i++)
    {
        cin>> array[i];
    }
    cout<<"Enter the element to be searched   ";
    cin>>keynum;
    /*  Linear search begins */
    LS l1;
    l1.LinearSearch(array,keynum,i,num);
    return 0;
}
