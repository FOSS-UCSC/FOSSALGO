package main

import (
	"fmt"
	"math"
)

func change(T []int, N int) []int {
	S := make([]int, N+1)
	C := make([]int, N+1)
	C[0] = 0
	for m := 1; m <= N; m++ {
		C[m] = math.MaxInt32
		for j := 0; j < len(T); j++ {
			if m >= T[j] && C[m-T[j]]+1 < C[m] {
				C[m] = C[m-T[j]] + 1
				S[m] = j + 1
			}
		}
	}

	return S
}

func printChange(T []int, N int) {
	S := change(T, N)

	for N > 0 {
		fmt.Println(T[S[N]-1])
		N = N - T[S[N]-1]
	}
}

func main() {
	T := []int{1, 2, 3}
	N := 4
	printChange(T, N)
}
