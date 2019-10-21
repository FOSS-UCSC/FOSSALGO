/*  BINARY SEARCH
    function for carrying out binary search on given array
    - values[] => given sorted array
    - len => length of the array
    - target => value to be searched
*/
int binarySearch(int values[], int len, int target)
{
    int max = (len - 1);
    int min = 0;
    
    int guess;  // this will hold the index of middle elements
    int step = 0;  // to find out in how many steps we completed the search
    
    while(max >= min)
    {
        guess = (max + min) / 2;
        // we made the first guess, incrementing step by 1
        step++;
        
        if(values[guess] ==  target)
        {
            printf("Number of steps required for search: %d \n", step);
            return guess;
        }
        else if(values[guess] >  target) 
        {
            // target would be in the left half
            max = (guess - 1);
        }
        else
        {
            // target would be in the right half
            min = (guess + 1);
        }
    }
 
    // We reach here when element is not 
    // present in array
    return -1;
}
 
int main(void)
{
    int values[] = {13, 21, 54, 81, 90};
    int n = sizeof(values) / sizeof(values[0]);
    int target = 81;
    int result = binarySearch(values, n, target);
    if(result == -1)
    {  
        printf("Element is not present in the given array.");
    }
    else
    {
        printf("Element is present at index: %d", result);
    }
    return 0;
//}
