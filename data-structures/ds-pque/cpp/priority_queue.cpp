//The queue which is implemented as FIFO where insertions are done at one end (rear) and deletions are done from another end (front). The first element that entered is deleted first.

Queue operations are

EnQueue (int data): Insertion at rear end

int DeQueue(): Deletion from front end

But a priority queue doesn’t follow First-In-First-Out, but rather than each element has a priority based on the basis of urgency.

Items with the same priority are processed on First-In-First-Out service basis.

An item with higher priority is processed before other items with lower priority.//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct n // node declaration {
   int p;
   int info;
   struct n *l;
};
class Priority_Queue {
   private:
      //Declare a front pointer f and initialize it to NULL.
      n *f;
   public:
      Priority_Queue() //constructor {
         f = NULL;
      }
      void insert(int i, int p) {
         n *t, *q;
         t = new n;
         t->info = i;
         t->p = p;
         if (f == NULL || p < f->p) {
            t->l= f;
            f = t;
         } else {
            q = f;
            while (q->l != NULL && q->l->p <= p)
               q = q->l;
               t->l = q->l;
               q->l = t;
         }
      }
      void del() {
         n *t;
         if(f == NULL) //if queue is null
            cout<<"Queue Underflow\n";
         else {
            t = f;
            cout<<"Deleted item is: "<<t->info<<endl;
            f = f->l;
            free(t);
         }
      }
      void show() //print queue {
         n *ptr;
         ptr = f;
         if (f == NULL)
            cout<<"Queue is empty\n";
         else {
            cout<<"Queue is :\n";
            cout<<"Priority Item\n";
            while(ptr != NULL) {
               cout<<ptr->p<<" "<<ptr->info<<endl;
               ptr = ptr->l;
            }
         }
      }
};
int main() {
   int c, i, p;
   Priority_Queue pq;
   Do//perform switch opeartion {
      cout<<"1.Insert\n";
      cout<<"2.Delete\n";
      cout<<"3.Display\n";
      cout<<"4.Exit\n";
      cout<<"Enter your choice : ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>i;
            cout<<"Enter its priority : ";
            cin>>p;
            pq.insert(i, p);
            break;
         case 2:
            pq.del();
            break;
         case 3:
            pq.show();
            break;
         case 4:
            break;
         default:
         cout<<"Wrong choice\n";
      }
   }
   while(c != 4);
   return 0;
}