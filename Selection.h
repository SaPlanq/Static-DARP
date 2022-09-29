/*
 * Selection.h
 *
 *  Created on: 28 fevr. 2012
 *      Author: deleplan
 */

#ifndef SELECTION_H_
#define SELECTION_H_

#include <list>
#include "QuatreUplet.h"

using namespace std;
/*
 * Cette classe est genere autant de fois qu il y a de demandes
 * elle permet justement de choisir au mieux la demande a inserer
 * et egalement des infos sur la prise en charge de celle ci
 */
class Selection {
protected:
	int N1;
	int N2;
	int NbCarLibre;
	list<QuatreUplet *> LibreXY;

public:

	Selection();
	Selection(const Selection & inSelection);
	Selection &
	operator =(Selection & inSelection);
	virtual
	~Selection();
	// Fonctions Amies
	friend ostream &
	operator <<(ostream & sortie, Selection & inSelection);

	// Getter et Setter
	list<QuatreUplet *> getLibreXY() const {
		return LibreXY;
	}

	int getN1() const {
		return N1;
	}

	int getN2() const {
		return N2;
	}

	int getNbCarLibre() const {
		return NbCarLibre;
	}

	void setLibreXY(list<QuatreUplet *> LibreXY) {
		this->LibreXY = LibreXY;
	}

	void setN1(int N1) {
		this->N1 = N1;
	}

	void setN2(int N2) {
		this->N2 = N2;
	}

	void ajoutLibreXY(QuatreUplet * quatreUplet) {
		LibreXY.push_back(quatreUplet);
	}

	void setNbCarLibre(int NbCarLibre) {
		this->NbCarLibre = NbCarLibre;
	}

	list<QuatreUplet *>::iterator getDebutLibreXY() {
		return LibreXY.begin();
	}

	list<QuatreUplet *>::iterator getEndLibreXY() {
		return LibreXY.end();
	}

	int getTailleLibreXY() const {
		return LibreXY.size();
	}

	void incrementeNbCarLibre() {
		NbCarLibre++;
	}

	void decrementeNbCarLibre() {
		NbCarLibre--;
	}

	void popLibreXY() {
		LibreXY.pop_back();
	}

	void trieLibreXY() {
		LibreXY.sort();
	}

	void dedoublonneLibreXY() {
		LibreXY.unique();
	}

	void
	effaceQuatreUplet(list<QuatreUplet *>::iterator it);

	void
	insertListeTriee(QuatreUplet * quatreUplet);

	bool
	kPresent(int k);

	bool kPresent(int k, bool typeList);
};

#endif /* SELECTION_H_ */
