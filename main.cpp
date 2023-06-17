#include "algorithm.hpp"
#include "fraction.cpp"

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	Fraction<int> t {2, 4};
	std::cout << t << std::endl;
	std::cout << std::boolalpha <<  nombrePremier( std::stoi(argv[1]) ) << std::endl;

	return 0;
}


