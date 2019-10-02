#include<iostream>
#include"Date.h"
using namespace std;
istream &operator >> (istream &in,Date &d){
    char c;
    in>>d.day>>c>>d.month>>c>>d.year>>d.hour>>c>>d.min;
    return in;
}
ostream &operator << (ostream &out,Date &d){
    out<<d.day<<" "<<d.month<<" "<<d.year<<" "<<d.hour<<" "<<d.min<<endl;
    return out;
}
Date::Date()
{
	cout<<"Constructor of date"<<endl;
}
int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}
int Date::getHour()
{
	return hour;
}
int Date::getMin()
{
	return min;
}
void Date::setDay(int d)
{
	day=d;
}
void Date::setMonth(int m)
{
	month=m;
}
void Date::setYear(int y)
{
	year=y;
}
void Date::setHour(int h)
{
	hour=h;
}
void Date::setMin(int mi)
{
	min=mi;
}
Date::Date(int d,int m,int y,int h,int mi)
{
	day=d;
	month=m;
	year=y;
	hour=h;
	min=mi;
}
Date::Date(const Date& obj)
{
	day=obj.day;
	month=obj.month;
	year=obj.year;
	hour=obj.hour;
	min=obj.min;
}
Date::~Date()
{
	cout<<"Destructor of date"<<endl;
}
Date Date::operator+(const Date& d1)
{
	int days_increment=d1.day;
	int hrs_increment=d1.hour;
	int add=hrs_increment/24;
	hrs_increment%=24;
	int res=hour+hrs_increment;
	//printf("%d %d resu\n",res,hour);
	if(res>24)
	{
		add++;
		res-=24;
	}
	hour=res;
	days_increment+=add;
	int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(year%100!=0 && year%4==0 || year%400==0)
	m[1]=29;
	int count=0;
	while(count<days_increment)
	{
		day=day+1;
		if(day>m[month-1])
		{
			day=1;
			month++;
			if(month>=13)
			{
				year++;
				month=1;
				if(year%100!=0 && year%4==0 || year%400==0)
				m[1]=29;
				else
				m[1]=28;
			}
		}
		count++;
	}
	return *this;
}
Date Date::operator-(const Date& d1)
{
	
	int days_decrement=d1.day;
	int hrs_decrement=d1.hour;
	int add=hrs_decrement/24;
	hrs_decrement%=24;
	int res=hour-hrs_decrement;
	if(res<0)
	{
		add++;
		res=res+24;
	}
	hour=res;
	days_decrement+=add;
	int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(year%100!=0 && year%4==0 || year%400==0)
	m[1]=29;
	int count=0;
	while(count<days_decrement)
	{
		day=day-1;
		if(day<=0)
		{
			month--;
			if(month<=0)
			{
				year--;
				if(year%100!=0 && year%4==0 || year%400==0)
				m[1]=29;
				else
				m[1]=28;
				month=12;
			}
			day=m[month-1];
		}
		count++;
	}
	return *this;
}
int main()
{
	Date date;
	cin>>date;
	int d,h;
	cin>>d>>h;
	Date temp(d,0,0,h,0);
	date=date+temp;
	cout<<date;
	date=date-temp;			
	cout<<date;
	return 0;
}
		
