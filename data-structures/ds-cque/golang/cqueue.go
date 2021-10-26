package main

import (
	"fmt"
)

/*
Circular Queue is a linear data structure.
Follows First in First Out (FIFO) principle.
Last Position is connected to First Position
1. initialize
2. enqueue
3. dequeue
4. isEmpty
5. isFull
6. queue size
*/

type circularQ struct {
	data     []interface{}
	capacity int
	front    int
	rear     int
}

//---Initialize Circular Queue-----
func initialize(c int) *circularQ {

	if c <= 0 {
		return nil
	} else {
		return &circularQ{data: make([]interface{}, c), capacity: c, front: 0, rear: 0}
	}
}

//---Enqueue an element into Circular Queue-----
func (cq *circularQ) enqueue(item interface{}) bool {

	if cq.isFull() {
		return false
	} else {
		cq.data[cq.rear] = item
		cq.rear = (cq.rear + 1) % cq.capacity
		return true
	}

}

//---Dequeue an element from Circular Queue-----
func (cq *circularQ) dequeue() interface{} {

	if cq.isEmpty() {
		return nil
	} else {
		item := cq.data[cq.front]
		cq.data[cq.front] = nil
		cq.front = (cq.front + 1) % cq.capacity
		return item
	}
}

//---IsEmpty check for Circular Queue-----
func (cq *circularQ) isEmpty() bool {

	if cq.front == cq.rear {
		return true
	}
	return false
}

// IsFull check for Circular Queue
func (cq *circularQ) isFull() bool {
	if cq.front == (cq.rear+1)%cq.capacity {
		return true
	}
	return false
}

//---Size of the Circular Queue-----
func (cq *circularQ) cQueueSize() int {

	return (cq.rear - cq.front + cq.capacity) % cq.capacity
}

func main() {

	//Initialize the circular queue
	myCQ := initialize(5)

	//Size, isEmpty
	fmt.Println("Circluar Queue  Size = ", myCQ.cQueueSize())

	fmt.Println("Circluar Queue IsFull? ", myCQ.isFull())

	//Pushing elements to circular Queue
	myCQ.enqueue(100)
	myCQ.enqueue("first")
	myCQ.enqueue("second")
	myCQ.enqueue(true)

	fmt.Println(myCQ)

	//Dequeuing elements from circular Queue
	fmt.Println("Dequeued Item:", myCQ.dequeue())
	fmt.Println("Dequeued Item:", myCQ.dequeue())

	fmt.Println(myCQ)

	// Is empty
	fmt.Println("Circluar Queue IsEmpty? ", myCQ.isEmpty())

}
