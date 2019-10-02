#include<iostream>
#include<string>
using namespace std;
class Birthday
{
	private:
	int day;
	int month;
	int year;
	friend class Person;
	public:
	Birthday();
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay();
	int getMonth();
	int getYear();
	Birthday(int d,int m,int y);
	~Birthday();
	Birthday(const Birthday& obj);
	void show();
};
