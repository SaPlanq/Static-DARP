/*
 * Noeud.cpp
 *
 *  Created on: 7 fevr. 2012
 *      Author: deleplan
 */

#include "Noeud.h"

Noeud::Noeud()
{
  k = -1;
  status = -1;
  indiceDemande = -1;
  indiceDsDist = -1;
  FPropageMin = 0.0;
  FPropageMax = 999999.9;
  FPropageMinSave = 0.0;
  FPropageMaxSave = 999999.9;
  FMax = 999999.9;
  FMin = 0.0;
  ChT = 0.0;
  t = 0.0;
  tSave = 0.0;
  X = -1;
  Y = -1;
  Mark = false;
}

/**
 * Constructeur de recopie
 */
Noeud::Noeud(const Noeud & inNoeud)
{
  status = inNoeud.status;
  indiceDemande = inNoeud.indiceDemande;
  FPropageMin = inNoeud.FPropageMin;
  FPropageMax = inNoeud.FPropageMax;
  FPropageMinSave = inNoeud.FPropageMinSave;
  FPropageMaxSave = inNoeud.FPropageMaxSave;
  FMin = inNoeud.FMin;
  FMax = inNoeud.FMax;
  ChT = inNoeud.ChT;
  t = inNoeud.t;
  tSave = inNoeud.tSave;
  k = inNoeud.k;
  tempsDeService = inNoeud.tempsDeService;
  X = inNoeud.X;
  Y = inNoeud.Y;
  Mark = inNoeud.Mark;
}

/*
 * Surcharge =
 */
Noeud &
Noeud::operator =(const Noeud & inNoeud)
{
  status = inNoeud.status;
  indiceDemande = inNoeud.indiceDemande;
  FPropageMin = inNoeud.FPropageMin;
  FPropageMax = inNoeud.FPropageMax;
  FPropageMinSave = inNoeud.FPropageMinSave;
  FPropageMaxSave = inNoeud.FPropageMaxSave;
  FMin = inNoeud.FMin;
  FMax = inNoeud.FMax;
  ChT = inNoeud.ChT;
  t = inNoeud.t;
  tSave = inNoeud.tSave;
  k = inNoeud.k;
  tempsDeService = inNoeud.tempsDeService;
  X = inNoeud.X;
  Y = inNoeud.Y;
  Mark = inNoeud.Mark;
  return *this;
}

/*
 * FOnction qui reeinitialise un
 * noeud comme si la demande
 * venait d etre allouee
 */

void Noeud::reinitNoeud()
{
  k = -1;
  status = -1;
  indiceDemande = -1;
  FPropageMin = 0.0;
  FPropageMax = 0.0;
  FPropageMinSave = 0.0;
  FPropageMaxSave = 0.0;
  FMax = 0.0;
  FMin = 0.0;
  ChT = -1.0;
  t = 0.0;
  tSave = 0.0;
  X = -1;
  Y = -1;
  Mark = false;
}
// Fonctions amies de la classe
/*
 * Surcharge <<
 */
ostream &
operator <<(ostream & sortie, Noeud & noeud)
{
  sortie << "Noeud : " << "   Status : " << noeud.status << " indiceDemande "
      << noeud.indiceDemande << " indiceDist : " << noeud.indiceDsDist << "   k : " << noeud.k << endl;
  //      sortie << "         FPropageMin : " << noeud.FPropageMin << endl;
  //  sortie << "   FPropageMax : " << noeud.FPropageMax << endl ;
  sortie << " ChT : " << noeud.ChT << "        tSave : " << noeud.tSave << "              t " << noeud.t << endl ;
  sortie << " FMIN     " << noeud.FMin
      <<  "                                 FMAX     " << noeud.FMax  << endl;
  sortie << " FPropageMinSave " << noeud.FPropageMinSave
      <<  "                           FPropageMaxSave " << noeud.FPropageMaxSave  << endl;
  sortie << " FPropageMin " << noeud.FPropageMin
       << "                           FPropageMax " << noeud.FPropageMax << endl;
  sortie << "Mark   : " << noeud.Mark << "    X et Y : " << noeud.X << "  " << noeud.Y << endl;
  //  sortie << "et les propagesSave : " << " FMinSave : " << noeud.FPropageMinSave
  //      << " FmaxSave : " << noeud.FPropageMaxSave << endl;
  return sortie;
}

Noeud::~Noeud()
{

}
