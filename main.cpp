

#include "fraction.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "point.hpp"
#include <complex>

template <typename T>
void affiche(T a)
{
	for( auto i : a)
		std::cout << i << "\n";
}

int main(int argc, char** argv)
{

	std::complex a {1, 1};

	std::cout << sin(a) << "\n";
	return 0;
}
