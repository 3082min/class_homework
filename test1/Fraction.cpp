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
  this->setNum();
  this->setDen();
}

int Fraction::getNum() const
{
  return num;
}

int Fraction::getDen() const
{
  return den;
}

void Fraction::setNum()
{
  num = num / gcd;
}

void Fraction::setDen()
{
  if (den == 0)
    throw invalid_argument("zero denominator");
  den = den / gcd;
}

Fraction& Fraction::operator+(Fraction &y)
{
  y.num = num * y.den + y.num * den;
  y.den = den * y.den;
  return y;
}

Fraction& Fraction::operator-(Fraction &y)
{
  y.num = num * y.den - y.num * den;
  y.den = den * y.den;
  return y;
}

Fraction& Fraction::operator=(Fraction &res)
{
  c = res.num;
  d = res.den;

  rem = c % d;
  while (rem != 0)
  {
    c = d;
    d = rem;
    rem = c % d;
  }
  gcd = d;

  res.num = res.num / gcd;
  res.den = res.den / gcd;

  if (res.den < 0)
    {
      res.num *= -1;
      res.den *= -1;
    }
  return res;
}

std::istream& operator >> (std::istream& is, Fraction &x)
{
  char slash;
  is >> x.num >> slash >> x.den;
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
