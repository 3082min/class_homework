// Minyoung Shin
// 912210108

#include "Point.h"
#include "Shape.h"
#include <iostream>
using namespace std;

//class Rectangle

Rectangle::~Rectangle (void) {}

bool Rectangle::overlaps (const Shape& r) const
{
  return r.overlaps(*this);
}

bool Rectangle::overlaps (const Circle& r) const
{
  int xn = min(max(r.center.x, position.x), position.x + width);
  int yn = min(max(r.center.y, position.y), position.y + height);
  int d2;
  d2 = ((xn - r.center.x) * (xn - r.center.x)) + ((yn - r.center.y) * (yn - r.center.y));
  if (d2 < (r.radius * r.radius))
  {
    return 1;
  }
  return 0;
}

bool Rectangle::overlaps (const Rectangle& r) const
{
  Point right = Point(position.x + width, position.y + height);
  Point r_right = Point(r.position.x + r.width, r.position.y + r.height);
  if (right.x <= r.position.x || r_right.x <= position.x)
  {
    return 1;
  }
  if (r.position.y <= right.y || position.y <= r_right.y)
  {
    return 1;
  }
  return 0;
}

bool Rectangle::fits_in (const Rectangle& r) const
{
  if (position.x < 0 || position.y < 0)
  {
    return 1;
  }
  else if ((position.x + width) > r.width || (position.y + height) > r.height)
  {
    return 1;
  }
  return 0;
}

void Rectangle::draw (void) const
{
  cout<< "<rect x=\"" << position.x << "\" y=\"" << position.y <<
  "\" width=\"" << width << "\" height=\"" << height <<"\"/>" << endl;
}


// class Circle

Circle::~Circle (void) {}

bool Circle::overlaps (const Shape& s) const
{
  return s.overlaps(*this);
}

bool Circle::overlaps (const Circle& r) const
{
  Point i;
  i = center - r.center;
  if (i.norm2() < (r.radius * r.radius + radius * radius))
  {
    return 1;
  }
  return 0;
}

bool Circle::overlaps (const Rectangle& r) const
{
  Circle c(center, radius);
  return r.overlaps(c);
}

bool Circle::fits_in (const Rectangle& r) const
{
  if ((center.x + radius) > r.width || (center.y + radius) > r.height)
  {
    return 1;
  }
  else if ((center.x - radius) < 0 || (center.y - radius) < 0)
  {
    return 1;
  }
  return 0;
}

void Circle::draw (void) const
{
  cout<< "<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << radius << "\"/>" << endl;
}
