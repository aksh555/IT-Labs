#include <iostream>
#include<stdlib.h>
using namespace std;
struct Node { 
   int data; 
   struct Node *next; 
}; 
struct Node* front = NULL; 
struct Node* rear = NULL;
void enque(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 
   newnode->data = val; 
   newnode->next = NULL; 
   if(rear==NULL){
   front = newnode; 
   rear = newnode;}
   else{
      rear->next=newnode;
      rear=newnode;
   }
}
void deque() {
   if(front==NULL){
      cout<<"Queue empty(underflow)"<<endl;
      rear=NULL;}
   
   else {
      struct Node *temp;
      temp = front;
      cout<<"Dequeued "<< front->data <<endl;
      front = front->next;
      free(temp);
   }
}
void display() {
   struct Node* ptr;
   if(front==NULL)
      cout<<"Queue is empty";
   else {   
      ptr = front; 
      cout<<"Queue elements: ";
      while (ptr != NULL) { 
         cout<< ptr->data <<" "; 
         ptr = ptr->next; 
      } 
   }
   cout<<endl;
}
int main() {
   char ch = 'y';
   int c, val; 
   
   while(ch =='y')
   {cout<<"1 to insert, 2 to delete element, 3 to display queue"<<endl;
   cin>>c;
      switch(c) {
         case 1: {   
            cout<<"Enter value to be enqueued:"<<endl; cin>>val; enque(val); break;}
         case 2: {
            deque();
            break;
         }
         case 3: {
            display();
            break;
         }

         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
      cout<<"Do you want to continue? "<<endl;
      cin>>ch;
   }
}  