/*
 * ManipString.cpp
 *
 *  Created on: 9 mars 2012
 *      Author: deleplan
 */

#include "ManipString.h"

ManipString::ManipString()
{

}

/*
 * Methode transformant un tring
 */
string ManipString::fromIntToString(int entier)
{
  string str;
  stringstream ss;

  ss << entier;
  ss >> str;
  return str;
}

ManipString::~ManipString()
{

}
