#include<iostream>
#include "University.h"
using namespace std;
University::University()
{
	cout<< "Inside default constructor of University"<<endl;
}
void University::setName(const string& n)
{
	name=n;
}
void University::setDepartment(const string& d)
{
	department=d;
}
void University::setPerson(const string& p)
{
	person_name=p;
}
string University::getName()
{
	return name;
}
string University::getDepartment()
{
	return department;
}
string University::getPerson()
{
	return person_name;
}
University::University(const string& n,const string& d,const string& p)
{
	setName(n);
	setDepartment(d);
	setPerson(p);
}
University::University(const University& obj)
{
	name=obj.name;
	department=obj.department;
	person_name=obj.person_name;
}
University::~University()
{
	cout<<"Inside destructor of university"<<endl;
}
void University::display()
{
	cout<<"Name of university: "<< name<< endl;
	cout<<"Department: "<< department<< endl;
	cout<<"Person: "<< person_name<< endl;
}
