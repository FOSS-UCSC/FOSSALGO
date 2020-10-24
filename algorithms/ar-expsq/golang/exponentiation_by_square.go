package main

import "fmt"

var mod = 1000000007

func main() {
	base := 5
	exponent := 10000000
	value := exponentiationBySquaring(base, exponent)
	fmt.Println(value)
}

func exponentiationBySquaring(base int, exponent int) int {
	if exponent == 0 {
		return 1
	} else if exponent == 1 {
		return base % mod
	}

	t := exponentiationBySquaring(base, exponent/2)
	t = (t * t) % mod

	// if exponent is even
	if exponent%2 == 0 {
		return t
	}

	//if exponent is odd
	return ((base % mod) * t) % mod
}
