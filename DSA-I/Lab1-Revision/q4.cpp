#include<bits/stdc++.h>
using namespace std;

void reverse(int n, string s)
{

	if(n>0){
		cout<<s[n-1];
		reverse(n-1,s);
	}
}
int main()
{
	int n,i;
	char c;
	string s,y;
	cout<<"Enter a string"<<endl;
	getline(cin,s);
	y=s;
	n=s.size();
	for(i=0;i<n/2;i++)
	{
		c=s[i];
		s[i]=s[n-i-1];
		s[n-i-1]=c;
	}
	cout<<"Reverse(iterative): "<<s<<endl;
	cout<<"Reverse(recursive): ";
	reverse(n,y);
}