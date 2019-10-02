#include<iostream>
#include "Company.h"
using namespace std;
Company::Company()
{
	cout<< "inside default constructor of Company"<<endl;
}
void Company::setName(const string& n)
{
	name_company=n;
}
void Company::setNum(const int& num)
{
	num_engineers=num;
}
void Company::setAmount(const float& am)
{
	amount_invested=am;
}
Company::Company(const string& name,const int& num,const float& am)
{
	setName(name);
	setNum(num);
	setAmount(am);
}
string Company::getName()
{
	return name_company;
}
int Company::getNum()
{
	return num_engineers;
}
float Company::getAmount()
{
	return amount_invested;
}
Company::Company(const Company& obj)
{
	name_company=obj.name_company;
	amount_invested=obj.amount_invested;
	num_engineers=obj.num_engineers;
}	
Company::~Company()
{
	cout<< "Inside destructor of company"<<endl;
}
void Company::display()
{
	cout<<"Company's name: "<< name_company <<endl;
	cout<<"Number of engineers: "<< num_engineers<<endl;
	cout<<"Amount invested: "<< amount_invested<<endl;
}
