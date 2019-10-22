#include<stdio.h>
int main()
{
	int n;
	printf("How many numbers do you wish to input ");
	scanf("%d",&n);
    int ar[n],i;
    for (i=0;i<n;i++)
    {
        printf("Input number %d :",i+1);
        scanf("%d", &ar[i]);
    }
    printf("\nOriginal List : ");
    for (i=0;i<5;i++)
        printf("%d ",ar[i]);

    int tmp,j,k;
    for (j=0;j<5;j++)
    {
        for (k=0;k<5;k++)
        {
            if (ar[k]>ar[k+1])
            {
                tmp = ar[k];
                ar[k] = ar[k+1];
                ar[k+1] = tmp;
            }
        }
    }
    printf("\n\nSorted array  is :");

    for (i=0;i<5;i++)
        printf("%d ", ar[i]);

}

