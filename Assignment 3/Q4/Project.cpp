#include<iostream>
#include"Project.h"
using namespace std;
Project::Project()
{
	cout<<"Inside constructor of Project"<<endl;
}
void Project::setType(const string& t)
{
	type=t;
}
void Project::setDuration(const int& d)
{
	duration_in_days=d;
}
void Project::setAmountG(const float& am)
{
	amount_granted=am;
}
Project::Project(const string& n,const string& d,const string& p,const string& name_c,const int& num,const float& am_f,const string& t,const int& d1,const float& am):University(n,d,p),Company(name_c,num,am_f),type(t),duration_in_days(d1),amount_granted(am)
{}
string Project::getType()
{
	return type;
}
int Project::getDuration()
{
	return duration_in_days;
}
float Project::getAmountG()
{
	return amount_granted;
}
Project::Project(const Project& obj)
{
	type=obj.type;
	duration_in_days=obj.duration_in_days;
	amount_granted=obj.amount_granted;
}
Project::~Project()
{
	cout<<"Destructor of Project"<<endl;
}
void Project::display()
{
	cout<<"name of university: "<<name<<endl;
	cout<<"department: "<<department<<endl;
	cout<<"Person: "<<person_name<<endl;
	cout<<"name of company: "<<name_company<<endl;
	cout<<"num of engineers: "<<num_engineers<<endl;
	cout<<"type of project: "<<type<<endl;
	cout<<"Duration: "<<duration_in_days<<endl;
	cout<<"amount granted: "<<amount_granted<<endl;
}
int main()
{
	string name,name_c,type,depart,person;
	int days,num;
	float amount_g,amount_f;
	name="VNIT";
	name_c="GOOGLE";
	depart="CSE";
	person="APOORV";
	days=15;
	num=1;
	amount_g=1545.76;
	amount_f=2000.00;
	Project object(name,depart,person,name_c,num,amount_f,type,days,amount_g);
	object.display();
	return 0;
}
