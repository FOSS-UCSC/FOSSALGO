package main

import "log"

// linearSearch linearly scans arr to check for existence of num.
// If num exists then it returns the index of the first match.
// If the number does not exist it returns -1.
func linearSearch(arr []int, num int) int {
	for i, v := range arr {
		if v == num {
			return i
		}
	}

	return -1
}

// go run linear_search.go
func main() {
	log.Print(linearSearch(
		[]int{10, -1, 23, 454, 64, 124, 51},
		124,
	))
}
