package main

import (
	"errors"
	"fmt"
)

type Queue struct {
	Elements []int
}

func (queue *Queue) Enqueue(element int) {
	queue.Elements = append(queue.Elements, element)
}

func (queue *Queue) Dequeue() (int, error) {
	if len(queue.Elements) == 0 {
		return 0, errors.New("empty queue")
	}
	var firstElement int
	firstElement, queue.Elements = queue.Elements[0], queue.Elements[1:]
	return firstElement, nil
}

func (queue *Queue) Peek() (int, error) {
	if queue.IsEmpty() {
		return 0, errors.New("empty queue")
	}
	return queue.Elements[0], nil
}

func (queue *Queue) IsEmpty() bool {
	return queue.Length() == 0
}

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
