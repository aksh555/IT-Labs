#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void insert(int val) {
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
  void sort(int n)
  {
    struct Node *ptr;
    struct Node *prev;
    if(front == NULL)
    cout<<"empty";
    if(front->next==NULL)
    return;
    ptr = front;
    prev = front;
    while(n!=0)
    {
      if(ptr->data == 0 && ptr!=front)
      {
        prev-> next = ptr -> next;
        ptr ->next = front;
        front = ptr;
        ptr=prev->next;
      }
      else if(ptr->data == 2)
      {
        if(ptr!=front)
        {
          prev-> next = ptr-> next;
          rear->next = ptr;
          ptr->next = NULL;
          rear = ptr;
          ptr=prev->next;
        }

        else
        {
          front = ptr->next;
          rear ->next = ptr;
          ptr ->next = NULL;
          rear = ptr;
          ptr=front;
        }
      }
      else
      {
        prev=ptr;
        ptr=ptr->next;
      }
      n--;
    }
  }


  void display()
  {
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
  int main()
  {
    char ch = 'y';
    int c, val;
    int n(0);
    while(ch =='y')
    {
      cout<<"Enter value to be enqueued:"<<endl; cin>>val; insert(val);
      n++;
      cout<<"Do you want to insert more? "<<endl;
      cin>>ch;
    }
    cout<<"Sorted:";
    sort(n);
    display();
  }
