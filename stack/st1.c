 
push() - This Function used to insert an element into a stack. ?     
pop() - This Function used to delete an element from a stack ?     
isEmpty() - This Function used to find the stack is empty or not. ?     
isFull() -  This Function used to find the stack is full or not. ?     
getSize() -This Function used to get the size of the stack. ?
outPut() - This Function used to print the element of the stack */

#include<stdio.h>
int a,b;
int arr[100], top = -1, val;
int push(), pop(), isEmpty(),isFull(), getSize(), outPut();
int main(){
	printf("enter the size of the array based stack : ");
	scanf("%d",&a);
	while(1){
	
		printf("\nenter the function: \n1.push\n2.pop\n3.isEmpty\n4.isFull\n5.getSize\n6.outPut\n :");
		scanf("%d",&b);
		
		switch(b){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				printf("%d",isEmpty());
				break;
			case 4:
				printf("%d",isFull());
				break;
			case 5:
				getSize();
				break;
			case 6:
				outPut();
				break;
		}
	}	
}
int isFull(){
	if(top != a-1) return 0;
	else return 1;
}
int isEmpty(){
	if(top != -1) return 0;
	else return 1;
}
int push(){
	if(isFull()) {
	printf("\nstack is full\n");
	}
	else{
		printf("\nenter value to push: ");
		scanf("%d",&val);
		top++;
		arr[top]= val;
	}
}
int pop(){
	if(isEmpty()) {
	printf("stack is empty\n");
	}
	else{
		printf("pop value is: %d",arr[top]);
		top--;
	}
}
int getSize(){
	printf("stack size %d of %d\n",top+1,a);
}
int outPut(){
	int i;
	for(i=0;i<top+1;i++){
		printf(" %d ",arr[i]);
	}
}

