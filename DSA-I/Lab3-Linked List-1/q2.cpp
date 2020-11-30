#include <iostream>
#include<stdlib.h>
using namespace std;
struct Node { 
   int data; 
   struct Node *next; 
}; 
struct Node* top = NULL; 
void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 
   newnode->data = val; 
   newnode->next = top; 
   top = newnode; 
}
void pop() {
   if(top==NULL)
      cout<<"Stack Underflow"<<endl;
   else {
      struct Node *temp;
      temp = top;
      cout<<"Popped "<< top->data <<endl;
      top = top->next;
      free(temp);
   }
}
void display() {
   struct Node* ptr;
   if(top==NULL)
      cout<<"Stack is empty";
   else {   
      ptr = top; 
      cout<<"Stack elements: ";
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
   {cout<<"1 to insert, 2 to delete element, 3 to display stack"<<endl;
   cin>>c;
      switch(c) {
         case 1: {   
            cout<<"Enter value to be pushed:"<<endl; cin>>val; push(val); break;}
         case 2: {
            pop();
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