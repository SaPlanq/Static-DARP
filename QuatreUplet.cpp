/*
 * QuatreUplet.cpp
 *
 *  Created on: 28 févr. 2012
 *      Author: deleplan
 */

#include "QuatreUplet.h"

QuatreUplet::QuatreUplet()
{
  k = -1; v = -1;
}

/*
 * Constructeur non par defaut
 */
QuatreUplet::QuatreUplet(int inK, int inV, list<Noeud *>::iterator inXIt,
    list<Noeud *>::iterator      inYIt)
{
  k = inK;
  v = inV;
  xIt = inXIt;
  yIt = inYIt;
}

/*
 * Constructeur de recopie
 */
QuatreUplet::QuatreUplet(const QuatreUplet & inQuatreUplet)
{
  k             = inQuatreUplet.k ;
  v             = inQuatreUplet.v;
  xIt           = inQuatreUplet.xIt;
  yIt           = inQuatreUplet.yIt;
}

/*
 * Surcharge =
 */
QuatreUplet &
QuatreUplet::operator =(const QuatreUplet & inQuatreUplet)
{
  k             = inQuatreUplet.k ;
  v             = inQuatreUplet.v;
  xIt           = inQuatreUplet.xIt;
  yIt           = inQuatreUplet.yIt;
  return * this;
}

/*
 * Surcharge de < pour la methode sort de list
 */
bool
QuatreUplet::operator< (const QuatreUplet & inQuatreUplet) const
{
        // On teste selon la valeur rendu par eval2
        return v < inQuatreUplet.v;
}

bool
QuatreUplet::operator== (const QuatreUplet & inQuatreUplet) const
{
        // On teste selon la valeur rendu par eval2
        return (v == inQuatreUplet.v)&&(k == inQuatreUplet.k)&&(xIt==inQuatreUplet.xIt)&&(yIt==inQuatreUplet.yIt);
}

QuatreUplet::~QuatreUplet()
{
}

// Fonctions Amies
ostream &
operator <<(ostream & sortie, QuatreUplet & inQuatreUplet)
{
  sortie        << "    4-uplet : (k, v) = (" <<inQuatreUplet.k<< "," <<inQuatreUplet.v<< ")"
                << " x sur dem " << (*(inQuatreUplet.xIt))->getIndiceDsDist() << " statut "
                << (*(inQuatreUplet.xIt))->getStatus()
                << " et y dem "  << (*(inQuatreUplet.yIt))->getIndiceDsDist() << " statut "
                << (*(inQuatreUplet.yIt))->getStatus()
                << endl;
  return sortie;
}



