def primefactor(arr):
    if arr<=0:
        return
    
    while arr%2==0:
        print(2)
        arr/=2

    for i in range(3, int(arr*arr)+1,2):

        while arr%i==0:
            print(i)
            arr/=i

    if arr>2:
        print(int(arr))


def main():
    primefactor(140)

    
if __name__ == '__main__':
    main()