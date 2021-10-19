package main

import (
	"errors"
	"fmt"
)

// Queue:
// front -> [1]->[2] -> [3] -> [4] -> Rear
// Element always dequeued from front and enqueued at rear.

// Queue follow first in first out rule which is also called
// (FIFO), It simply means element who enqueued in queue will
// be dequeued first.
type Queue struct {
	Elements []int
}

// Enqueue function implementation of Queue to add new Element at end Queue
// of type int and return nil.
func (queue *Queue) Enqueue(element int) {
	queue.Elements = append(queue.Elements, element)
}

// Dequeue function implementation of Queue to remove element from
// front and return nil or int
func (queue *Queue) Dequeue() (int, error) {
	if len(queue.Elements) == 0 {
		return 0, errors.New("empty queue")
	}
	var firstElement int
	firstElement, queue.Elements = queue.Elements[0], queue.Elements[1:]
	return firstElement, nil
}
// Peek function return element at front in queue.
func (queue *Queue) Peek() (int, error) {
	if queue.IsEmpty() {
		return 0, errors.New("empty queue")
	}
	return queue.Elements[0], nil
}
// IsEmpty it is a utility method to validate the length of elements in queue.
// Always return a bool value of true or false.
func (queue *Queue) IsEmpty() bool {
	return queue.Length() == 0
}
// Length It is a utility method always returns a int in queue. which is the length of
// elements in Queue.
func (queue *Queue) Length() int {
	return len(queue.Elements)
}

func main() {
	queue := Queue{}
	queue.Enqueue(20)
	queue.Enqueue(300)
	queue.Enqueue(30)
	fmt.Println(queue)

	element, _ := queue.Dequeue()
	fmt.Println("Remove element: ", element)
	fmt.Println(queue)
}
