/*
 * Parametres.cpp
 *
 *  Created on: Feb 17, 2012
 *      Author: spydel
 */

#include "Parametres.h"

void Parametres::setUniteTempsDeService(char typeTempsDeService)
{
  // Par defaut l'unite est la minute
  if (typeTempsDeService == 's')
    {
      uniteTempsDeService = 1.0/60.0;
    }
  else if (typeTempsDeService == 'm')
    {
      uniteTempsDeService = 1.0;
    }
  else // C'est en heure
    {
      uniteTempsDeService = 60.0;
    }
}

Parametres::~Parametres()
{

}
