#include<stdio.h>
void main()
{
	int n=1;
	printf("Enter the numeber of items in the list:");
        scanf("%d", &n);
    int ar[n],i;
    for (i=0;i<n;i++)
    {
        printf("Input number %d :",i+1);
        scanf("%d", &ar[i]);
    }
    printf("\nOriginal List : ");
    for (i=0;i<n;i++)
        printf("%d ",ar[i]);

    int tmp,j,k;
    for (j=0;j<n;j++)
    {
        for (k=0;k<n-1;k++)
        {
            if (ar[k]>ar[k+1])
            {
                tmp = ar[k];
                ar[k] = ar[k+1];
                ar[k+1] = tmp;
            }
        }
    }
    printf("\n\nSorted array :");

    for (i=0;i<n;i++)
        printf("%d ", ar[i]);

}


