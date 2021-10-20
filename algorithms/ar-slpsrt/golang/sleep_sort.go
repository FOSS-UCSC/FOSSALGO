package main

import (
	"fmt"
	"time"
)

func main() {
	list := []uint{90, 10, 80, 20, 70, 30, 60, 40, 50}
	fmt.Println("Original list:", list)
	sortedList := sleepSort(list)
	fmt.Println("Sorted list: ", sortedList)
}

func sleepSort(list []uint) []uint {
	sortedList := []uint{}
	out := make(chan uint)
	for _, i := range list {
		go func(n uint) {
			time.Sleep(time.Duration(n) * time.Millisecond)
			out <- n
		}(i)
	}
	for range list {
		sortedList = append(sortedList, <-out)
	}
	return (sortedList)
}
