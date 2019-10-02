#include<iostream>
#include<string>
using namespace std;
class Salary
{
	private:
	int salary;
	friend class Person;
	public:
	int getSalary();
	Salary();
	Salary(int s);
	void setSalary(int s);
	Salary(const Salary& s1);
	~Salary();
	void display();
};
