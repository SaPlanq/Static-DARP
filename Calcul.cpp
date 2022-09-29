/*
 * Calcul.cpp
 *
 *  Created on: Feb 16, 2012
 *      Author: spydel
 */

#include "Calcul.h"

Calcul::Calcul()
{
  srand(0);
}

/*
 * calcule la distance euclidienne entre deux points 2D
 */
double
Calcul::calculDistance(double X1, double X2, double Y1, double Y2)
{
  return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}

/*
 * Même chose à partir de noeud *
 */
double
Calcul::calculDistance(Noeud * X, Noeud * Y)
{
   return calculDistance(X->getX(), Y->getX(), X->getY(), Y->getY());
}


/*
 * Même chose à partir de noeud *
 */
double
Calcul::calculDistanceAvecService(Noeud * X, Noeud * Y)
{
  // ATTENTION on ajoute ici les temps de service au debut d une distance si le noeud est de status 0 ou 1
  if ( (X->getStatus()==0) ||(X->getStatus()==1) )
    {
    return X->getTempsDeService() + calculDistance(X->getX(), Y->getX(), X->getY(), Y->getY());
    }
  else  return calculDistance(X->getX(), Y->getX(), X->getY(), Y->getY());
}

/*
 * Methode qui renvoie le maximum de deux doubles
 */
double
Calcul::SUP(double x, double y)
{
  if (x < y)
    return y;
  else
    return x;
}

/*
 * Methode qui renvoie le minimu de deux doubles
 */
double
Calcul::INF(double x, double y)
{
  if (x < y)
    return x;
  else
    return y;
}

/*
 * Methode sortant l indice du maximum d un vector de positifs
 */
int
Calcul::Maximum(vector<double> & vecteur)
{
  double maximum = -1.0;
  int i = 0;
  int indiceSave = -1;

  for (vector<double>::iterator itVecteur = vecteur.begin(); itVecteur
      != vecteur.end(); itVecteur++)
    {
      if (maximum < *itVecteur)
        {
          maximum = *itVecteur;
          indiceSave = i;
        }
      i++;
    }
  return indiceSave;
}

/*
 * Methode sortant l indice du minimum d un vector de positifs
 */
int
Calcul::Minimum(vector<double> & vecteur)
{
  double minimum = getInfiniDouble();
  int i = 0;
  int indiceSave = -1;

  for (vector<double>::iterator itVecteur = vecteur.begin(); itVecteur
      != vecteur.end(); itVecteur++)
    {
      if (minimum > *itVecteur)
        {
          minimum = *itVecteur;
          indiceSave = i;
        }
      i++;
    }
  return indiceSave;
}

/*
 * Methode renvoyant un nombre aleatoire entier entre 0 et borne (non compris)
 */
int
Calcul::randInt(int borne)
{
  if (borne>=1)    return rand() % borne;
  else          return 0;
}

/*
 * Methode calculant le coef directeur d'une droite
 */
double
Calcul::getCoefDirecteur(double X1, double Y1, double X2, double Y2)
{
  if (X1 == X2)
    return 0;
  else
    return (Y2 - Y1) / (X2 - X1);
}

/*
 * Cette methode calcule b, de y = ax + b
 */
double
Calcul::getBFonctionLineaire(double X1, double Y1, double a)
{
  return Y1 - a * X1;
}

/*
 * Cette fonction renvoie un noeud * d'un nouveau noeud cree aléatoirement entre deux autres
 */
Noeud *
Calcul::NewRelais(Noeud * Z1, Noeud * Z2, Noeud * nouveauNoeud)
{
  double a, b, temp;
  Noeud * noeudRelais = nouveauNoeud;

  if (Z1->getX() == Z2->getX())
    {
      // Si ce sont les memes points on le point relais est un troisieme identique
      if ((Z1->getY() == Z2->getY()))
        {
          noeudRelais->setX(Z1->getX());
          noeudRelais->setY(Z1->getY());
          return noeudRelais;
        }
      else
        {
          // Le nouveau noeud a le meme X
          noeudRelais->setX(Z1->getX());
          if (Z1->getY() < Z2->getY())
            {
              temp = Z2->getY() - Z1->getY();
              if (temp < 1.0)
                temp = Z1->getY();
              else
                temp = rand() % (int(temp));
              noeudRelais->setY(temp);
            }
          else
            {
              temp = Z1->getY() - Z2->getY();
              if (temp < 1.0)
                temp = Z1->getY();
              else
                temp = rand() % (int(temp));
              noeudRelais->setY(temp);
            }
        }
    }
  else
    {
      if ((Z1->getY() == Z2->getY()))
        {
          noeudRelais->setY(Z1->getY());
          if (Z1->getX() < Z2->getX())
            {
              temp = Z2->getX() - Z1->getX();
              if (temp < 1.0)
                temp = Z1->getX();
              else
                temp = rand() % (int(temp));
              noeudRelais->setX(temp);
            }
          else
            {
              temp = Z1->getX() - Z2->getX();
              if (temp < 1.0)
                temp = Z1->getX();
              else
                temp = rand() % (int(temp));
              noeudRelais->setX(temp);
            }
        }
      else
        {
          a = getCoefDirecteur(Z1->getX(), Z1->getY(), Z2->getX(), Z2->getY());
          b = getBFonctionLineaire(Z1->getX(), Z1->getY(), a);
          if (Z1->getX() < Z2->getX())
            {
              temp = Z2->getX() - Z1->getX();
              if (temp < 1.0)
                temp = Z1->getX();
              else
                temp = rand() % (int(temp));
              noeudRelais->setX(temp);
            }
          else
            {
              temp = Z1->getX() - Z2->getX();
              if (temp < 1.0)
                temp = Z1->getX();
              else
                {
                   temp = rand() % (int(temp));
                }
              noeudRelais->setX(temp);
            }
          noeudRelais->setY(a * noeudRelais->getX() + b);
        }
    }
  return noeudRelais;
}

Calcul::~Calcul()
{

}
