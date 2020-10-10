//About stack
//A stack is a linear data structure that serves as a collection of elements, with following main operations:
//Push operation, which adds an elements to the stack.
//Pop operation, which removes the most recently added element that was not yet removed.

//The push and pop operations occur only at one end of the structure, referred to as the top of the stack.
//The order in which elements come off a stack gives rise to its alternative name, LIFO (for last in, first out).


#include<iostream>
using namespace std;
int A[100],choose,m,n,top,i;
void push();
void pop();
void display();

int main()
{
    top=-1;
    cout<<"Enter the size of stack:: ";
    cin>>m;

    cout<<"\n1.PUSH \n2.POP \n3.DISPLAY \n4.EXIT\n ";

    do                                                 //do-while loop is used to ask the user for their choice
    {
        cout<<"\n\nChoose the number :: ";
        cin>>choose;

        switch(choose)
        {
        case 1:
        {
            push();
            break;
        }

        case 2:
        {
            pop();
            break;
        }

        case 3:
        {
            display();
            break;
        }

        case 4:
        {
            cout<<"EXIT";
            break;
        }

        default:
        {
            cout<<"INVALID INPUT";
        }
        }
    }
    while(choose!=4);
    return 0;
}


void push()                                           //subprogram for operating the push operation in stack
{
    if(top>=m-1)                                        //if top is greater than and equals to size of array-1
    {
        cout<<"Stack overflow";
    }
    else                                                //else push the element
    {
        cout<<"Enter a value to be pushed:: ";
        cin>>n;
        top++;
        A[top]=n;
    }
}

void pop()                           //subprogram for operating the pop operation in stack
{
    if(top<=-1)                          //if top is less than and equals to -1
    {
        cout<<"Stack under flow";
    }
    else                                       //else pop the element
    {
        cout<<"Poped element is "<<A[top];
        top--;
    }
}

void display()                              //subprogram to display the elements of stack
{
    if(top>=0)                                 //if top is greater than and equals to 0
    {
        cout<<"Stack elements are:: ";
        for(i=top; i>=0; i--)
            cout<<"\t"<< A[i];
    }
    else                                              //else print stack is empty
    {
        cout<<"stack is empty.";
    }
}
