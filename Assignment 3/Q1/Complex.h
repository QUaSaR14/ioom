#include<iostream>
using namespace std;
class Complex
{
	private:
	int real;
	int imaginary;
	public:
	Complex();
	int getReal();
	int getIm();
	void setReal(int r);
	void setIm(int i);
	Complex(int i,int r);
	Complex(const Complex& obj);
	~Complex();
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	friend istream &operator >> (istream& in,Complex& d1);
	friend ostream &operator << (ostream& out,Complex& d2);
};
