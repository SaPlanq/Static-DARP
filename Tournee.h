/*
 * Tournee.h
 *
 *  Created on: 7 fevr. 2012
 *      Author: deleplan
 */

#ifndef TOURNEE_H_
#define TOURNEE_H_

using namespace std;

#include <list>
#include <utility>
#include <iostream>
#include <fstream>
#include "Noeud.h"

using namespace std;

class Tournee {
protected:
	list<Noeud*> listeNoeud;
	// itTab permet de garder une marque entre les noeuds deja tester par evalTour2VH ou pas
	list<Noeud * >::iterator itTab;
public:
	// Constructeur par defaut
	Tournee();
	// Constructeur de recopie
	Tournee(const Tournee & inTournee);
	// Surcharge =
	Tournee & operator = ( const Tournee & inTournee);

	// Fonctions amies
	friend ostream & operator << (ostream & sortie, Tournee & inTournee);

	// Destructeur
	virtual ~Tournee();

    list<Noeud*>::iterator getItTab() const
    {
        return itTab;
    }

    void setItTab(list<Noeud*>::iterator itTab)
    {
        this->itTab = itTab;
    }

    list<Noeud*> getListeNoeud() const
    {
        return listeNoeud;
    }

    void setListeNoeud(list<Noeud*> listeNoeud)
    {
        this->listeNoeud = listeNoeud;
    }

    void ajoutNoeud(Noeud * noeud)
    {
      listeNoeud.push_back(noeud);
    }

    list<Noeud*>::iterator getItDebut()
    {
      return listeNoeud.begin();
    }

    list<Noeud*>::iterator getItEnd()
    {
      return listeNoeud.end();
    }

    list<Noeud *>::iterator insererNoeud(list<Noeud *>::iterator itSucc, Noeud * in)
    {
      return listeNoeud.insert(itSucc,in);
    }

    list<Noeud *>::iterator sortirNoeud(list<Noeud *>::iterator itASortir)
    {
      return listeNoeud.erase(itASortir);
    }

    void setTempsDePassage(list<Noeud *>::iterator itNoeud, double t)
    {
      (*itNoeud)->setT(t);
    }


};

#endif /* TOURNEE_H_ */
