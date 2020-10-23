package main

import (
	"fmt"
	"math"
)

func largestSumContiguousSubarray(array []int) int {
	globalMax := math.MinInt32
	localMax := 0

	for _, num := range array {
		localMax += num

		if globalMax < localMax {
			globalMax = localMax
		}

		if localMax < 0 {
			localMax = 0
		}
	}

	return globalMax
}

func main() {
	array := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	largestSum := largestSumContiguousSubarray(array)
	fmt.Println(largestSum)
}
