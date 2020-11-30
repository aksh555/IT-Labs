#include<bits/stdc++.h>
using namespace std;

int dtb(int x)
{
	if(x==0)
		return 0;
	return (x%2 + 10*dtb(x/2));
}
int main()
{
	int n,len,y,c=0,i;
	cout<<"Enter a no"<<endl;
	cin>>n;
	y=n;
	len=log(n)/log(2)+1;
	int a[len+1];
	while(n>0)
	{
		a[c]=n%2;
		n/=2;
		c++;
	}
	cout<<"Binary(iterative): ";
	for(i=len-1;i>=0;i--)
		cout<<a[i];
	cout<<endl;
	cout<<"binary(recursive): "<<dtb(y)<<endl;
}