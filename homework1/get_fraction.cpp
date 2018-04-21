# include <iostream>
using namespace std;

class Fraction
{
	public:
	  void calculate(int a, int b, int c, int d) {num = a + c; denom = b + d;}
	  void print(void) {cout << num << "/" << denom << endl;}
	private:
	  int num, denom;
};

int main()
{
	Fraction f;
	int n1, d1, n2, d2;
	char slash;

	cin >> n1 >> slash >> d1 >> n2 >> slash >> d2;
	f.calculate(n1, d1, n2, d2);
	f.print();
}
