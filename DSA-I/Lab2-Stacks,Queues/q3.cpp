#include<bits/stdc++.h>
using namespace std;
class Stack
{
public:
	int size,top1,top2,a[10];
	Stack(){
	 size = 10;
	 top1 = -1;
	 top2 = size;
	 a[10];}
	void push1(int x)
	{
		if(abs(top1-top2)==1)
			cout<<"Stack overflow"<<endl;
		else{
		a[++top1] = x;
		cout<<"Pushed "<< x<<endl;}
	}
	void pop1()
	{
		if(top1==-1)
			cout<<"Stack underflow"<<endl;
		else{
		cout<<"Popped "<< a[top1]<<endl;
		top1--;}
	}
	void push2(int x)
	{
		if(abs(top1-top2)==1)
			cout<<"Stack overflow"<<endl;
		else{
		a[--top2] = x;
		cout<<"Pushed "<< x<<endl;}
	}
	void pop2()
	{
		if(top2==size+1)
			cout<<"Stack underflow"<<endl;
		else{
		cout<<"Popped "<< a[top2]<<endl;
		top2--;}
	}
	void show()
	{
		cout<<"Stack:"<<endl;
		for(int i=size-1;i>=top2;i--)
			cout<<a[i];
		cout<<" ";
		for(int j=top1;j>=0;j--)
			cout<<a[j];
	}
};
int main()
{
	Stack s;
	char ch = 'y';
	int m,x;
	while(ch == 'y')
	{
		cout<<"Enter 1 to push to stack1, 2 to pop from stack1, 3 to push to stack2, 4 to pop from stack2, 5 to view stack"<<endl;
		cin>>m;
		switch(m){
			case 1: {cout<<"Enter element"; cin>>x; s.push1(x); break;}
			case 2: {s.pop1(); break;}
			case 3: {cout<<"Enter element"; cin>>x; s.push2(x); break;}
			case 4: {s.pop2(); break;}
			case 5: {s.show(); break;}
			default: cout<<"Invalid choice"<<endl;

		}
		cout<<"Want to try another? (y for yes)"<<endl;
		cin>>ch;
	}
}