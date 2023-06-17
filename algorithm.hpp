#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
#include <vector>
#include <complex>

// fonction de decomposition en nombre en produit de facteur premier
std::vector<int> decomposition(int nombre, int default_p);


// fonction verifiant si un nombre est premier ou non
bool nombrePremier(int);

// fonction de recherche de nombre premier suivant en fonction du precedant
int nombrePremierSuivant(int nombre);


// fonction de translation complex avec un vecteur
typedef std::complex<float> cfloat;
cfloat& translation( const cfloat& vect, 
		    cfloat &point);

// fonction de rotation complex autour d'un point d'origine
cfloat& rotation( const cfloat& origine,
		  cfloat& point,
		  float angle);

#endif
