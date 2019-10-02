#include<iostream>
#include"Complex.h"
using namespace std;
istream &operator >> (istream& in,Complex& c)
{
    in>>c.real;
    in>>c.imaginary;
    return in;
}
ostream &operator << (ostream& out,Complex& c)
{
	if(c.imaginary>=0)
	    out<<c.real<<"+"<<c.imaginary<<"i"<<endl;
	else
		out<<c.real<<c.imaginary<<"i"<<endl;
    return out;
}
Complex::Complex()
{
	
}
int Complex::getReal()
{
	return real;
}
int Complex::getIm()
{
	return imaginary;
}
void Complex::setReal(int r)
{
	real=r;
}
void Complex::setIm(int i)
{
	imaginary=i;
}
Complex::Complex(int r,int i)
{
	real=r;
	imaginary=i;
}
Complex::Complex(const Complex& obj)
{
	real=obj.real;
	imaginary=obj.imaginary;
}
Complex::~Complex()
{
	
}
Complex Complex::operator+(const Complex& c)
{
	return Complex(real+c.real,imaginary+c.imaginary);
}
Complex Complex::operator-(const Complex& c)
{
	return Complex(real-c.real,imaginary-c.imaginary);
}
Complex Complex::operator*(const Complex& c)
{
	return Complex((real*c.real)-(imaginary*c.imaginary),(real*c.imaginary)+(imaginary*c.real));
}
Complex Complex::operator/(const Complex& c)
{
    int d = c.real*c.real + c.imaginary*c.imaginary;
    return Complex((real*c.real+imaginary*c.imaginary)/d,(imaginary*c.real - real*c.imaginary)/d);
}
