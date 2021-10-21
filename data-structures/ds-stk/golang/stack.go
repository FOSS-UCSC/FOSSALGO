package main

import (
	"fmt"
)

//---Stack supports any type of elements-----

type stack struct {
	items [] interface{}
}

/*
Stack is a linear data structure. 
Follows Last in First Out (LIFO) principle.
1. init
2. Push
3. Pop
4. Size
5. Peek
6. isEmpty
7. print stack
*/

//---Initialize Stack-----
func initialize() stack{
	return stack{};
}

//---Pushing any type of element to Stack-----
func (s *stack) push(i interface{}){
	s.items = append(s.items, i)
}

//---Pop an element from Stack-----
func (s *stack) pop() interface{}{
	if(!s.isEmpty()){
		stackSize := len(s.items)-1
		poppedItem := s.items[stackSize]
		s.items = s.items[:stackSize]
		return poppedItem
	} 	
	fmt.Println("Stack is empty");
	return ""
}

//---Pop an element from Stack-----
func (s *stack) size() int {
	return len(s.items)
}

//---Peek an element in the Stack-----
func (s *stack) peek() interface{} {
	if(!s.isEmpty()){
		return s.items[len(s.items)-1]
		
	} 
	fmt.Println("Stack is empty");
	return ""
}

//Check the Stack is empty or not
func (s *stack) isEmpty() bool {
	return len(s.items) == 0
}

func main() {
	fmt.Println("Hello All, Stack Operation in GoLang")
	
	//Stack Initialize
	myStack := initialize();
	
	//Check stack is Empty before pushing element? 
	fmt.Println("IsEmpty", myStack.isEmpty())
	
	//Pushing any type of elements
	myStack.push(100);
	myStack.push(200);
	myStack.push("first");
	myStack.push(false);
	myStack.push(500);
	
	//Print Stack: After loaded with elements
	fmt.Println("Stack data: ", myStack)
	
	//printing size of stack
	fmt.Println("Size of the stack", myStack.size())
	
	//Peek an element
	fmt.Println("Peek element: ", myStack.peek())
	
	//Pop an element
	fmt.Println("Pop element: ", myStack.pop())
	
	//Check stack is Empty?
	fmt.Println("IsEmpty", myStack.isEmpty())
	
	//Print Stack
	fmt.Println("Stack data: ", myStack)
}
