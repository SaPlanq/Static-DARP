/*
 * Calcul.h
 *
 *  Created on: Feb 16, 2012
 *      Author: spydel
 */

#ifndef CALCUL_H_
#define CALCUL_H_

#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "Noeud.h"

using namespace std;

class Calcul
{
public:
  Calcul();

  static double
  getInfiniDouble()
  {
    return 999999.9;
  }
  static int
  getInfiniInt()
  {
    return 999999;
  }
  static double
  getEpsilon()
  {
    return 0.0001;
  }
  double
  calculDistance(double X1, double X2, double Y1, double Y2);
  double calculDistanceAvecService(Noeud * X, Noeud * Y);
  double calculDistance(Noeud * X, Noeud * Y);
  int Maximum(vector<double> & vecteur);
  int Minimum(vector<double> & vecteur);
  double
  SUP(double x, double y);
  double
  INF(double x, double y);
  int
  randInt(int borne);
  double getCoefDirecteur(double X1, double Y1, double X2, double Y2);
  double getBFonctionLineaire(double X1, double Y1, double a);
  Noeud * NewRelais(Noeud * Z1, Noeud * Z2, Noeud * nouveauNoeud);
  virtual
  ~Calcul();
};

#endif /* CALCUL_H_ */
