#include<iostream>
#include<string>
#include"Birthday.h"
using namespace std;
Birthday::Birthday()
{
	cout<<"Constructor of birthday"<<endl;
}
void Birthday::setDay(int d)
{
	day=d;
}
void Birthday::setMonth(int m)
{
	month=m;
}
void Birthday::setYear(int y)
{
	year=y;
}
int Birthday::getDay()
{
	return day;
}
int Birthday::getMonth()
{
	return month;
}
int Birthday::getYear()
{
	return year;
}
Birthday::Birthday(int d,int m,int y)
{
	day=d;
	month=m;
	year=y;
}
Birthday::~Birthday()
{
	cout<<"Destructor of birthday"<<endl;
}
Birthday::Birthday(const Birthday& obj)
{
	day=obj.day;
	month=obj.month;
	year=obj.year;
}
void Birthday::show()
{
	cout<<"Date of birth is "<<day<<"-"<<month<<"-"<<year<<endl;
}
