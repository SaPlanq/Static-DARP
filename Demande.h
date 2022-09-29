/*
 * Demande.h
 *
 *  Created on: 7 fevr. 2012
 *      Author: deleplan
 */

#ifndef DEMANDE_H_
#define DEMANDE_H_

#include "Noeud.h"

class Demande {
protected:
	double 		FOrigineMin;
	double 		FOrigineMax;
	double 		FDestinationMin;
	double 		FDestinationMax;
	double 		origineX;
	double 		origineY;
	double 		destinationX;
	double 		destinationY;
	double 		delta;
	double		deltaSave;
	double 		Qi;
public:
	Noeud *         noeudOrigine;
	Noeud *         noeudDestination;
	Noeud *         noeudOut;
	Noeud *         noeudIn;
public:
	// Constructeur par defaut
	Demande();
	// Constructeur de recopie
	Demande(const Demande & inDemande);
	Demande(
			double 		inFOrigineMin,
			double 		inFOrigineMax,
			double 		inFDestinationMin,
			double 		inFDestinationMax,
			double 		inorigineX,
			double 		indestinationX,
			double 		inorigineY,
			double 		indestinationY,
			double 		indelta,
			double          indeltaSave,
			double 		inQi,
			int 		indiceDemande);
	// Surcharge =
	Demande & operator = (const Demande & inDemande);
	// Surcharge amie <<
	friend ostream & operator << (ostream & sortie, Demande & inDemande);
	virtual ~Demande();

    double getDeltaSave() const
    {
        return deltaSave;
    }

    void setDeltaSave(double deltaSave)
    {
        this->deltaSave = deltaSave;
    }

    Noeud * getNoeudIn() const
    {
        return noeudIn;
    }

    Noeud *getNoeudOut() const
    {
        return noeudOut;
    }

    void setNoeudIn(Noeud *noeudIn)
    {
        this->noeudIn = noeudIn;
    }

    void setNoeudOut(Noeud *noeudOut)
    {
        this->noeudOut = noeudOut;
    }

    Noeud *getNoeudDestination() const
    {
        return noeudDestination;
    }

    Noeud * getNoeudOrigine() const
    {
        return noeudOrigine;
    }

    void setNoeudDestination(Noeud *noeudDestination)
    {
        this->noeudDestination = noeudDestination;
    }

    void setNoeudOrigine(Noeud *noeudOrigine)
    {
        this->noeudOrigine = noeudOrigine;
    }

    double getDelta() const
    {
        return delta;
    }

    double getDestinationX() const
    {
        return destinationX;
    }

    double getDestinationY() const
    {
        return destinationY;
    }

    double getFDestinationMax() const
    {
        return FDestinationMax;
    }

    double getFDestinationMin() const
    {
        return FDestinationMin;
    }

    double getFOrigineMax() const
    {
        return FOrigineMax;
    }

    double getFOrigineMin() const
    {
        return FOrigineMin;
    }

    double getOrigineX() const
    {
        return origineX;
    }

    double getOrigineY() const
    {
        return origineY;
    }

    double getQi() const
    {
        return Qi;
    }

    void setDelta(double delta)
    {
        this->delta = delta;
    }

    void setDestinationX(double destinationX)
    {
        this->destinationX = destinationX;
    }

    void setDestinationY(double destinationY)
    {
        this->destinationY = destinationY;
    }

    void setFDestinationMax(double FDestinationMax)
    {
        this->FDestinationMax = FDestinationMax;
    }

    void setFDestinationMin(double FDestinationMin)
    {
        this->FDestinationMin = FDestinationMin;
    }

    void setFOrigineMax(double FOrigineMax)
    {
        this->FOrigineMax = FOrigineMax;
    }

    void setFOrigineMin(double FOrigineMin)
    {
        this->FOrigineMin = FOrigineMin;
    }

    void setOrigineX(double origineX)
    {
        this->origineX = origineX;
    }

    void setOrigineY(double origineY)
    {
        this->origineY = origineY;
    }

    void setQi(double Qi)
    {
        this->Qi = Qi;
    }

    void setKpourTous(int k)
    {
      noeudOrigine->setK(k);
      noeudDestination->setK(k);
    }

    double amplitude()
    {
      return noeudDestination->getGapFenetre() * noeudOrigine->getGapFenetre();
    }

    double amplitudeSave()
    {
      return noeudDestination->getGapFenetreSave() * noeudOrigine->getGapFenetreSave();
    }

};

#endif /* DEMANDE_H_ */
