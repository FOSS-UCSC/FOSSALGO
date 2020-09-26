package main

import (
	"fmt"
)

type node struct
{
 data int
 left *node
 right *node
}

var root *node = nil

func insert(d int){

	if root==nil {
		root = new(node)
		root.data=d
		root.left=nil
		root.right=nil
	}else{
		q := root
		p := new(node)
		p.data=d
		p.left=nil
		p.right=nil
		for ; ;{
			if p.data<q.data {
			   if q.left==nil{
				q.left=p
				break;
			    }else{
				  q=q.left
				}
			}
			
			if p.data>=q.data{
			     if q.right==nil{
			         q.right=p
				 break;
				}else{
				   q=q.right;
				}
			}
		}
	}
}

func preorder(q *node){
	
	if q!=nil{
		fmt.Println(q.data)
		preorder(q.left)
		preorder(q.right)
	}
	
}

func inorder(q *node){
	
	if q!=nil{
		inorder(q.left)
		fmt.Println(q.data)
		inorder(q.right)
	}
	
}

func postorder(q *node){
	
	if q!=nil{
		postorder(q.left)
		postorder(q.right)
		fmt.Println(q.data)
	}
	
}

func main() {
	insert(10)
	insert(8)
	insert(12)
	insert(7)
	insert(9)
	insert(11)
	insert(13)
	
	fmt.Println("Pre-Order: ")
	preorder(root)
	fmt.Println("-----------------------")
	fmt.Println("In-Order: ")
	inorder(root)
	fmt.Println("----------------------")
	fmt.Println("Post-Order: ")
	postorder(root)

}