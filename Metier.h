/*
 * Metier.h
 *
 *  Created on: 7 fevr. 2012
 *      Author: deleplan
 */

#ifndef METIER_H_
#define METIER_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <iomanip>
#include "Demande.h"
#include "Tournee.h"
#include "Calcul.h"
#include "Noeud.h"
#include "Parametres.h"
#include "Selection.h"
#include "ManipString.h"

using namespace std;

class Metier
{
protected:

  vector<Demande> tabDemandes;
  vector<Selection> tabSelection;
  vector<bool> tabBoolJ;
  vector<bool> tabrejet;
  vector<Tournee> tabTournees;
  vector<double> tabValTournees;
  vector<double> tabTpsAttente;
  vector<double> tabTpsGlobal;
  vector<double> tabTpsDemande;
  vector<double> tabDistance;
  vector<double> tabTempsExe;
  vector<double> tabPerformance;
  vector<double> tabEarlyArrival;
  vector<double> tabWaitPassenger;
  vector<double> tabRideExcess;
  vector<vector<double> > DIST;
  vector<vector<double> > DISTSansService;
  vector<string> nomFichiersInstances;
  vector<string> nomFichiersSortiesInstances;

  QuatreUplet * tabTousQuatreuplet;
  Noeud * tabTousNoeud;
  Calcul calcul;
  Parametres parametres;
  ManipString manipulateurString;

  double coordDepotX;
  double coordDepotY;
  double FminDepot;
  double FmaxDepot;
  double A, B, C, D, E;
  double capaciteVehicule;
  double sommeTpsExe;
  double lambdaCharge;
  double insertionRatees;
  double SEUIL;
  int nbReplicationReussie;
  int nbInstances;
  int nombreDemandes;
  int nombreVoitures;
  int compteurJ;
  int N1;
  int N2;
  int nombreReplication;
  int indiceTabTousQuatreuplet;
  int indiceTqbTousDeuxUplet;
  int indiceTabTousCandidat;
  int indiceTabTousNoeud;
  int indiceDemandeProchaine;
  int indiceDemandeProchaine2;
  bool premiereReplication;
  string idInst;

public:
  Metier();
  Metier(const Metier & inMetier);
  void
  preparationFichiers();
  void
  saveNomsFichiersInstances();
  void
  saveNomsFichiersSortiesInstances();
  void
  ecritureResultats(ofstream & flotBasique);
  void
  allocationReplication();
  void
  desalloueReplication();
  void
  executionMetier();
  QuatreUplet *
  newQuatreUplet(int k, list<Noeud*>::iterator itX, list<Noeud*>::iterator itY,
      double v);
  Noeud *
  newNoeud();
  void
  ajoutDemande(const Demande & newDemande);
  void
  afficherSeparationCOUT(ofstream & sortie);
  void
  affichageQuatreUpletDemande(ofstream & sortie, int indiceDemande);
  void
  affichageDemandes(ofstream & sortie, int indiceDemande);
  void
  affichageTournees(ofstream & sortie, int indiceTournee);
  void
  lireInstances(const char *nomFichierInstance);
  void
  initTournees(Parametres & param);
  void
  initSelection(ofstream & sortie);
  void
  calculDIST();
  void
  affichageDIST(ofstream & sortie);
  void
  additionDistTpsService();
  void
  additionDeltaTpsService();
  Noeud *
  ptSurJumeau(Noeud *frere);
  bool
  R1Propagation(Noeud *itx, Noeud *ity, Calcul & calcul);
  bool
  R2Propagation(Noeud *itx, Noeud *ity, Calcul & calcul);
  bool
  R3Propagation(Noeud *itx, Noeud *ity, double delta, Calcul & calcul);
  bool
  R4Propagation(Noeud *itx, Noeud *ity, double delta, Calcul & calcul);
  bool
  R5Propagation(Noeud *itx);
  bool
  propagerFenetreTemps(const int indiceTournee,
      list<list<Noeud*>::iterator> & ListeitListPointeurSurNoeud,
      Calcul & calcul, ofstream & sortie);
  double
  TpsGlobalTournee(int indiceTournee);
  double
  TpsGlobalTourneeSave(int indiceTournee);
  double
  TpsDemandesTournee(int indiceTournee);
  double
  TpsDemandesTourneeSave(int indiceTournee);
  double
  TpsAttenteTournee(int indiceTournee, double & tpsGlobal);
  double
  EvalTournee(int indiceTournee);
  double
  EvalTourneeSave(int indiceTournee);
  double
  EvalTouteTournee();
  double
  EvalTouteTourneeSave();
  double
  EvalEarlyArrival(int indiceTournee);
  double
  EvalWaitPassenger(int indiceTournee);
  double
  TpsDemandesTourneeExcess(int indiceTournee);
  double
  EvalEarlyArrivalSave(int indiceTournee);
  double
  EvalWaitPassengerSave(int indiceTournee);
  double
  TpsDemandesTourneeExcessSave(int indiceTournee);
  double
  calculDistanceParcourue(int indiceTournee);
  double
  evalTour1(int indiceTournee);
  bool
  testTpsMaxConnexion(int indiceTournee1, int indiceTournee2, int i0, list<
      Noeud *>::iterator x1, list<Noeud *>::iterator x2,
      list<Noeud *>::iterator y1, list<Noeud *>::iterator y2, Noeud * z,
      ofstream & sortie);
  bool
  E2(Noeud *x, Noeud *xsucc);
  bool
  E3(Noeud *xpred, Noeud *x);
  double
  evalTour2(int indiceTournee, ofstream & sortie);
  bool
  testCharge(int indiceTournee, list<Noeud*>::iterator x,
      list<Noeud*>::iterator y, int indiceDemande);
  bool
  test2Charge(int indiceTournee1, list<Noeud*>::iterator x1,
      list<Noeud*>::iterator y1, int indiceTournee2, list<Noeud*>::iterator x2,
      list<Noeud*>::iterator y2, int indiceDemande);
  void
  PropageCharge(int indiceTournee, list<Noeud*>::iterator xsucc,
      list<Noeud*>::iterator ysucc, int indiceDemande, ofstream & sortie);
  void
  fromFPrSaveToFPrxy(int indiceTournee, list<Noeud*>::iterator x,
      list<Noeud*>::iterator y);
  void
  fromFPrSaveToFPr(int indiceTournee, list<Noeud*>::iterator x,
      list<Noeud*>::iterator y);
  bool
  testUnNoeud(list<Noeud*>::iterator z, list<Noeud*>::iterator zz, Noeud *u,
      int indiceDemande, int indiceTournee);
  double
  testDeuxNoeudslist(list<Noeud*>::iterator z, list<Noeud*>::iterator zz,
      Noeud *u, Noeud *v, int indiceDemande, int indiceTournee);
  double
  testInsertion(int indiceTournee, int indiceDemande, list<Noeud*>::iterator x,
      list<Noeud*>::iterator y, Noeud *oIt, Noeud *dIt, ofstream & sortie);

