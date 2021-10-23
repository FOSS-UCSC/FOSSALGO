//C++ Program to Implement Max PriorityQueue (using Ordered Array)

#include<iostream>
#define N 20
using namespace std;
int Q[N],Pr[N];
int r = -1,f = -1;
void enqueue(int data,int p)//Enqueue function to insert data and its priority in queue
{
	int i;
	if((f==0)&&(r==N-1)) //Check if Queue is full
		cout<<"Queue is full";
	else
	{
		if(f==-1)//if Queue is empty
		{
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;

		}
		else if(r == N-1)//if there there is some elemets in Queue
		{
			for(i=f;i<=r;i++) { 
                                Q[i-f] = Q[i]; 
                                Pr[i-f] = Pr[i];
                                r = r-f; 
                                f = 0;
                                for(i = r;i>f;i--)
				{
					if(p>Pr[i])
					{
						Q[i+1] = Q[i];
						Pr[i+1] = Pr[i];
					}
					else
						break;
					Q[i+1] = data;
					Pr[i+1] = p;
					r++;
				}
			}
		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if(p>Pr[i])
				{
					Q[i+1] = Q[i];
					Pr[i+1] = Pr[i];	
				}
				else
					break;
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
		}	
	}

}
void print() //print the data of Queue
{
int i;
	for(i=f;i<=r;i++)
	{
		cout<<"Element ="<<Q[i]<<"Priority = "<<Pr[i]<<endl;
	}
}
int dequeue() //remove the data from front
{
	if(f == -1)
	{
	cout<<"Queue is Empty";
	}	
	else
	{
	cout<<"deleted Element ="<<Q[f]<<endl;
	cout<<"Its Priority = "<<Pr[f]<<endl;
		if(f==r)
			f = r = -1;
		else
			f++;
	}
}
int main()
{
	int opt,n,i,data,p;
	cout<<"Enter Your Choice:-"<<endl;
	do{
	cout<<"1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit"<<endl;
	cin>>opt;
		switch(opt){
			case 1:
				cout<<"Enter the number of data"<<endl;
				cin>>n;
				cout<<"Enter your data and Priority of data"<<endl;
				i=0;
				while(i<n){
					cin>>data;
					cin>>p;
					enqueue(data,p);
					i++;
				}
				break;
			case 2:
				print();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
			cout<<"Incorrect Choice"<<endl;

		}
	}while(opt!=0);
        return 0;
}

