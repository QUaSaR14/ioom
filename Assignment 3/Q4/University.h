#include<string>
#include<iostream>
using namespace std;
class University
{
	protected:
	string name;
	string department;
	string person_name;
	public:
	University();
	string getName();
	string getDepartment();
	string getPerson();
	void setName(const string& n);
	void setDepartment(const string& d);
	void setPerson(const string& p);
	University(const string& n,const string& d,const string& p);
	University(const University& obj);
	~University();
	void display();
};

