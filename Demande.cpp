/*
 * Demande.cpp
 *
 *  Created on: 7 fevr. 2012
 *      Author: deleplan
 */

#include "Demande.h"

Demande::Demande()
{
  noeudOrigine = new Noeud();
  noeudDestination = new Noeud();
  noeudOut = new Noeud();
  noeudIn = new Noeud();
  noeudOrigine->setStatus(0);
  noeudOrigine->setIndiceDemande(-1);
  noeudDestination->setStatus(1);
  noeudDestination->setIndiceDemande(-1);
  noeudOut->setStatus(4);
  noeudIn->setStatus(5);
  noeudOut->setIndiceDemande(-1);
  noeudIn->setIndiceDemande(-1);


  FOrigineMin = -1;
  FOrigineMax = -1;
  FDestinationMin = -1;
  FDestinationMax = -1;
  origineX = -1;
  origineY = -1;
  destinationX = -1;
  destinationY = -1;
  delta = -1;
  deltaSave = -1;
  Qi = -1;
}

/*
 * Constructeur de recopie
 */
Demande::Demande(const Demande & inDemande)
{
  FOrigineMin = inDemande.FOrigineMin;
  FOrigineMax = inDemande.FOrigineMax;
  FDestinationMin = inDemande.FDestinationMin;
  FDestinationMax = inDemande.FDestinationMax;
  origineX = inDemande.origineX;
  destinationX = inDemande.destinationX;
  origineY = inDemande.origineY;
  destinationY = inDemande.destinationY;
  delta = inDemande.delta;
  deltaSave = inDemande.deltaSave;
  Qi = inDemande.Qi;
  noeudOrigine = inDemande.noeudOrigine;
  noeudDestination = inDemande.noeudDestination;
  noeudOut =  inDemande.noeudOut;
  noeudIn  =  inDemande.noeudIn;
}

/*
 * Constructeur non par defaut
 */
Demande::Demande(double inFOrigineMin, double inFOrigineMax,
    double inFDestinationMin, double inFDestinationMax, double inorigineX,
    double indestinationX, double inorigineY, double indestinationY,
    double indelta, double indeltaSave, double inQi, int indiceDemande)
{
  noeudOrigine->setStatus(0);
  noeudOrigine->setIndiceDemande(indiceDemande);
  noeudDestination->setStatus(1);
  noeudDestination->setIndiceDemande(indiceDemande);
  FOrigineMin = inFOrigineMin;
  FOrigineMax = inFOrigineMax;
  FDestinationMin = inFDestinationMin;
  FDestinationMax = inFDestinationMax;
  origineX = inorigineX;
  destinationX = indestinationX;
  origineY = inorigineY;
  destinationY = indestinationY;
  delta = indelta;
  deltaSave = indeltaSave;
  Qi = inQi;

  cout << "Constructeur Demande non par defaut" << endl;
}

/*
 * Surcharge =
 */
Demande &
Demande::operator =(const Demande & inDemande)
{
  noeudOrigine = inDemande.noeudOrigine;
  noeudDestination = inDemande.noeudDestination;
  noeudOut =  inDemande.noeudOut;
  noeudIn  =  inDemande.noeudIn;
  FOrigineMin = inDemande.FOrigineMin;
  FOrigineMax = inDemande.FOrigineMax;
  FDestinationMin = inDemande.FDestinationMin;
  FDestinationMax = inDemande.FDestinationMax;
  origineX = inDemande.origineX;
  destinationX = inDemande.destinationX;
  origineY = inDemande.origineY;
  destinationY = inDemande.destinationY;
  delta = inDemande.delta;
  deltaSave = inDemande.deltaSave;
  Qi = inDemande.Qi;

  return *this;
}

/*
 * Surcharge de <<
 */
ostream &
operator <<(ostream & sortie, Demande & inDemande)
{
  sortie << "FOrigineMin : " << inDemande.FOrigineMin << endl
      << "FOrigineMax : " << inDemande.FOrigineMax << endl
      << "FDestinationMin : " << inDemande.FDestinationMin << endl
      << "FDestinationMax : " << inDemande.FDestinationMax << endl
      << "origineX : " << inDemande.origineX << endl << "destinationX : "
      << inDemande.destinationX << endl << "origineY : " << inDemande.origineY
      << endl << "destinationY : " << inDemande.destinationY << endl
      << "delta : " << inDemande.delta << "deltaSave : " << inDemande.deltaSave
      << endl << "Qi : " << inDemande.Qi
      << endl;
  sortie << "-Noeud Origine " << *(inDemande.noeudOrigine) << endl
      << "-Noeud Destination " << *(inDemande.noeudDestination) << endl;
  return sortie;
}

Demande::~Demande()
{
	//	delete noeudOrigine;
	//	delete noeudDestination;
}
