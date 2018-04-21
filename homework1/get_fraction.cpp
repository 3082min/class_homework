# include <iostream>
using namespace std;

class Fraction
{
	public:
	  void print(void) {cout << num << "/" << denom << endl;}
	private:
	  int num, denom;
};

class Calculation
{
	public:
	  void add (int a, int b, int c, int d)
		{
			num = a + c;
			denom = b * d;
			f.print();
		}
	  void subtract (int a, int b, int c, int d)
		{
			num = a - c;
			denom = b * d;
			f.print();
		}
	  void multiply (int a, int b, int c, int d)
		{
			num = a * c;
			denom = b * d;
			f.print();
		}
	  void divide (int a, int b, int c, int d)
		{
			num = a * d;
			denom = b * c;
			f.print();
		}
	private:
	  int num, denom;
};

int main()
{
	Fraction f;
	Calculation c;
	int n1, d1, n2, d2;
	char slash, sign;

	cin >> n1 >> slash >> d1 >> sign >> n2 >> slash >> d2;

	c.subtract(n1,d1,n2,d2);
	c.add(n1,d1,n2,d2);
	c.multiply(n1,d1,n2,d2);
	c.divide(n1,d1,n2,d2);
}
