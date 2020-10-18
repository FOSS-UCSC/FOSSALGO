def exponentiation_by_squaring(base, power):
    res = 1
    while(power > 0):
        if(power % 2 != 0):
            res *= base  #if power is ODD, multiply res with base
        base *= base   # square the base
        power = power // 2  # halving power (integer)
    return res

def main():
    print(exponentiation_by_squaring(5, 6))

if __name__ == "__main__":
    main()