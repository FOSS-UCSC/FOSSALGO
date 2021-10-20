package main

import (
	"fmt"
)

//---Stack supports any type of elements-----

type StackGo struct {
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
func initialize() StackGo{
	return StackGo{};
}

//---Pushing any type of element to Stack-----
func (s *StackGo) push(i interface{}){
	s.items = append(s.items, i)
}

//---Pop an element from Stack-----
func (s *StackGo) pop() interface{}{
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
func (s *StackGo) size() int {
	return len(s.items)
}

//---Peek an element in the Stack-----
func (s *StackGo) peek() interface{} {
	if(!s.isEmpty()){
		return s.items[len(s.items)-1]
		
	} 
	fmt.Println("Stack is empty");
	return ""
}

//Check the Stack is empty or not
func (s *StackGo) isEmpty() bool {
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
