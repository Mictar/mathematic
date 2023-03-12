#include <iostream>
#include <cassert>
#include "fraction.hpp"


int main(int argc, char** argv)
{
	Fraction<int> a { 1, 3}, b {3, 3}, c;

	c = a + b;


	assert( c == Fraction(12, 9) && "addition de deux fraction ");
	
	assert ( c != Fraction( 3, 3) && "addiction de a et b not egale a 3/3" );

	c = a - b;

	assert( c == Fraction(-6, 9) && "soustraction de a et b est egale à -6/9");

	assert ( c != Fraction(3, 3) && "soustraction de a t b not egale à 3/3");

	c = a * b;
	
	std::cout << ( a * b == Fraction<int>(3, 3) )<< "\n";
	assert ( c == Fraction(3, 9) && "multiplication de deux fraction a et b est egale à 3/9");

	assert ( c != Fraction<int>(3, 3) && "multiplication de deux fraction n'est pas egale à 3/3");

	c = a / b;

	assert (c == Fraction(3, 9) && "division de deux fraction a et b est egale à : 3/9");


	return 0;
}
