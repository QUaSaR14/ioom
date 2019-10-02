#include<iostream>
#include<string>
#include"Salary.h"
using namespace std;
int Salary::getSalary()
{
	return salary;
}
Salary::Salary()
{
	cout<<"Constructor of Salary"<<endl;
}
Salary::Salary(int s)
{
	salary=s;
}
void Salary::setSalary(int s)
{
	salary=s;
}
Salary::Salary(const Salary& s1)
{
	salary=s1.salary;
}
Salary::~Salary()
{
	cout<<"Destructor of salary"<<endl;
}
void Salary::display()
{
	cout<<"Salary is "<<salary<<endl;
}
