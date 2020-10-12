package main

import "fmt"

// BubbleSort sorts an array by using an optimized version of the Bubble Sort algorithm
func BubbleSort(arr []int) {
	isSorted := false
	n := len(arr)

	for !isSorted {
		isSorted = true
		for i := 0; i < n-1; i++ {
			if arr[i+1] < arr[i] {
				temp := arr[i+1]
				arr[i+1] = arr[i]
				arr[i] = temp
				isSorted = false
			}
		}
	}

}

func main() {
	testArr := []int{2, 4, 1, 12, 7, 0, 3, 14, 19, 11}
	fmt.Printf("%v\n", testArr)
	BubbleSort(testArr)
	fmt.Printf("%v\n", testArr)
}
