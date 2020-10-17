def exponentiationSquaring(base, power):
    result = 1
    while(power > 0):
        if power % 2 != 0:  # if power is ODD multiply result by base
            result = (result * base)

        base = base * base  # squaring base
        power /= 2  # half the power

    return result


def main():
    power = 3
    base = 5
    result = exponentiationSquaring(base, power)
    print(result)


if __name__ == '__main__':
    main()
