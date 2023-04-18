

#include "fraction.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "point.hpp"
#include <complex>
#include "fonction_math.hpp"

template <typename T>
void affiche(T a)
{
	for( auto i : a)
		std::cout << i << "\n";
}

//std::boolalpha;

int main(int argc, char** argv)
{

	auto droite = detect_droite_from_point<float>(1, 3, 2, 2);
	
	auto courbe = generate_equation_2<float>(2, 3, -5);
	
	std::cout << droite(2) << "\n";
	std::cout << std::boolalpha << verifie_point<float>(droite, 1, 4) << "\n";
	
	std::cout << std::boolalpha<< verifie_point<float>(courbe, 1, 3) << std::endl;
	return 0;
}
