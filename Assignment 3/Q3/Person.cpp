#include<iostream>
#include<string>
#include"Person.h"
using namespace std;
Person::Person()
{
	cout<<"Constructor of Person"<<endl;
	int d,m,y;
	cout<<"Enter day,month and year respectively"<<endl;
	scanf("%d %d %d",&d,&m,&y);
	b1=new Birthday(d,m,y);
	cout<<"Enter Salary"<<endl;
	scanf("%d",&d);
	s1=new Salary(d);
}
string Person::getName()
{
	return name;
}
void Person::setName(string n)
{
	name=n;
}
Person::Person(string n)
{
	name=n;
	int d,m,y;
	cout<<"Enter day,month and year respectively"<<endl;
	scanf("%d %d %d",&d,&m,&y);
	b1=new Birthday(d,m,y);
	cout<<"Enter Salary"<<endl;
	scanf("%d",&d);
	s1=new Salary(d);
}
Person::Person(const Person& obj)
{
	name=obj.name;
	b1=new Birthday();
	Birthday b2=*obj.b1;
	b1->day=b2.getDay();
	b1->month=b2.getMonth();
	b1->year=b2.getYear();
	s1=new Salary();
	Salary s2=*obj.s1;
	s1->salary=s2.getSalary();
}
Person::~Person()
{
	cout<<"Destructor of Person"<<endl;
	delete b1;
	delete s1;
}
void Person::display()
{
	cout<<"Name of the person is "<<name<<endl;
	b1->show();
	s1->display();
}
int main()
{
	string n;
	getline(cin,n);
	Person p(n);
	p.display();
	return 0;
}
