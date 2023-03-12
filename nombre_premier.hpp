#include <iostream>
#include <vector>

bool nombrePremier(int nombre)
{
	/*
	 * fonction de verification d'un nombre premier
	 * retour true si le nombre est premier
	 * sinon retour false
	 */

	int nombre_diviseur =0;
	for (int i = 2; i < nombre ; ++i)
	{
		if ( ( nombre % i) == 0 )
			return false;
	}
	return true;
}

int nombrePremierSuivant(int nombre=2)
{
	/*
	 * fonction de recherche de nombre premier suivant
	 */
	int i = nombre + 1;

	while(true)
	{
		if ( nombrePremier(i) )
			return i;
		else
			i++;
	}
}

std::vector<int> decomposition(int nombre, int default_p=2)
{
	/*
	 * fonction de decomposition d'un nombre en produit
	 * de facteur premier
	 */

	// un conteneur vector pour stocker les nombres premiers
	std::vector<int> result;

	// le nombre_premier en cour
	int nombre_premier = default_p;
	
	// le dividant ( le nombre en cour )
	int dividant = nombre;

	while(  dividant != 1)  {
		
		if ( ( dividant % nombre_premier) == 0 )
		{
			dividant /= nombre_premier; result.push_back(nombre_premier);

		}
		else
		{
			nombre_premier = nombrePremierSuivant(nombre_premier);
		}
	}

	return result;
}
