#include <iostream>

#include "Rational.hpp"

int main()
{
	using namespace std;
	using numeric::Rational;

	Rational a { 1, 3 };
	Rational b { 3, 2 };

	cout << "Rational Number Class - Test Program\n"
			"------------------------------------\n"
		 << endl;
	
	Rational c = a + b;

	cout << a.numerator() << '/' << a.denominator() << " + "
		 << b.numerator() << '/' << b.denominator() << " = "
		 << c.numerator() << '/' << c.denominator() << endl;

	Rational d = a * c;

	cout << a.numerator() << '/' << a.denominator() << " * "
		 << c.numerator() << '/' << c.denominator() << " = "
		 << d.numerator() << '/' << d.denominator() << endl;

	Rational e = d - b;

	cout << d.numerator() << '/' << d.denominator() << " - "
		 << b.numerator() << '/' << b.denominator() << " = "
		 << e.numerator() << '/' << e.denominator() << endl;

	Rational f = e / a;

	cout << e.numerator() << '/' << e.denominator() << " / "
		 << a.numerator() << '/' << a.denominator() << " = "
		 << f.numerator() << '/' << f.denominator() << endl;

	cout.setf(ios::boolalpha);

	cout << a.numerator() << '/' << a.denominator() << " == "
		 << b.numerator() << '/' << b.denominator() << " ? "
		 << (a == b) << endl;

	cout << c.numerator() << '/' << c.denominator()
		 << " Positive? " << (c > Rational::ZERO) << endl;

	cout << e.numerator() << '/' << e.denominator()
		 << " Negative? " << (e < Rational::ZERO) << endl;

	return 0;
}
