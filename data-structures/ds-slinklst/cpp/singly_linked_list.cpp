// Linked List
#include<iostream>
using namespace std;

struct node{
	int val;
	node *next;
};

void addNode(node **h);
void printList(node *h);
void appendNode(node *&h, int loc, int value);
void editNode(node *&h, int loc, int value);
void deleteNode(node *&h, int loc);
void deleteList(node *&h);
int printChoices();
void handleChoices(int ch);

int main(){
	int choice = 0;
	
	node *head = NULL;
//	choice = printChoices();
	
	while(choice!=6){
		int loc, num;
		switch(choice){
			case 1:
				addNode(&head);
				break;
			case 2:
				cout<<"Enter the location : ";
				cin>>loc;
				cout<<"Enter the number : ";
				cin>>num;
				appendNode(head, loc, num);
				break;
			case 3:
				cout<<"Enter the location : ";
				cin>>loc;
				cout<<"Enter the number : ";
				cin>>num;
				editNode(head, loc, num);
				break;
			case 4:
				cout<<"Enter location of the deleting number : ";
				cin>>loc;
				deleteNode(head, loc);
				break;
			case 5:
				printList(head);
				break;
						
		}
		choice = printChoices();
	}
	
	
	
	
	addNode(&head);
	appendNode(head, 1, 8);
	appendNode(head, 2, 1);
	printList(head);
	editNode(head, 1, 9);
	printList(head);
	editNode(head, 3, 9);
	printList(head);
	deleteNode(head, 2);
	printList(head);
	deleteList(head);
	printList(head);
	addNode(&head);
	printList(head);
	addNode(&head);
	printList(head);
}


int printChoices(){
	int ch;
	cout<<"\n###### Choices ######"<<endl;
	cout<<"Enter 1 to add a number\nEnter 2 to add number in specific location\nEnter 3 to edit number\nEnter 4 to delete a number\nEnter 5 to print the list\nEnter 6 to end process\n\nEnter your choice here - ";
	cin>>ch;
	return ch;
}

void deleteList(node *&h){
	node *prev = h;
	while(prev!=NULL){
		h = prev->next;
		delete prev;
		prev = h;
	}
	delete prev;
}

void deleteNode(node *&h, int loc){
	node *temp = h;
	for(int i=0; i<loc-2; i++){
		temp = temp->next;
	}
	node *tail = temp->next->next;
	delete temp->next;
	temp->next = tail;
}

void editNode(node *&h, int loc, int value){
	if(loc==1){
		node *temp = h;
		temp->val = value;
	}else if(loc>1){
		node *temp = h;
		for(int i=0; i<loc-1; i++){
			temp = temp->next;
		}
		temp->val = value;
	}
}

void appendNode(node *&h, int loc, int value){
	if(loc==1){
		node *temp = h;
		h = new node;
		h->val = value;
		h->next = temp;
		
	}else if(loc>1){
		node *temp = h;
		
		for(int i=0; i<loc-2; i++){
			temp = temp->next;
		}
		node *tail = temp->next;
		temp->next = new node;
		temp->next->val = value;
		temp->next->next = tail;
		
	}
}

void addNode(node **h){
	node *temp = new node;
	
	cout<<"Enter a number : ";
	cin>>temp->val;
	
	temp->next = NULL;
	
	if(*h==NULL){
		*h=temp;
	}else{
		node *current = *h;
		
		while(current->next!=NULL){
			current = current->next;
		}
		current->next = temp;
	}
}

void printList(node *h){
	while(h!=NULL){
		cout<<h->val<<" ";
		h = h->next;
	}
	cout<<endl;
}
