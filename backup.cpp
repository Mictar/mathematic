#include <iostream>
#include <tuple>
#include <cmath>
#include <functional>

using std::placeholders::_1;
using std::placeholders::_2;

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

template <typename T>
std::pair<T, T> equation_2_degre(T a, T b, T c)
{
	T delta = b*b - 4*(a*c);
	
	T x_1, x_2;

	if (delta > 0)
	{
		T sqrt_delta = sqrt(delta);
		
		T two_a = 2 * a;

		x_1 =  ( -b + sqrt_delta ) / two_a;
		x_2 =  ( -b - sqrt_delta ) / two_a ;
		
		return { x_1, x_2};
	}
	else
		return { NULL, NULL};
}


int main(int argc, char** argv)
{
	
	Fraction<int> x {1, 4};
	Fraction<int> z {1, 4};
	z = x + x;
	std::cout << z << "\n";
	return 1;
}

