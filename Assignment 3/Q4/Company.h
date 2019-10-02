#include<string>
#include<iostream>
using namespace std;
class Company
{
	protected:
	string name_company;
	int num_engineers;
	private:
	float amount_invested;
	public:
	Company();
	void setName(const string& n);
	void setNum(const int& num);
	void setAmount(const float& am);
	string getName();
	int getNum();
	float getAmount();
	Company(const string& name,const int& num,const float& am);
	Company(const Company& obj);
	~Company();
	void display();
};
