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
		Fraction& operator+(Fraction &f);
		Fraction& operator-(Fraction &f);
		const Fraction operator=(const Fraction &res);
		friend std::istream& operator>>(std::istream& is, Fraction &x);
		friend std::ostream& operator<<(std::ostream& os, const Fraction &x);
	private:
		int num;
		int den;
};

#endif
