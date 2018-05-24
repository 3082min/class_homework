// Minyoung Shin
// 912210108

#include "Point.h"
#include <iostream>
using namespace std;

Point Point::operator+ (const Point& rhs) const
{
  Point P;
  P.x = x + rhs.x;
  P.y = y + rhs.y;
  return P;
}

Point Point::operator- (const Point& rhs) const
{
  Point P;
  P.x = x -rhs.x;
  P.y = y - rhs.y;
  return P;
}

ostream& operator << (ostream& os, const Point& p)
{
  os << "(" << p.x << "," << p.y << ")";
  return os;
}

istream& operator >> (istream& is, Point& p)
{
  is >> p.x >> p.y;
  return is;
}
