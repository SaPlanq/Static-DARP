/*
 * Parametres.h
 *
 *  Created on: Feb 17, 2012
 *      Author: spydel
 */

#ifndef PARAMETRES_H_
#define PARAMETRES_H_

#include <iostream>

using namespace std;

class Parametres
{
protected:
  double uniteTempsDeService;
  double tempsMaxTournee;
  double XDepot;
  double YDepot;
public:
  Parametres(){};
  virtual
  ~Parametres();
  double
  getUniteTempsDeService() const
  {
    return uniteTempsDeService;
  }
  void
  setUniteTempsDeService(char typeTempsDeService);
    double getXDepot() const
    {
        return XDepot;
    }

    double getYDepot() const
    {
        return YDepot;
    }

    void setXDepot(double XDepot)
    {
        this->XDepot = XDepot;
    }

    void setYDepot(double YDepot)
    {
        this->YDepot = YDepot;
    }

    double getTempsMaxTournee() const
    {
        return tempsMaxTournee;
    }

    void setTempsMaxTournee(double tempsMaxTournee)
    {
        this->tempsMaxTournee = tempsMaxTournee;
    }

};

#endif /* PARAMETRES_H_ */
