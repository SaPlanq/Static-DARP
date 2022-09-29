/*
 * QuatreUplet.h
 *
 *  Created on: 28 févr. 2012
 *      Author: deleplan
 */

#ifndef QUATREUPLET_H_
#define QUATREUPLET_H_

#include <list>
#include "Noeud.h"

class QuatreUplet
{
protected:
  int                           	k;
  double                       	 	v;
  list<Noeud *>::iterator         	xIt;
  list<Noeud *>::iterator         	yIt;
public:
  QuatreUplet();
  QuatreUplet(int inK, int inV, list<Noeud *>::iterator inXIt,
      list<Noeud *>::iterator      inYIt);
  QuatreUplet(const QuatreUplet & inQuatreUplet);
  QuatreUplet &
  operator =(const QuatreUplet & inQuatreUplet);
  bool operator <(const QuatreUplet & inQuatreUplet) const ;
  bool operator== (const QuatreUplet & inQuatreUplet) const;
  virtual
  ~QuatreUplet();
  // Fonctions amies
  friend ostream &
  operator <<(ostream & sortie, QuatreUplet & inQuatreUplet);

  // Getter et setter
  list<Noeud *>::iterator getXIt() const
  {
      return xIt;
  }

  list<Noeud *>::iterator getYIt() const
  {
      return yIt;
  }

  int getK() const
  {
      return k;
  }

  double getV() const
  {
      return v;
  }

  void setXIt(list<Noeud *>::iterator xIt)
  {
      this->xIt = xIt;
  }

  void setYIt(list<Noeud *>::iterator yIt)
  {
      this->yIt = yIt;
  }

  void setK(int k)
  {
      this->k = k;
  }

  void setV(double v)
  {
      this->v = v;
  }
};

#endif /* QUATREUPLET_H_ */
