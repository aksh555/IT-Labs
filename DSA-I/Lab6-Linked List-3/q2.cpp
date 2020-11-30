//reversing ll

#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
struct Node* pre=NULL;
struct Node* curr=NULL;
struct Node* nex=NULL;

void insert(int x)
{
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->data = x;
	newnode->next = NULL;
	if(front == NULL){
		rear = newnode;
		front = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}

}

void rev()
{
	curr = front;

	while(curr!=NULL)
	{

		nex = curr->next;
		curr->next = pre;
		pre = curr;
		curr = nex;
	}
}

void show()
{
	struct Node*p;
	p = rear;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

int main()
{
	int i,n;
	cout<<"Choice:"<<endl;
	while(true)
	{
		cout<<"1 to insert, 2 to see reversed list, 3 to exit ";
		cin>>n;
		if(n==1)
		{
			cout<<"Enter element ";
			cin>>i;
			insert(i);

		}
		else if(n==2)
		{
			cout<<"Reversed: ";
			rev(); show();
			cout<<endl;
		}
		else break;
	}
}
