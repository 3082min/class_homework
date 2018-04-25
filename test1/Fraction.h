//Minyoung Shin
//912210108

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction
{
	public:
		Fraction();
		Fraction(int a, int b);
		int getNum() const;
		int getDen() const;
		Fraction& operator+(Fraction &y);
		Fraction& operator-(Fraction &y);
		Fraction& operator=(Fraction &res);
		friend std::istream& operator>>(std::istream& is, Fraction &x);
		friend std::ostream& operator<<(std::ostream& os, const Fraction &x);
	private:
		int num;
		int den;
		int gcd;
		int rem;
		int c;
		int d;
};

#endif
