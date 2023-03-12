#include <iostream>
#include <tuple>
#include <cmath>
#include <functional>
#include "fraction.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

/*
template <typename F>
class Fraction
{
	private:
		F a_, b_;
	public:
		Fraction(F a, F b)
		{
			a_ =a; b_ = b; 
		}
		Fraction() : a_(0), b_(0) {}

		Fraction operator + (Fraction x)
		{
			Fraction result;
			result.a_ = this -> a_ * x.b_ + x.a_ * this-> b_;
			result.b_ = this -> b_ * x.b_;
			return result;
		}
		
		template <typename U>
		friend std::ostream & operator << (std::ostream& os, Fraction<U> sortie);

};

template <typename F>
std::ostream& operator <<( std::ostream& os, Fraction<F> sortie)
		{
			os << sortie.a_ << "/" << sortie.b_;
			return os;
		}
*/
template <typename T>
std::pair<T, T> equation_2_degre(T a, T b, T c)
{
	T delta = b*b - 4*(a*c);
	
	T x_1, x_2;


	std::cout << delta << "\n";
	std::cout <<"racine carre de delta :"<< sqrt(delta) << "\n";
	std::cout<<  -1 * delta << "\n";
	
	if ( (double) delta > 0)
	{
		float sqrt_delta = sqrt( delta);
		
		T two_a = float(2) * a;
		float facteur = 1;
		x_1 =  ( ( facteur* b ) + sqrt_delta ) / two_a;
		x_2 =  ( ( facteur* b)  - sqrt_delta ) / two_a ;
		
		return { x_1, x_2};
	}
	else
		
		return {  };
}


int main(int argc, char** argv)
{
	
	Fraction<float> x {3, 2};
	Fraction<float> z {5, 1};
	Fraction<float> t {2, 1};

	auto result = equation_2_degre(x, z, t);
	
	//std::cout << " x1 : " << result.first  << "  y :" << result.second<< "\n";
	return 1;
}

