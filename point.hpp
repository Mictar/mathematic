/*
 * Module Point contenant la definition d'un point geometrie
 * et contenant les differents operations sur les point
 * comme par exemples: le calcul de la norme entre deux
 * point ( distance entre deux points )
 */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

template <typename T>
class Point
{
	private:
		T x_, y_;
	public:
		Point(T abs = 0, T ord = 0): x_(abs), y_(ord) {}
		
		// fonctin amie pour la sortie standart
		template <typename F>
		friend std::ostream & operator << (std::ostream &, Point<F>);

		// fonction amie pour la calcule de la norme
		// de deux points (distance entre deux point)
		template <typename U>
		friend double norme (const Point<U>&, const Point<U>&);
		
};

template <typename T>
std::ostream & operator << ( std::ostream & sortie, Point<T> p)
{
	sortie << "{ " << p.x_ << ", " << p.y_ << " }";

	return sortie;
}

template <typename T>
double norme (const Point<T>& a, const Point<T>& b)
{
	T diff_x = a.x_ - b.x_;
	T diff_y = a.y_ - b.y_;

	return sqrt( diff_x * diff_x + diff_y * diff_y );
}

#endif
