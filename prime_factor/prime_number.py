def checkPrime(a):
    i = 0
    if(a<2):
        print(a," is not a prime!")
        return;
    elif(a==2):
        print(a, " is a Prime number!");
    else:
        # To check if the number is divisible by
        # any number other than 1 and itself
        for i in (2, a-1):
            
            if(a%i==0):
                print(a," is not a Prime number!");
                return;
            
        print(a, " is a Prime number!");



# Test data to check the function
checkPrime(0);
checkPrime(1);
checkPrime(2);
checkPrime(3);
checkPrime(10);
checkPrime(123);
