// Minyoung Shin
// 912210108

#include "Shape.h"
#include "Domain.h"
#include <iostream>
#include <vector>
using namespace std;

Domain::Domain (void) : sizex(600), sizey(500) {}

Domain::~Domain (void) {}

void Domain::addShape (const Shape* p)
{
  s.push_back(p);
}

void Domain::draw (void)
{
  Rectangle d(Point(0,0), sizex ,sizey);

  cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>" << endl;
  cout << "<svg width=\"700\" height=\"600\"" << endl;
  cout << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
  cout << "<g transform=\"matrix(1,0,0,-1,50,550)\"" << endl;
  cout << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << endl;
  cout << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"" << sizex << "\" height=\"" << sizey << "\"/>" << endl;

//printing the shapes
  vector<const Shape*>::iterator it = s.begin();
  while (it != s.end())
  {
    const Shape * ptr = *it;
    ptr->draw();
    *it++;
  }

  cout << "</g>" << endl;
  cout << "<g transform=\"matrix(1,0,0,1,50,590)\"" << endl;
  cout << " font-family=\"Arial\" font-size=\"32\">" << endl;
  cout << "<text x=\"0\" y=\"0\">";

  it = s.begin();
  const Shape * ptr = *it;

  if (ptr->fits_in(d) == 1)
  {
    cout << "does not fit</text>" << endl;
  }
  else
  {
    *it++;
    while (it != s.end())
    {
      int n = 0;
      const Shape * ptr2 = *it;
      if ( ptr2->fits_in(d) == 1)
      {
        cout << "does not fit</text>" << endl;
        break;
      }
      if (ptr2->overlaps(*ptr) == 1)
      {
        cout << "overlap on " << n << "</text>" << endl;
        break;
      }
      if (it == s.end() - 1)
      {
        cout << "ok</text>" << endl;
      }
      ptr = *it;
      *it++;
      n++;
    }
  }
  cout << "</g>" << endl;
  cout << "</svg>" << endl;
}
