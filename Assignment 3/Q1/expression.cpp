#include<iostream>
#include<stack>
#include"Complex.h"
using namespace std;
int main()
{
	stack<Complex> a;
	char c='c';
	Complex x,y,z;
	while(c!=';')
	{
		cin>>c;
		if(c=='(')
		{
			Complex c1;
			cin>>c1;
			a.push(c1);
			cin>>c;
		}
		else if(c=='+')
		{
			x=a.top();
			a.pop();
			y=a.top();
			a.pop();
			z=x+y;
			cout<<"result1:"<<z<<endl;
			a.push(z);
		}
		else if(c=='-')
		{
			x=a.top();
			a.pop();
			y=a.top();
			a.pop();
			z=x-y;
			cout<<"result1:"<<z<<endl;
			a.push(z);
		}
		else if(c=='*')
		{
			x=a.top();
			a.pop();
			y=a.top();
			a.pop();
			z=x*y;
			cout<<"result1:"<<z<<endl;
			a.push(z);
		}
		else if(c=='/')
		{
			x=a.top();
			a.pop();
			y=a.top();
			a.pop();
			z=x/y;
			cout<<"result1:"<<z<<endl;
			a.push(z);
		}
	}
	z=a.top();
	cout<<z<<endl;
	return 0;
}
	
