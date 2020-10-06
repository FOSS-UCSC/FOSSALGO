package main

import "fmt"

// Merges the sorted halves of the array
func merge(l, r []int) []int {
	resLen := len(l) + len(r)
	res := make([]int, 0, resLen)

	for len(l) > 0 || len(r) > 0 {
		// If right array is completed, then append the left array to result
		if len(r) == 0 {
			return append(res, l...)
		}
		// If left array is completed, then append the right array to result
		if len(l) == 0 {
			return append(res, r...)
		}
		if r[0] >= l[0] {
			res = append(res, l[0])
			l = l[1:]
		} else {
			res = append(res, r[0])
			r = r[1:]
		}
	}
	return res
}

// MergeSort sorts an array using the merge sort algorithm
func MergeSort(arr []int) []int {
	n := len(arr)
	if n > 1 {
		mid := n / 2

		// Dividing the array from the midpoint
		l := arr[:mid]
		r := arr[mid:]
		l = MergeSort(l)
		r = MergeSort(r)

		// Merges and returns the two sorted sub arrays
		return merge(l, r)
	}
	return arr
}

func main() {
	testArr := []int{2, 4, 1, 12, 7, 0, 3, 14, 19, 11}
	fmt.Printf("%v\n%v\n", testArr, MergeSort(testArr))
}
