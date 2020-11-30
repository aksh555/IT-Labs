//sorted insertion in ll

#include <iostream>
#include<stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insert(int val)
{

	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = val;
   newnode->next = NULL;
   if(rear==NULL){
   front = newnode;
   rear = newnode;}
   else if(val<front->data){
   	newnode->next=front;
   	front = newnode;
   }
   else{
   	struct Node* ptr;
   	ptr = front;
   	while(ptr->next!=NULL && val> (ptr->next->data)){
   		ptr=ptr->next;
   	}
   	if(ptr->next==NULL){
   		ptr->next=newnode;
   	}

   	else{
	newnode->next = ptr->next;
   		ptr->next = newnode;}

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
   {cout<<"1 to insert, 2 to display queue"<<endl;
   cin>>c;
      switch(c) {
         case 1: {
            cout<<"Enter value to be inserted:"<<endl; cin>>val; insert(val); break;}
         case 2: {
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
