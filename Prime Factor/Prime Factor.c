#include <stdio.h>

int main()
{
    int i, j, num, flag;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime factors of %d are: \n", num);

	printf("[");
    for(i = 2; i <= num; i++)
    {
        if(num%i == 0)
        {
            flag = 1;
            for(j = 2; j <= i/2; j++)
            {
                if(i%j == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
            {
                printf("%d, ", i);
            }
        }
    }
    printf("\b\b]");

    return 0;
}