  double
  INSER2(int indiceTournee, int indiceDemande, list<Noeud*>::iterator x,
      list<Noeud*>::iterator y, Noeud *oIt, Noeud *dIt, ofstream & sortie);
  double
  INSER1(int indiceTournee, int indiceDemande, ofstream & sortie);
  double
  INSER(int indiceDemande, ofstream & sortie);
  int
  SelectionDemandeINSERABILITE(ofstream & sortie);
  int
  SelectionDemandeMaxINSERABILITE(ofstream & sortie);
  bool
  testExclusion(int indiceDemande, QuatreUplet * itUplet,  ofstream & sortie);
  int
  selectionDemandeE4(Calcul & calcul, ofstream & sortie);
  QuatreUplet *
  selectionDemandeE5(int indiceDemande, Calcul & calcul, ofstream & sortie);
  QuatreUplet *
  selectionE5Inserabilite(int indiceDemande, Calcul & calcul,
      ofstream & sortie);
  double
  insertionCoeur(Calcul&, ofstream & sortie, bool processSeul);
  void
  effaceUplet(int numDemande, list<QuatreUplet*>::iterator it);
  virtual
  ~Metier();
  int
  getNbInstances() const
  {
    return nbInstances;
  }

  void
  setNbInstances(int nbInstances)
  {
    this->nbInstances = nbInstances;
  }

  void
  setD(int D)
  {
    this->D = D;
  }

  void
  setE(int E)
  {
    this->E = E;
  }

  int
  getNombreReplication() const
  {
    return nombreReplication;
  }

  void
  setNombreReplication(int nombreReplication)
  {
    this->nombreReplication = nombreReplication;
  }

  double
  getA() const
  {
    return A;
  }

  double
  getB() const
  {
    return B;
  }

  double
  getC() const
  {
    return C;
  }

  double
  getD() const
  {
    return D;
  }

  int
  getN1() const
  {
    return N1;
  }

  int
  getN2() const
  {
    return N2;
  }

	const string& getIdInst() const
	{
		return idInst;
	}

	void setIdInst(const string& idInst)
	{
		this->idInst = idInst;
	}

  vector<bool>
  getTabBoolJ() const
  {
    return tabBoolJ;
  }

  void
  setA(double A)
  {
    this->A = A;
  }

  void
  setB(double B)
  {
    this->B = B;
  }

  void
  setC(double C)
  {
    this->C = C;
  }

  void
  setD(double D)
  {
    this->D = D;
  }

  void
  setN1(int N1)
  {
    this->N1 = N1;
  }

  void
  setN2(int N2)
  {
    this->N2 = N2;
  }

  void
  setTabBoolJ(vector<bool> tabBoolJ)
  {
    this->tabBoolJ = tabBoolJ;
  }

  void
  pretraitementSurFenetre();
  
  double
  getLambdaCharge() const
  {
    return lambdaCharge;
  }

  void
  setLambdaCharge(double lambdaCharge)
  {
    this->lambdaCharge = lambdaCharge;
  }
    
         
  void
  majDelta(double lambdaDeDelta);
      
  bool
  testSousEnsembleLibreXY(list<Noeud*>::iterator z, list<Noeud*>::iterator zz,
      Noeud *u, int indiceDemande, int indiceTournee);
  
  void
  oldDelta();
  
  void
  fromTourneesToTxt(int numReplication);
  
  void
  fromTourneesToGraphVIZ(int numReplication);
  
    double getSEUIL() const
    {
        return SEUIL;
    }

    void setSEUIL(double SEUIL)
    {
        this->SEUIL = SEUIL;
    }


    double calculLambdaEval2(int status);
};

// Declaration de fonction
template<typename T>
  void
  affichage(T instanceT);

#endif /* METIER_H_ */
