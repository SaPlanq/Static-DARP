//============================================================================
// Name        : DARPSimple.cpp
// Author      : Samuel Deleplanque
// Version     :
// Copyright   : LIMOS
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include "Metier.h"
using namespace std;

int main(int argc, char ** argv) {
		ManipString stringManip;
		string idInstance;
        cout << "Resolution du DARP avec Inserabilite et exclusion" << endl;
        Metier coucheMetier;
        // Les arguments sont : nomExe A B C N1 N2
        coucheMetier.setA(atoi(argv[1]));
        coucheMetier.setB(atoi(argv[2]));
        coucheMetier.setC(atoi(argv[3]));
        coucheMetier.setD(atoi(argv[4]));
        coucheMetier.setE(atoi(argv[5]));
        coucheMetier.setN1(atoi(argv[6]));
        coucheMetier.setN2(atoi(argv[7]));
        coucheMetier.setNombreReplication(atoi(argv[8]));
        coucheMetier.setNbInstances(atoi(argv[9]));
        coucheMetier.setLambdaCharge(atoi(argv[10]));
        coucheMetier.setSEUIL(atoi(argv[11]));


//    idInstance += "C";
//    idInstance += stringManip.fromIntToString(atoi(argv[1]));
//    idInstance += stringManip.fromIntToString(atoi(argv[2]));
//    idInstance += stringManip.fromIntToString(atoi(argv[3]));
//    idInstance += stringManip.fromIntToString(atoi(argv[4]));
//    idInstance += stringManip.fromIntToString(atoi(argv[5]));

    coucheMetier.setIdInst(idInstance);

        coucheMetier.executionMetier();
        //coucheMetier.executionMetierClassToVH(atoi(argv[11]));

        return 0;
}
