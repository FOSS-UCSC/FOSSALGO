#include <stdio.h>
int main()
{
int i, low, high, n, key, array[100];

printf("Enter number of elements: ");
scanf("%d",&n);
printf("Enter %d integers:", n);
for(i = 0; i < n; i++)
scanf("%d",&array[i]);
printf("Enter value to find: ");
scanf("%d", &key);
low = 0;
high = n - 1;
int mid = (low+high)/2;
while (low <= high)
 {
    if(array[mid] < key)
    {
    low = mid + 1;
    }
    else if (array[mid] == key) 
    {
    printf("Element Found! \n%d is present at location %d", key, mid+1);
    break;
    }
    else
    {
    high = mid - 1;
    mid = (low + high)/2;
    }
}
if(low > high)
{
    printf("Element Not Found! \n%d isn't present in the list", key);
}
return 0;
}
