#ifndef RATION_H_
#define RATION_H_
#include <iostream>

namespace numeric
{
	using namespace std;
	
	class Rational
	{
		public:
		//Constants
			static const Rational ZERO;
			static const Rational INFINITY;
			static const Rational UNDEFINED;
		//constructors
			Rational();			
			Rational(const Rational &);
			Rational(int numerator, int denomanator);
		//Destructors
			~Rational();
		//Observers	
			void fract() const {cout << top << "/" << bottom;}
			int numerator() const;
			int denominator() const;
		//Operation Overloading
			Rational operator+(const Rational & b);
			Rational operator-(const Rational & b);
			Rational operator-();
			Rational operator*(const Rational & n);	
			Rational operator/(const Rational & n);
	        Rational operator=(const Rational & n);			
		
		//Friends
			friend bool operator<(const Rational & n, const Rational & b);
			friend bool operator>(const Rational & n, const Rational & b);
			friend bool operator==(const Rational & n, const Rational & b);

		private:
		//methods
			static int gcd( int a, int b );
			void reduce();
		//Variable
			int top;
			int bottom;
	};
}
#endif //RATION_H_