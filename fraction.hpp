/*
 * Module Fraction contient la definition d'une fraction
 * mathematique et les differents operations et une fonction de
 * simplification pour simplifier une fraction
 */

#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cmath>

#include "nombre_premier.hpp"

template <typename F>
class Fraction
{
	/* Classe fraction pour le calcule des nombres fractionnaire
	 *
	 */
	private:
		// a est le numerateur
		// b est le denomunateur
		F a_, b_;
	public:
		Fraction(F a, F b)
		{
			// initialisation du numerateur et le denomunateur
			a_ =a; b_ = b; 
		}

		Fraction() : a_(0), b_(0) {}
		
		/* operateur d'addition de deux fraction et retour une fraction */
		Fraction operator + (Fraction x)
		{
			Fraction result;
			result.a_ = this -> a_ * x.b_ + x.a_ * this-> b_;
			result.b_ = this -> b_ * x.b_;
			return result;
		}

		/*operateur de soustraction de deux fraction et retour une fraction
		 * formule : a/b - c/d  = ( a*d + c*b ) / (b*b)
		 */
		Fraction operator - (const Fraction & x)
		{
			Fraction result;
			result.a_ = this -> a_ * x.b_ - x.a_ * this -> b_;
			result.b_ = this -> b_ * x.b_;

			return result;
		}

		
		template <typename T>
		friend Fraction<T> operator + (Fraction<T>, T);
		

		/*
		 * operateur de multiplication de deux fraction
		 * formule : a/b * c/d = ( a * c) / ( b*d)
		 */

		Fraction operator *(const Fraction &x)
		{
			Fraction result;
			result.a_ = this -> a_ * x.a_;
			result.b_ = this -> b_ * x.b_;

			return result;
		}

		/*
		 * operateur de division de deux fractions
		 * formule : (a /b) / (c /d) = ( a*d) / (b*c)
		 */
		Fraction operator / (Fraction x)
		{
			Fraction result;

			result.a_ = this -> a_ * x.b_;
			result.b_ = this -> b_ * x.a_;

			return result;
		}
		
		/*
		 * operateur de comparaision de deux fraction
		 */
		bool operator == (Fraction x)

		{
			if ( this -> a_ == x.a_ && this -> b_ == x.b_)
				return true;
			else return false;
		}

		bool operator != (Fraction x)
		{
			if ( this -> a_ != x.a_ && this -> b_ != x.b_)
				return true;
			else
				return false;
		}
		
		// operateur d'addition type Fraction + ( int, float, double ...)
		template <typename T>
		friend Fraction<T> operator + (T, Fraction<T>);

		template <typename T>
		friend Fraction<T> operator - (T, Fraction<T>);
	
		template <typename T>
		friend Fraction<T> operator - (Fraction<T>, T);


		template <typename T>
		friend Fraction<T> operator *(Fraction<T>, T);

		template <typename T>
		friend Fraction<T> operator * (T, Fraction<T>);

		template <typename T>
		friend Fraction<T> operator / (Fraction<T>, T);

		template<typename T>
		friend Fraction<T> operator / (T, Fraction<T>);


		template <typename T>
		friend Fraction<T> simplication(Fraction <T>);

		/*
		template <typename T>
		Fraction<T> operator - (T)
		{
			Fraction<T> result;
			result.a_ = - this -> a_;
			result.b_ = this -> b_;
			return result;
		}*/

		template <typename T>
		operator T()
		{
			return T( this -> a_) / T(this -> b_) ;
		}
		
		template <typename U>
		friend std::ostream & operator << (std::ostream& os, Fraction<U> sortie);

		template <typename T>
		friend Fraction<T> power(const Fraction<T>&, T );

};

template <typename T>
Fraction<T> power(const Fraction<T> &f, T p)
{
	Fraction<T> result;
	result.a_ = pow( f.a_, p) ;
	result.b_ = pow( f.b_, p) ; 

	return result;
}

template <typename T, typename V>
bool erase(T & cont, V valeur )
{
	auto itr_debut { std::begin(cont ) };
	auto itr_fin { std::end(cont)};

	auto search  { std::find(itr_debut, itr_fin, valeur) };
	if ( search != itr_fin)
	{
		
		cont.erase(search);
		return true;
	}
	
	else return false;
}

template <typename T>
Fraction<T> simplication(Fraction<T> a)
{
	/*
	 * fonction de simplification d'un fraction
	 * par la methode de decomposition en produit de
	 * facteur premier le numerateur et le denonumateur
	 */

	std::vector<int> numerateur_premier = decomposition(a.a_);
	std::vector<int> denomunateur_premier = decomposition(a.b_);
	
	auto iter_fin { std::end(denomunateur_premier) };

	auto iter_debut  { std::begin(denomunateur_premier) };

	std::vector<int> index;
	
	for ( auto i : numerateur_premier)
	{
		if ( erase(denomunateur_premier, i ))

			index.push_back(i);
	}

	for(auto i: index)
	{
		erase(numerateur_premier, i);
	}


	
	auto numerateur_produit { std::accumulate(std::cbegin(numerateur_premier),
			std::cend(numerateur_premier), 1,
			std::multiplies<int>{}) };


	auto denomunateur_produit { std::accumulate( std::cbegin(denomunateur_premier),
		std::cend(denomunateur_premier), 1,
		std::multiplies<int>{} ) };
	

	return Fraction<int>(numerateur_produit, denomunateur_produit);

}

template <typename F>
std::ostream& operator <<( std::ostream& os, Fraction<F> sortie)
		{
			os << sortie.a_ << "/" << sortie.b_;
			return os;
		}

template <typename T>
Fraction<T> operator + (Fraction<T> x, T b)
{
	Fraction<T> result;
	result.a_ = x. a_ + b* x.b_;
	result.b_ = x. b_;
	return result;
}

template <typename T>
Fraction<T> operator + (T b, Fraction<T> x)
{
	return x + b;
}

template <typename T>
Fraction<T> operator - (Fraction<T> x, T b)
{
	Fraction<T> result;
	result.a_ = x.a_ - b * x.b_;
	result.b_ = x.b_;

	return result;
}

template <typename T>
Fraction<T> operator - (T b, Fraction<T> x)
{
	return x - b;
}

template <typename T>
Fraction<T> operator * (Fraction<T> x, T b)
{
	Fraction<T> result;
	result.a_ = x.a_ * b;
	result.b_ = x.b_;
	return result;
}

template <typename T>
Fraction<T> operator * ( T b, Fraction<T> x)
{
	return x * b;
}

template <typename T>
Fraction<T> operator / (Fraction<T> x, T b)
{
	Fraction<T> result;

	result.a_ = x.a_ -> a_;
	result.b_ = x.b_ * b;

	return b;
}

template <typename T>
Fraction<T> operator / (T b, Fraction<T> x)
{
	return x / b;
}

#endif
