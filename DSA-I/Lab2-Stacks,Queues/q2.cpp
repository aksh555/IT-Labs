#include<bits/stdc++.h>
using namespace std;
class Queue
{
public:
	int size,left,right,a[10];
	Queue(){
	 size = 10;
	 left = -1;
	 right = -1;
	 a[10];}
	void enque(int x)
	{
		if(right == size-1)
			cout<<"Queue overflow"<<endl;
		else{
		a[++right] = x;
		cout<<"Enqued "<< x<<endl;}
		if(right==0) left=0;
	}
	void deque()
	{
		if(right-left==1)
			cout<<"Queue underflow"<<endl;
		else{
		cout<<"Dequed "<< a[left]<<endl;
		left++;}
	}
	void show()
	{
		cout<<"Queue: ";
		for(int i=left;i<=right;i++)
			cout<<a[i]<<" ";
	}
};
int main()
{
	Queue q;
	char ch = 'y';
	int m,x;
	while(ch == 'y')
	{
		cout<<"Enter 1 to enque, 2 to deque, 3 to see Queue ";
		cin>>m;
		switch(m){
			case 1: {cout<<"Enter element "; cin>>x; q.enque(x); break;}
			case 2: {q.deque(); break;}
			case 3: {q.show(); break;}
			default: cout<<"Invalid choice"<<endl;
		}
		cout<<"Want to try another operation? (y for yes)"<<endl;
		cin>>ch;
	}
}
