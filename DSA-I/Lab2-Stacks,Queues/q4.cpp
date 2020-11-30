#include<bits/stdc++.h>
using namespace std;
class Queue
{
public:
	int size,left,right,a[5];
	Queue(){
	 size = 5;
	 left = -1;
	 right = -1;
	 a[10];}
	void enque(int x)
	{
		if(left==0 && right==size-1 || left-right==1)
			cout<<"Queue overflow"<<endl;
		else{
			if(right==size-1 && left!=0) {right =-1; a[++right] = x;}
			else {a[++right] = x; if(right==0) left=0;}
		cout<<"Enqued "<< x<<endl;}
	}
	void deque()
	{
		if(left==-1)
			cout<<"Queue underflow"<<endl;
		else{
			cout<<"Dequed "<< a[left]<<endl;
			if(left==right)  left=right=-1;
			else left=(left+1)%size;}
	}
	void show()
	{
		int i;
		cout<<"Queue:"<<endl;
		if(right>=left)
		for(i=left;i<=right;i++)  cout<<a[i]<<" ";
		else{
		for(i=left;i<size;i++)    cout<<a[i]<<" ";
		for(i=0;i<=right;i++)    cout<<a[i]<<" ";}

	}
};
int main()
{
	Queue q;
	char ch = 'y';
	int m,x;
	while(ch == 'y')
	{
		cout<<"Enter 1 to enque, 2 to deque, 3 to see Queue"<<endl;
		cin>>m;
		switch(m){
			case 1: {cout<<"Enter element"; cin>>x; q.enque(x); break;}
			case 2: {q.deque(); break;}
			case 3: {q.show(); break;}
			default: cout<<"Invalid choice"<<endl;
		}
		cout<<"Want to try another? (y for yes)"<<endl;
		cin>>ch;
	}
}
