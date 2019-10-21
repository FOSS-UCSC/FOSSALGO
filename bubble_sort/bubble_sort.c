#include<stdio.h>

void sawp(int *xp, int *yp);

void main()
{
	//int num;
	//printf("How many numbers are in the list : ");
	//scanf("%d", &num);

    int ar[5],i;
    for (i=0;i<5;i++)
    {
        printf("Input number %d : ",i+1);
        scanf("%d", &ar[i]);
    }
    printf("\nOriginal List : ");
    for (i=0;i<5;i++)
        printf("%d ",ar[i]);

    int tmp,j,k;
    for (j=0;j<5;j++)
    {
        for (k=0;k<4;++k)
        {
            if (ar[k]>ar[k+1])
            {
                swap(&ar[k],&ar[k+1]);
            }
        }
    }
    printf("\n\nSorted array : ");

    for (i=0;i<5;i++)
        printf("%d ", ar[i]);

}

void swap(int *xp, int *yp){
     int temp=*xp;
     *xp=*yp;
     *yp=temp;
}
