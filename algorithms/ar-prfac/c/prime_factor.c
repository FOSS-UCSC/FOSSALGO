#include <stdio.h>

void primeNumbers(int num) {
    int i, j, isPrime;
    
     for(i=2; i<=num; i++)
    {
        if(num%i==0)
        {
            isPrime = 1;
            for(j=2; j<=i/2; j++)
            {
                if(i%j==0)
                {
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime==1)
            {
                printf("%d, ", i);
            }
        }
    }
}

int main()
{
    int num;

    printf("Enter any number to print Prime factors: ");
    scanf("%d", &num);

    printf("All Prime Factors of %d are: \n", num);
    primeNumbers(num);

    return 0;
}
