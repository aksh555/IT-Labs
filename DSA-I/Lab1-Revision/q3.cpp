#include<bits/stdc++.h>
using namespace std;

int reverse(int s, int x)
{
	if(x<10)
		return s*10+x;
	return reverse(s*10+x%10,x/10);
}
int main()
{
	int n,s=0,y,r;
	cout<<"Enter a no"<<endl;
	cin>>n;
	y=n;
	while(n>0)
	{
		r = n%10;
		s=s*10+r;
		n/=10;
	}
	cout<<"Reverse(iterative): "<<s<<endl;
	cout<<"Reverse(recursive): "<<reverse(0,y)<<endl;
}