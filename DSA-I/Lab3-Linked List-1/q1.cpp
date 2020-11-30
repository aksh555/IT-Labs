#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node * next;

};

Node *head = NULL;

void show(Node * x)
{
	cout<<"Displaying Stack:"<<endl;
	while(x!=NULL){
	cout<<x->data<<" ";
	x = x->next;}
	cout<<endl;
}
void insert(Node * x, int k)
{

	Node *newnode = new Node(); newnode->data=k; newnode->next = NULL;

	if(x==NULL)  x = newnode;
	else{
		while(x->next!=NULL){
			x=x->next;}
		x->next=newnode;
}}

void del(Node * x)
{
	Node * c = new Node();
	if(x==NULL) {cout<<"Stack underflow"<<endl;}
	else{
		c = x;
	while(x->next!=NULL){
		c= x;
			x=x->next;}
		cout<<"Popped "<<x->data<<endl;
		c->next=NULL;
		free(x);
}}

int main()
{
	char ch = 'y';
	int c,k;
	while(ch =='y')
	{
		cout<<"1 to insert, 2 to delete element, 3 to display stack"<<endl;
		cin>>c;
		switch(c)
		{
			case 1: {cout<<"Enter element"; cin>>k; insert(head,k); break;}
			case 2: {del(head); break;}
			case 3: {show(head); break;}
			default: cout<<"Invalid choice"<<endl;
		}
		cout<<"Do you want to continue? "<<endl;
		cin>>ch;
	}
}
