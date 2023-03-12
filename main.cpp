#include "fraction.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
void affiche(T a)
{
	for( auto i : a)
		std::cout << i << "\n";
}

int main(int argc, char** argv)
{

	
	Fraction<int> a {3, 2}, b {5, 2}, c{2, 1};

	Fraction<int> delta = -1 * b;

	//Fraction x = simplication(delta);
	

	//x = y + y;

	std::cout <<(delta) <<"  " << (float)delta<< "\n";
	//std::cout << ( simplication( Fraction(10, 28) ) ) << "\n";

	return 0;
}
