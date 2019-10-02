#include<string>
#include<iostream>
#include"Company.h"
#include"University.h"
using namespace std;
class Project:public Company, public University 
{
	private:
	string type;
	int duration_in_days;
	float amount_granted;
	public:
	Project();
	void setType(const string& t);
	void setDuration(const int& d);
	void setAmountG(const float& am);
	string getType();
	int getDuration();
	float getAmountG();
	Project(const string& n,const string& d,const string& p,const string& name_c,const int& num,const float& am_f,const string& t,const int& d1,const float& am);
	Project(const Project& obj);
	~Project();
	void display();
};
