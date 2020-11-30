#include<bits/stdc++.h>
using namespace std;
int a[100];
void fibo(int x,int n)
{
	
	if(x==1)
		a[x]=0;
	if(x==2)
		a[x]=1;
	if(x>=3)
		a[x]=a[x-1]+a[x-2];
	if(x<n)
	fibo(x+1,n);
	}
int main()
{
	int n,f1,f2,f3,i,y;
	cout<<"Enter a no"<<endl;
	cin>>n;
	y=n;
	f1=0;
	f2=1;
	cout<<"Fibo seires(iterative): "<<f1<<" "<<f2<<" ";
	n-=2;
	while(n>0)
	{
		f3=f1+f2;
		f1=f2;
		f2=f3;
		cout<<f3<<" ";
		n--;
	}
	cout<<endl<<"Fibo series(recursive): ";
	fibo(1,y);
	for(i=1;i<y+1;i++)
		cout<<a[i]<<" ";

}