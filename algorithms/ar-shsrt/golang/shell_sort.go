package main

import "fmt"

func main() {
	list := []int{100, -80, 70, -60, 50, -40, 30, -20, 10, 0}
	fmt.Println("Original list:", list)
	shellSort(list)
	fmt.Println("Sorted list: ", list)
}

func shellSort(list []int) {
	for inc := len(list) / 2; inc > 0; inc = (inc + 1) * 5 / 11 {
		for i := inc; i < len(list); i++ {
			j, k := i, list[i]
			for ; j >= inc && list[j-inc] > k; j -= inc {
				list[j] = list[j-inc]
			}
			list[j] = k
		}
	}
}
