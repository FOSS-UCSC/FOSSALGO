#include<stdio.h>
void main()
{
    int ar[5],i;
    for (i=0;i<5;i++)
    {
        printf("Input number %d :",i+1);
        scanf("%d", &ar[i]);
    }
    printf("\nOriginal List : ");
    for (i=0;i<5;i++)
        printf("%d ",ar[i]);

    int tmp,j,k;
    for (j=0;j<4;j++)
    {
        for (k=0;k<4-j;k++)
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

    for (i=0;i<5;i++)
        printf("%d ", ar[i]);
}


