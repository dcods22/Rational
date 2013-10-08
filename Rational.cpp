#include "Rational.hpp"

namespace numeric
{
	using namespace std;
	
	//method to find the common differnce
	int Rational::gcd( int a, int b )
	{
		int rem = a % b;
		return rem == 0 ? b : gcd(b, rem);
	}
	
	//method to have a fraction reduced
	void Rational::reduce() 
	{ 
		int diff = Rational::gcd(top,bottom);
		
		top /= diff;
		bottom /= diff;
	}
	
	int Rational::numerator() const			//Method to return numerator
	{
		return top;
	}
	
	int Rational::denominator() const		//method to return denomanator
	{
		return bottom;
	}

	Rational::Rational()		//constructor
	{
		top = 0;
		bottom = 0;
	}
	
	Rational::Rational(int numerator, int denomanator)	//constructor
	{
		int diff = Rational::gcd(top,bottom);
		
		top = numerator / diff;
		bottom = denomanator / diff;
	}

	Rational::~Rational(){}
		
	Rational Rational::operator+(const Rational & b) 	//overwriting operator
    {
		int ntop;
		int nbottom;
		nbottom = (bottom * b.bottom);
		ntop = (b.bottom * top) + (bottom * b.top);
		Rational temp {ntop,nbottom};
		temp.reduce();
		return temp;
    }

    Rational Rational::operator-(const Rational & b)	//overwriting operator
    {
		int ntop;
		int nbottom;
		nbottom = (bottom * b.bottom);
		ntop = (b.bottom * top) - (bottom * b.top);
		Rational temp {ntop,nbottom};
		temp.reduce();
		return temp;
    }

    Rational Rational::operator-() 	//overwriting operator
    {
        return Rational(-top, bottom);
    }

	Rational Rational::operator*(const Rational & n) 	//overwriting operator
    {

		Rational temp {(n.top * top), (n.bottom * bottom)};
		temp.reduce();
		return temp;;
    }
	
	Rational Rational::operator/(const Rational & n) 	//overwriting operator
    {
		Rational temp {(top * n.bottom),( bottom * n.top)};
		temp.reduce();
		return temp;
    }
	
	Rational Rational::operator=(const Rational & n)
	{
		Rational temp {(top = n.top), (bottom = n.bottom)};
		temp.reduce();
		return temp;
	}
	
	//Constants
	const Rational Rational::ZERO(0,1);
	const Rational Rational::UNDEFINED(0,0);
	const Rational Rational::INFINITY(1,0);
	

	//Friend Operators
	bool operator<(const Rational & n, const Rational & b)
	{
		if( n.top < b.top && n.bottom < b.bottom)
			return true;
		else
			return false;
	}

	bool operator>(const Rational & n, const Rational & b)
	{
		if( n.top > b.top && n.bottom > b.bottom)
			return true;
		else
			return false;
	}

	bool operator==(const Rational & n, const Rational & b)
	{
		if( n.top == b.top && n.bottom == b.bottom)
			return true;
		else
			return false;
	}
	
	
}	