#include<iostream>
using namespace std;
class Date{
	private:
	int day;
	int month;
	int year;
	int hour;
	int min;
	public:
	Date();
	int getDay();
	int getMonth();
	int getYear();
	int getHour();
	int getMin();
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void setHour(int h);
	void setMin(int mi);
	Date(int d,int m,int y,int h,int mi);
	Date(const Date& obj);
	~Date();
	Date operator+(const Date& d1);
	Date operator-(const Date& d1);
	friend istream &operator >> (istream& in,Date& d1);
	friend ostream &operator << (ostream& out,Date& d2);
};

