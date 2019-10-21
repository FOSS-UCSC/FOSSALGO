#include<stdio.h>
void main()
{
	int num;
	printf("How many numbers are in the list : ");
	scanf("%d", &num);

    int ar[num],i;
    for (i=0;i<num;i++)
    {
        printf("Input number %d : ",i+1);
        scanf("%d", &ar[i]);
    }
    printf("\nOriginal List : ");
    for (i=0;i<num;i++)
        printf("%d ",ar[i]);

    int tmp,j,k;
    for (j=0;j<num;j++)
    {
        for (k=0;k<(num-1);++k)
        {
            if (ar[k]>ar[k+1])
            {
                tmp = ar[k];
                ar[k] = ar[k+1];
                ar[k+1] = tmp;
            }
        }
    }
    printf("\n\nSorted array in Ascending order: ");
    for (i=0;i<num;i++)
        printf("%d ", ar[i]);

    printf("\n\nSorted array in Descending order: ");
    for (i=(num-1);i>=0;i--)
        printf("%d ", ar[i]);
}
