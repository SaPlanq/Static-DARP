/*
 * Noeud.h
 *
 *  Created on: 7 fevr. 2012
 *      Author: deleplan
 */

#ifndef NOEUD_H_
#define NOEUD_H_

#include <iostream>

using namespace std;

class Noeud
{
protected:
  int status;
  int indiceDemande;
  int indiceDsDist;
  int k;
  double FPropageMin;
  double FPropageMax;
  double FPropageMinSave;
  double FPropageMaxSave;
  double FMin;
  double FMax;
  double ChT;
  double qi;
  double t;
  double tSave;
  double tempsDeService;
  double X;
  double Y;
  bool   Mark;
public:
  // Constructeur par defaut
  Noeud();
  //Constructeur de recopie
  Noeud(const Noeud & inNoeud);
  // Surcharge =
  Noeud &
  operator =(const Noeud & inNoeud);

  // Fonction Amies
  friend ostream &
  operator <<(ostream & sortie, Noeud & noeud);
  virtual
  ~Noeud();

  void reinitNoeud();
    bool getMark() const
    {
        return Mark;
    }

    void setMark(bool Mark)
    {
        this->Mark = Mark;
    }

    double getX() const
    {
        return X;
    }

    double getY() const
    {
        return Y;
    }

    void setX(double X)
    {
        this->X = X;
    }

    void setY(double Y)
    {
        this->Y = Y;
    }

    double &
  getFMax() 
  {
    return FMax;
  }

  double &
  getFMin() 
  {
    return FMin;
  }

  void
  setFMax(double FMax)
  {
    this->FMax = FMax;
  }

  void
  setFMin(double FMin)
  {
    this->FMin = FMin;
  }

  double &
  getSave() 
  {
    return tSave;
  }

  void
  setSave(double tSave)
  {
    this->tSave = tSave;
  }

  double &
  getQi() 
  {
    return qi;
  }

  void
  setQi(double qi)
  {
    this->qi = qi;
  }

  // Les get & set
  int
  getIndiceDsDist() 
  {
    return indiceDsDist;
  }

  void
  setIndiceDsDist(int indiceDsDist)
  {
    this->indiceDsDist = indiceDsDist;
  }
  void
  setStatus(const int Status)
  {
    status = Status;
  }
  void
  setIndiceDemande( int IndiceDemande)
  {
    indiceDemande = IndiceDemande;
  }
  double &
  getChT() 
  {
    return ChT;
  }
  double &
  getFPropageMax() 
  {
    return FPropageMax;
  }
  double &
  getFPropageMin() 
  {
    return FPropageMin;
  }

  int
  getIndiceDemande() 
  {
    return indiceDemande;
  }

  int
  getK() 
  {
    return k;
  }

  int
  getStatus() 
  {
    return status;
  }

  double &
  getT() 
  {
    return t;
  }

  double &
  getTempsDeService() 
  {
    return tempsDeService;
  }

  void
  setChT(double ChT)
  {
    this->ChT = ChT;
  }

  void
  setFPropageMax(double FPropageMax)
  {
    this->FPropageMax = FPropageMax;
  }

  void
  setFPropageMin(double FPropageMin)
  {
    this->FPropageMin = FPropageMin;
  }

  void
  setK(int k)
  {
    this->k = k;
  }

  void
  setT(double t)
  {
    this->t = t;
  }

  void
  setTempsDeService(double tempsDeService)
  {
    this->tempsDeService = tempsDeService;
  }
  double &
  getFPropageMaxSave() 
  {
    return FPropageMaxSave;
  }

  double &
  getFPropageMinSave() 
  {
    return FPropageMinSave;
  }

  void
  setFPropageMaxSave(double FPropageMaxSave)
  {
    this->FPropageMaxSave = FPropageMaxSave;
  }

  void
  setFPropageMinSave(double FPropageMinSave)
  {
    this->FPropageMinSave = FPropageMinSave;
  }

  double getGapFenetreSave()
  {
    return FPropageMaxSave - FPropageMinSave;
  }

  double getGapFenetre()
  {
    return 0.01 + FPropageMax - FPropageMin;
  }



};

#endif /* NOEUD_H_ */
