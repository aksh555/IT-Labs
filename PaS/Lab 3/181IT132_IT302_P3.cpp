#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"Enter the value of m: ";
	cin>>m;
	cout<<"Enter the value of a: ";
	cin>>a;
	cout<<'\n';

	if(a<=0 || n<0 || m<0)
    {
		cout<<"Invalid input!\n";

		freopen("181IT132_IT302_P3_Output_TC6.txt","w",stdout);
		cout<<"n: "<<n<<'\n';
		cout<<"m: "<<m<<'\n';
		cout<<"a: "<<a<<'\n';
		cout<<"Invalid input!\n";
		return 0;
	}

	int sum=(n+1)*a;
	for(int x=0;x<=n;x++)
    {
		int k=pow(x,m);
		sum+=k;
	}

	cout<<"n: "<<n<<'\n';
	cout<<"m: "<<m<<'\n';
	cout<<"a: "<<a<<'\n';
	float c=(1.0/sum);
	cout<<"\nIntermediate results\n";

	for(int x=0;x<=n;x++)
    {
		int k=pow(x,m);
		cout<<"f("<<x<<") = "<<"c*"<<k+a<<'\n';
	}

	cout<<"\nValue of sum f(0)...f(n): c*"<<sum;
    cout<<"\nFor probability dist. function sum = 1";
	cout<<"\nValue of c: "<<c<<"\n";

	freopen("181IT132_IT302_P3_Output_TC6.txt","w",stdout);

	cout<<"n: "<<n<<'\n';
	cout<<"m: "<<m<<'\n';
	cout<<"a: "<<a<<'\n';
	cout<<"\nIntermediate results\n";

	for(int x=0;x<=n;x++)
    {
		int k=pow(x,m);
		cout<<"f("<<x<<") = "<<"c*"<<k+a<<'\n';
	}
	cout<<"\nValue of sum f(0)...f(n): c*"<<sum;
    cout<<"\nFor probability dist. function sum = 1";
	cout<<"\nValue of c: "<<c;
}