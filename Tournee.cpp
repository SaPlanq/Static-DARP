/*
 * Tournee.cpp
 *
 *  Created on: 7 fevr. 2012
 *      Author: deleplan
 */

#include "Tournee.h"

Tournee::Tournee(const Tournee & inTournee)
{
	// La STL a surcharge l'affectation de ses conteneurs
      listeNoeud = inTournee.listeNoeud;
}

Tournee::Tournee() {

}

/*
 * Surcharge operateur =
 */
Tournee & Tournee::operator = ( const Tournee & inTournee)
{
	// La STL a surcharge l'affectation de ses conteneurs
      listeNoeud = inTournee.listeNoeud;
	return *this;
}


// Fonctions amies de la classe
/*
 * Surcharge <<
 */
ostream & operator << (ostream & sortie, Tournee & inTournee)
{
        sortie << "Affichage de la tournee  : " << endl ;
        for ( list<Noeud*>::iterator itFor=inTournee.listeNoeud.begin();
                        itFor!=inTournee.listeNoeud.end();itFor++)
        {
                sortie << " adresse : " << *itFor << endl << "  -> " << endl << **itFor << endl;
        }
        return sortie;
}

/*
 * Destructeur
 */
Tournee::~Tournee() {

}
