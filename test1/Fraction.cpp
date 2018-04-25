// Minyoung Shin
// 912210108

#include "Fraction.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Fraction::Fraction()
{
  num = den = 0;
}
Fraction::Fraction(int a, int b)
{
  num = a;
  den = b;
}

int Fraction::getNum() const
{
  return num;
}

int Fraction::getDen() const
{
  return den;
}

Fraction& Fraction::operator+(Fraction &f)
{
  num = num * f.den + f.num * den;
  den = den * f.den;
}

Fraction& Fraction::operator-(Fraction &f)
{
  num = num * f.den - f.num * den;
  den = den * f.den;
}

Fraction& Fraction::operator=(Fraction &res)
{
  while (res.num % 2 == 0 && res.den % 2 == 0)
  {
    res.num = res.num /2;
    res.den = res.den / 2;
  }
  while (res.num % 3 == 0 && res.den % 3 == 0)
  {
    res.num = res.num /3;
    res.den = res.den /3;
  }
  if (res.den < 0)
    {
      res.num *= -1;
      res.den *= -1;
    }
  if (res.den == res.num)
  {
    res.num = 1;
    res.den = 1;
  }
  return res;
}

std::istream& operator >> (std::istream& is, Fraction &x)
{
  char slash;
  is >> x.num >> slash >> x.den;
  if (x.den == 0)
  {
    throw std::invalid_argument("zero denominator");
  }
  return is;
}

std::ostream& operator << (std::ostream& os, const Fraction &x)
{
  if (x.den == 1)
  {
    os << x.num;
  }
  else {
    os << x.num << "/" << x.den;
  }
  return os;
}
