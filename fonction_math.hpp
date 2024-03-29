/*
 * Module contenant les fonctions mathematiques
 * usuelle comme la resolution d'une eqution du premier, deux degre
 */

#ifndef FONCTION_MATH_HPP
#define FONCTION_MATH_HPP


#include <iostream>
#include <tuple>
#include <cmath>
#include <functional>

template <typename T>
std::pair<T, T> equation_2_degre(const T& a, const  T& b,const T& c)
{
	/*
	 * fonction de resolution reel d'une equation du deuxieme
	 * degre a une inconnue
	 * formule: ax^2 + bx + c = 0
	 */

	// calcule du discriminant deltat
	T delta = b*b - 4*(a*c);
	
	T x_1, x_2;

	if ( delta > 0)
	{
		T sqrt_delta = sqrt( delta);
		
		T two_a = 2 * a;
	
		x_1 =  (  -b  + sqrt_delta ) / two_a;
		x_2 =  (  -b  - sqrt_delta ) / two_a;
		
		return { x_1, x_2};
	}
	else
		
		return {  };
}


template <typename T>
T equation_1_degre(const T &a, const T& b, const T &c)
{
	/*
	 * fonction de resolution d'une equation d'un premier
	 * degre a une inconnue 
	 * formule : ax + b = c donc c = (c -b) / a
	 */
	return ( c -b ) / a;
}

template <typename T>
std::pair<T, T> equation_1_degre_2_inconnue(const T &a, const T b, const T& c,
	       const T & d, const T & e, const T & f)
{
	/*
	 * fonction de resolution d'une equation du premier degre a
	 * deux inconnues
	 * formule : (1) ax + by = c; (2) dx + ey = f
	 */


	return { a, b};

}

template <typename T>
std::function<T (T)> detect_droite_from_point(
		const T& x1, 
		const T& y1, 
		const T& x2,
		const T& y2)
{
	T pente = ( y2 - y1 ) / ( x2 - x1);

	T b  = y1 - x1 * pente;

	return [pente, b](T x) { return x * pente + b; };

}

template <typename T>
std::function<T (T)> generate_equation_2(const T& a, const T& b, const T& c)
{
	return [a, b, c](const T &x) { return a*x*x + b * x + c; };
}

template <typename T>
bool verifie_point( std::function<T (T)> fonc, const T& valeur, const T& result)
{
	return fonc(valeur) == result ? true: false;
}



#endif
