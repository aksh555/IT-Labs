#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
	int rn;
	float scor,cg;
	struct Node * next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void add(int n,float x,float y)
{

	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->rn=n;
	newnode->scor=x;
	newnode->cg=y;
	newnode->next = NULL;
	if(front==NULL){
   front = newnode; 
}
   else if(x>front->scor){
   	newnode->next=front;
   	front = newnode;
   }
   else{
   	struct Node* ptr;
   	ptr = front;
   	while(ptr->next!=NULL && x< (ptr->next->scor)){
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


void show(int c,float x,float y)
{
	int i=1;
	int j=1;
	cout<<"Sl.No."<<"\tRoll No.\tScore\tCGPA"<<endl;
	if(c==1)
	{
		struct Node* ptr;
		ptr = front;
		while(ptr!=NULL)
		{
			if(ptr->scor >= x && ptr->cg >= y)
			{
				cout<<i<<"\t"<<ptr->rn<<"\t"<<"\t"<<ptr->scor<<"\t"<<ptr->cg<<endl;
				i++;
			}
			ptr=ptr->next;
		}

	}
	else
	{
		struct Node* ptr;
		ptr = front;
		while(ptr!=NULL)
		{
			if(ptr->cg>=x && y>0)
			{
				cout<<j<<"\t"<<ptr->rn<<"\t"<<"\t"<<ptr->scor<<"\t"<<ptr->cg<<endl;
				j++; y--;
			}
			ptr=ptr->next;
	}
}
}
int main()
{
	float x,y,cx,cy(0);
	int n,c,cn(0);
	int ch=1;
	
	while(ch==1)
	{
		cout<<"Enter details"<<endl;
		cin>>n>>x>>y;
		add(n,x,y);
		cout<<"Want to add more?";
		cin>>ch;
	}
	cout<<"Criteria of list (1 for cutoff, 2 for top x)"<<endl;
		cin>>c;
		if(c==1)
		{
			cout<<"Enter cutoff marks, CGPA"<<endl;
			cin>>cx>>cy;
			show(c,cx,cy);
		}
		else
		{
			cout<<"Enter min CGPA,number of stud"<<endl;
			cin>>cy>>cn;
			show(c,cy,cn);
		}
}
