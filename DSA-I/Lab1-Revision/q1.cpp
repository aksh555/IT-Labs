#include<bits/stdc++.h>
using namespace std;

int factorial(int x)
{
	if(x==0 || x==1)
		return 1;
	return x*factorial(x-1);
}
int main()
{
	int n,fact=1,y;
	cout<<"Enter a no"<<endl;
	cin>>n;
	y=n;
	while(n>0)
	{
		fact*=n;
		n--;
	}
	cout<<"Factorial(iterative): "<<fact<<endl;
	cout<<"Factorial(recursive): "<<factorial(y)<<endl;
}