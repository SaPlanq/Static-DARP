/*
 * ManipString.h
 *
 *  Created on: 9 mars 2012
 *      Author: deleplan
 */

#ifndef MANIPSTRING_H_
#define MANIPSTRING_H_

#include <string>
#include <sstream>

using namespace std;

class ManipString
{
public:
  ManipString();
  string fromIntToString(int entier);
  virtual
  ~ManipString();
};

#endif /* MANIPSTRING_H_ */
