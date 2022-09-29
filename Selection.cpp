/*
 * Selection.cpp
 *
 *  Created on: 28 fevr. 2012
 *      Author: deleplan
 */

#include "Selection.h"

Selection::Selection()
{

}

/*
 * Constructeur de recopie
 */
Selection::Selection(const Selection & inSelection)
{
   N1 = inSelection.N1;
   N2 = inSelection.N2;
   NbCarLibre = inSelection.NbCarLibre;
   LibreXY = inSelection.LibreXY;
}

/*
 * Surcharge =
 */
Selection &
Selection::operator =( Selection & inSelection)
{
  N1 = inSelection.N1;
  N2 = inSelection.N2;
  NbCarLibre = inSelection.NbCarLibre;
  LibreXY = inSelection.LibreXY;
  return * this;
}

/*
 * Fonction renvoyant vrai si le vehicule est present dans
 * les 4uplets
 */
bool
Selection::kPresent(int k)
{
  for ( list<QuatreUplet *>::iterator it = getDebutLibreXY();
      it !=  getEndLibreXY() ; it++)
    {
      if ((*it)->getK() == k) return true;
    }
  return false;
}


void
Selection::effaceQuatreUplet(list<QuatreUplet *>::iterator it)
{
  LibreXY.erase(it);
}

/*
 * Fonction qui insere dans une liste triee sans aucun doublon
 * le tri se fait de la plus petite valeur v du quatreUplet a la
 * plus grande
 */
void
Selection::insertListeTriee(QuatreUplet * quatreUplet)
{
  bool continu = true;
  list<QuatreUplet *>::iterator itListe = LibreXY.begin();
  while (continu && (itListe != LibreXY.end()))
    {
      if (quatreUplet->getV() < (*itListe)->getV())
        {
          continu = false;
        }
      else itListe++;
    }
  LibreXY.insert(itListe, quatreUplet);
}


Selection::~Selection()
{

}

// Fonctions Amies
ostream &
operator <<(ostream & sortie,  Selection & inSelection)
{
  sortie        << "  Selection. N1 = " << inSelection.N1 << " N2 = "
                << inSelection.N2 << " NbCarLibre = "
                << inSelection.NbCarLibre << ". Les QuatreUplet : " << endl;
  for ( list<QuatreUplet *>::iterator it = inSelection.LibreXY.begin() ; it != inSelection.LibreXY.end(); it++)
    {
      sortie << (*it) ;
    } sortie << endl;
  return sortie;
}


