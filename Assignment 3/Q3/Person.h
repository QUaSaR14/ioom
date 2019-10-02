#include<iostream>
#include<string>
#include"Birthday.h"
#include"Salary.h"
using namespace std;
class Person{
	private:
	string name;
	Birthday* b1;
	Salary* s1;
	public:
	Person();
	string getName();
	void setName(string n);
	Person(string name);
	Person(const Person& obj);
	~Person();
	void display();
};
