#include<bits/stdc++.h>
using namespace std;

int sod(int x)
{
	if(x<10)
		return x;
	return x%10 + sod(x/10);
}
int main()
{
	int n,s=0,y;
	cout<<"Enter a no"<<endl;
	cin>>n;
	y=n;
	while(n>0)
	{
		int r = n%10;
		s+=r;
		n/=10;
	}
	cout<<"SumOfDigits(iterative): "<<s<<endl;
	cout<<"SumOfDigits(recursive): "<<sod(y)<<endl;
}