/*
 * Metier.cpp
 *
 *  Created on: 7 fevr. 2012
 *      Author: deleplan
 */

#include "Metier.h"

Metier::Metier()
{
  tabTousQuatreuplet = NULL;
  tabTousNoeud = NULL;
}

Metier::Metier(const Metier & inMetier)
{
  // La STL a surcharge l'affectation de ses conteneurs
  tabDemandes = inMetier.tabDemandes;
  tabTournees = inMetier.tabTournees;
}

/*
 * Methode generant tous les noms de fichiers de cordeaux[3]
 */
void
Metier::saveNomsFichiersInstances()
{
  for (int i = 1; i < 10; i++)
    {
      string nomTemp = "pr0";
      nomTemp += manipulateurString.fromIntToString(i);
      nomTemp += ".txt";
      nomFichiersInstances.push_back(nomTemp);
    }
  for (int i = 10; i < 21; i++)
    {
      string nomTemp = "pr";
      nomTemp += manipulateurString.fromIntToString(i);
      nomTemp += ".txt";
      nomFichiersInstances.push_back(nomTemp);
    }
}

/*
 * Methode generant tous les noms de fichiers de sortie pour Cordeaux
 */
void
Metier::saveNomsFichiersSortiesInstances()
{
  for (int i = 1; i < 10; i++)
    {
      string nomTemp = "ResultInstances.pr0";

      nomTemp += manipulateurString.fromIntToString(i);
      nomTemp += ".txt";
      nomFichiersSortiesInstances.push_back(nomTemp);
    }

  for (int i = 10; i < 21; i++)
    {
      string nomTemp = "ResultInstances.pr";

      nomTemp += manipulateurString.fromIntToString(i);
      nomTemp += ".txt";
      nomFichiersSortiesInstances.push_back(nomTemp);
    }
}

void
Metier::preparationFichiers()
{
  saveNomsFichiersInstances();
  saveNomsFichiersSortiesInstances();
}
/*
 * Affichage des minimum des resultats
 */
void
Metier::ecritureResultats(ofstream & flotBasique)
{
  int indiceVecteur;
  afficherSeparationCOUT(flotBasique);
  flotBasique << " nombre de replications reussies sur " << nombreReplication
      << " : " << nbReplicationReussie << " ; soit un pourcentage de "
      << (double(nbReplicationReussie) / double(nombreReplication)) * 100.0
      << "%" << endl;
  flotBasique
      << " Valeur A B C D N1(i2) N2 nbDemandes (A*TpsGlobal+B*Ride+C*Wait+D*Distance. "
      << endl;
  flotBasique << " Valeur " << A << " " << B << " " << C << " " << D << " "
      << N1 << "   " << N2 << "    " << nombreDemandes << endl;
  // On passe au traitement de la performance

  indiceVecteur = calcul.Minimum(tabPerformance);

  afficherSeparationCOUT(flotBasique);

  flotBasique << "Replication avec la performance ; n° " << indiceVecteur + 1
      << endl;

  flotBasique << "A * tabTpsGlobal(DUREE) : " << tabTpsGlobal[indiceVecteur]
      << endl;
  flotBasique << " B * TabTpsDemande(Ride) : " << tabTpsDemande[indiceVecteur]
      << endl;
  flotBasique << "C *   tabTpsAttente(WAIT): " << tabTpsAttente[indiceVecteur]
      << endl;
  flotBasique << "D *  tabDistance : " << tabDistance[indiceVecteur] << endl;

  flotBasique << " tabRideExcess : " << tabRideExcess[indiceVecteur] << endl;
  flotBasique << "tabWaitPassenger : " << tabWaitPassenger[indiceVecteur]
      << endl;
  flotBasique << "tabEarlyArrival : " << tabEarlyArrival[indiceVecteur] << endl;

  flotBasique << "                        tabPerformance : "
      << tabPerformance[indiceVecteur] << endl;
  // On affiche les moyennes
  afficherSeparationCOUT(flotBasique);
  flotBasique << " -- Affichage  tps exe :  " << sommeTpsExe << endl << endl;

  // Affichage pour le minTpsGlobal
  indiceVecteur = calcul.Minimum(tabTpsGlobal);
  afficherSeparationCOUT(flotBasique);

  flotBasique << "Replication avec le temps global MIN : " << endl;
  flotBasique << "   mintabTpsGlobal(DUREE) : " << tabTpsGlobal[indiceVecteur]
      << endl;
  flotBasique << "   tabTpsAttente(WAIT) : " << tabTpsAttente[indiceVecteur]
      << endl;
  flotBasique << "   tabTpsDemande(Ride) : " << tabTpsDemande[indiceVecteur]
      << endl;
  flotBasique << "   tabDistance : " << tabDistance[indiceVecteur] << endl;
  flotBasique << "   tabPerformance : " << tabPerformance[indiceVecteur]
      << endl;
  flotBasique << "   tabWaitPassenger : " << tabWaitPassenger[indiceVecteur]
      << endl;
  flotBasique << "   tabEarlyArrival : " << tabEarlyArrival[indiceVecteur]
      << endl;
  flotBasique << "   tabRideExcess : " << tabRideExcess[indiceVecteur] << endl;
  // Affichage pour min des temps d attente
  indiceVecteur = calcul.Minimum(tabTpsAttente);
  afficherSeparationCOUT(flotBasique);
  flotBasique << "Replication avec le temps d'attente MIN : " << endl;
  flotBasique << "   tabTpsGlobal(DUREE) : " << tabTpsGlobal[indiceVecteur]
      << endl;
  flotBasique << "   MintabTpsAttente(WAIT) : " << tabTpsAttente[indiceVecteur]
      << endl;
  flotBasique << "   tabTpsDemande(Ride) : " << tabTpsDemande[indiceVecteur]
      << endl;
  flotBasique << "   tabDistance : " << tabDistance[indiceVecteur] << endl;
  flotBasique << "   tabPerformance : " << tabPerformance[indiceVecteur]
      << endl;
  flotBasique << "   tabWaitPassenger : " << tabWaitPassenger[indiceVecteur]
      << endl;
  flotBasique << "   tabEarlyArrival : " << tabEarlyArrival[indiceVecteur]
      << endl;
  flotBasique << "   tabRideExcess : " << tabRideExcess[indiceVecteur] << endl;
  // Affichage pour min des temps de connexion (RIDE)
  indiceVecteur = calcul.Minimum(tabTpsDemande);
  afficherSeparationCOUT(flotBasique);
  flotBasique << "Replication avec le temps de connexion (RIDE) MIN : " << endl;
  flotBasique << "   tabTpsGlobal(DUREE) : " << tabTpsGlobal[indiceVecteur]
      << endl;
  flotBasique << "   tabTpsAttente(WAIT) : " << tabTpsAttente[indiceVecteur]
      << endl;
  flotBasique << "   MintabTpsDemande(Ride) : " << tabTpsDemande[indiceVecteur]
      << endl;
  flotBasique << "   tabDistance : " << tabDistance[indiceVecteur] << endl;
  flotBasique << "   tabPerformance : " << tabPerformance[indiceVecteur]
      << endl;
  flotBasique << "   tabWaitPassenger : " << tabWaitPassenger[indiceVecteur]
      << endl;
  flotBasique << "   tabEarlyArrival : " << tabEarlyArrival[indiceVecteur]
      << endl;
  flotBasique << "   tabRideExcess : " << tabRideExcess[indiceVecteur] << endl;
  // Affichage pour min des temps de connexion (RIDE)
  indiceVecteur = calcul.Minimum(tabDistance);
  afficherSeparationCOUT(flotBasique);
  flotBasique << "Replication avec les distances parcourues MIN : " << endl;
  flotBasique << "   tabTpsGlobal(DUREE) : " << tabTpsGlobal[indiceVecteur]
      << endl;
  flotBasique << "   tabTpsAttente(WAIT) : " << tabTpsAttente[indiceVecteur]
      << endl;
  flotBasique << "   tabTpsDemande(Ride) : " << tabTpsDemande[indiceVecteur]
      << endl;
  flotBasique << "   mintabDistance : " << tabDistance[indiceVecteur] << endl;
  flotBasique << "   tabPerformance : " << tabPerformance[indiceVecteur]
      << endl;
  flotBasique << "   tabWaitPassenger : " << tabWaitPassenger[indiceVecteur]
      << endl;
  flotBasique << "   tabEarlyArrival : " << tabEarlyArrival[indiceVecteur]
      << endl;
  flotBasique << "   tabRideExcess : " << tabRideExcess[indiceVecteur] << endl;
  // On passe au traitement de WaitPassenger
  indiceVecteur = calcul.Minimum(tabWaitPassenger);
  afficherSeparationCOUT(flotBasique);
  flotBasique << "Replication avec tabWaitPassenger " << endl;
  flotBasique << " A  tabTpsGlobal(DUREE) : " << tabTpsGlobal[indiceVecteur]
      << endl;
  flotBasique << "  C tabTpsAttente(WAIT) : " << tabTpsAttente[indiceVecteur]
      << endl;
  flotBasique << "  B tabTpsDemande(Ride) : " << tabTpsDemande[indiceVecteur]
      << endl;
  flotBasique << "   tabDistance : " << tabDistance[indiceVecteur] << endl;
  flotBasique << "   tabPerformance : " << tabPerformance[indiceVecteur]
      << endl;
  flotBasique << "   tabWaitPassenger : " << tabWaitPassenger[indiceVecteur]
      << endl;
  flotBasique << "   tabEarlyArrival : " << tabEarlyArrival[indiceVecteur]
      << endl;
  flotBasique << "   tabRideExcess : " << tabRideExcess[indiceVecteur] << endl;

  // On passe au traitement de tabEarlyArrival
  indiceVecteur = calcul.Minimum(tabEarlyArrival);
  afficherSeparationCOUT(flotBasique);
  flotBasique << "Replication avec tabEarlyArrival : " << endl;
  flotBasique << " A  tabTpsGlobal(DUREE) : " << tabTpsGlobal[indiceVecteur]
      << endl;
  flotBasique << "  C tabTpsAttente(WAIT) : " << tabTpsAttente[indiceVecteur]
      << endl;
  flotBasique << "  B tabTpsDemande(Ride) : " << tabTpsDemande[indiceVecteur]
      << endl;
  flotBasique << "   tabDistance : " << tabDistance[indiceVecteur] << endl;
  flotBasique << "   tabPerformance : " << tabPerformance[indiceVecteur]
      << endl;
  flotBasique << "   tabWaitPassenger : " << tabWaitPassenger[indiceVecteur]
      << endl;
  flotBasique << "   tabEarlyArrival : " << tabEarlyArrival[indiceVecteur]
      << endl;
  flotBasique << "   tabRideExcess : " << tabRideExcess[indiceVecteur] << endl;
  // On passe au traitement de tabRideExcess
  indiceVecteur = calcul.Minimum(tabRideExcess);
  afficherSeparationCOUT(flotBasique);
  flotBasique << "Replication avec tabRideExcess : " << endl;
  flotBasique << " A  tabTpsGlobal(DUREE) : " << tabTpsGlobal[indiceVecteur]
      << endl;
  flotBasique << "  C tabTpsAttente(WAIT) : " << tabTpsAttente[indiceVecteur]
      << endl;
  flotBasique << "  B tabTpsDemande(Ride) : " << tabTpsDemande[indiceVecteur]
      << endl;
  flotBasique << "   tabDistance : " << tabDistance[indiceVecteur] << endl;
  flotBasique << "   tabPerformance : " << tabPerformance[indiceVecteur]
      << endl;
  flotBasique << "   tabWaitPassenger : " << tabWaitPassenger[indiceVecteur]
      << endl;
  flotBasique << "   tabEarlyArrival : " << tabEarlyArrival[indiceVecteur]
      << endl;
  flotBasique << "   tabRideExcess : " << tabRideExcess[indiceVecteur] << endl;
  afficherSeparationCOUT(flotBasique);
  flotBasique << " -- Tps Total pour toutes les replication : " << sommeTpsExe
      << endl;
  afficherSeparationCOUT(flotBasique);

  for (int i = 0; i < nombreReplication; ++i)
    {
      flotBasique << " R" << i;
      flotBasique << " - tabDistance : " << tabDistance[i];
      flotBasique << " ; tabRideExcess : " << tabRideExcess[i];
      flotBasique << " ; tabWaitPassenger : " << tabWaitPassenger[i];
      flotBasique << " ; tabTpsGlobal : " << tabTpsGlobal[i];
      flotBasique << " ; tabEarlyArrival : " << tabEarlyArrival[i];
      flotBasique << " ; tabTpsAttente : " << tabTpsAttente[i];
      flotBasique << " ; tabTpsDemande(Ride) : " << tabTpsDemande[i] << endl;
    }
}

/*
 * Fonction allouant les tableaux regroupant les donnees relatives aux replications
 */
void
Metier::allocationReplication()
{
  // On reserve la memoire d avance pour les vectors
  tabValTournees.reserve(nombreReplication);
  tabTpsAttente.reserve(nombreReplication);
  tabPerformance.reserve(nombreReplication);
  tabTpsGlobal.reserve(nombreReplication);
  tabTpsDemande.reserve(nombreReplication);
  tabDistance.reserve(nombreReplication);
  tabTempsExe.reserve(nombreReplication);
  tabEarlyArrival.reserve(nombreReplication);
  tabWaitPassenger.reserve(nombreReplication);
  tabRideExcess.reserve(nombreReplication);
}

/*
 * Fonction qui vide les tableaux relatifs aux replications
 */
void
Metier::desalloueReplication()
{
  // Nettoyage
  tabTournees.erase(tabTournees.begin(), tabTournees.end());
  tabSelection.erase(tabSelection.begin(), tabSelection.end());
  tabDemandes.erase(tabDemandes.begin(), tabDemandes.end());
  tabrejet.erase(tabrejet.begin(), tabrejet.end());
  tabBoolJ.erase(tabBoolJ.begin(), tabBoolJ.end());
}

/*
 * Methode pour ajouter une demande au vecteur
 */
void
Metier::ajoutDemande(const Demande & newDemande)
{
  tabDemandes.push_back(newDemande);
}

/*
 * Affichage Separation
 */
void
Metier::afficherSeparationCOUT(ofstream & sortie)
{
  sortie << endl << "---------------------------------------------------------"
      << endl;
}

/*
 * Affichage de tous les quatreUplet d une ou de toutes les demandes
 */
void
Metier::affichageQuatreUpletDemande(ofstream & sortie, int indiceDemande)
{
  if (indiceDemande > -1)
    {
      sortie << "Demande " << indiceDemande << endl;
      for (list<QuatreUplet *>::iterator it =
          tabSelection[indiceDemande].getDebutLibreXY();
          it != tabSelection[indiceDemande].getEndLibreXY(); it++)
        {
          sortie << "  Uplet  -> " << **it << endl;
        }
    }
  else
    {
      for (int i = 0; i < nombreDemandes; i++)
        {
          sortie << "Demande " << i << endl;
          for (list<QuatreUplet*>::iterator it =
              tabSelection[i].getDebutLibreXY();
              it != tabSelection[i].getEndLibreXY(); it++)
            {
              sortie << "  Uplet  -> " << **it << endl;
            }
        }
    }
}

/*
 * Affichage d une demande si l indice est negatif on affiche toutes les demandes
 */
void
Metier::affichageDemandes(ofstream & sortie, int indiceDemande)
{
  afficherSeparationCOUT(sortie);
  if (indiceDemande < 0) // Alors on affiche toutes les demandes
    {
      sortie << "                Afficage du tableau de demande " << endl;
      for (vector<Demande>::iterator itDemande = tabDemandes.begin();
          itDemande != tabDemandes.end(); itDemande++)
        {
          sortie << *itDemande << endl;
        }
    }
  else
    {
      sortie << "              Afficage de la demande n " << indiceDemande
          << endl;
    }
  afficherSeparationCOUT(sortie);
}

/*
 * Affichage des tournees si l indice est negatif on affiche toute les tournees
 */
void
Metier::affichageTournees(ofstream & sortie, int indiceTournee)
{
  afficherSeparationCOUT(sortie);
  list<Noeud *>::iterator itTourneePred;
  int i = 0;
  double miniDist = 0.0;

  if (indiceTournee < 0) // Alors on affiche toutes les tournees
    {
      sortie << "                 Affichage du tableau des tournees " << endl;
      for (vector<Tournee>::iterator itTournees = tabTournees.begin();
          itTournees != tabTournees.end(); itTournees++, i++)
        {
          afficherSeparationCOUT(sortie);
          sortie << "Tournne n " << i << endl;
          sortie << *itTournees << endl;
          sortie
              << "Affichage des DIST (avec tps de service) entre chaque noeud avec"
                  " calcul si besoin pour les noeuds Relais : " << endl;
          for (list<Noeud *>::iterator itTourneeNoeud =
              (++tabTournees[i].getItDebut());
              itTourneeNoeud != (tabTournees[i].getItEnd()); itTourneeNoeud++)
            {
              itTourneePred = itTourneeNoeud;
              itTourneePred--;

              if (((*itTourneePred)->getIndiceDsDist() > -1)
                  && ((*itTourneeNoeud)->getIndiceDsDist() > -1))
                miniDist =
                    DIST[(*itTourneePred)->getIndiceDsDist()][(*itTourneeNoeud)->getIndiceDsDist()];
              else
                miniDist = calcul.calculDistanceAvecService(*itTourneePred,
                    *itTourneeNoeud);

              sortie << miniDist << " ";

            }
          sortie << endl;
        }
    }
  else
    {
      sortie << "          Afficage de la tournee du vehicule n "
          << indiceTournee << endl;
      sortie << tabTournees[indiceTournee];
    }
  afficherSeparationCOUT(sortie);
}

/*
 * lecture des fichiers d'instances et remplissage
 * du tableau de tournees
 */
void
Metier::lireInstances(const char * nomFichierInstance)
{
  ifstream flotInstance(nomFichierInstance, ios::in);
  if (flotInstance)
    {
      int numeroDemande;
      double tempsDelta, tempsMaxTournee;
      double tempsDeService, chargement, fenetreMin, fenetreMax, coordX, coordY;
      // On lit la premiere ligne de renseignement
      flotInstance >> nombreVoitures >> nombreDemandes >> tempsMaxTournee
          >> capaciteVehicule >> tempsDelta;
      // On lit la premiere demande toujours vide
      flotInstance >> numeroDemande >> coordX >> coordY >> tempsDeService
          >> chargement >> fenetreMin >> fenetreMax;
      FminDepot = fenetreMin;
      FmaxDepot = fenetreMax;
      coordDepotY = coordY;
      coordDepotX = coordX;
      // On lit les origines de la demande
      Demande temp;
      temp.setDelta(tempsDelta);
      temp.setDeltaSave(tempsDelta);
      parametres.setTempsMaxTournee(tempsMaxTournee);
      // Le nombre de demande etait jusque la le nomre
      // de noeud
      nombreDemandes /= 2;
      for (int i = 0; i < nombreDemandes; i++)
        {
          Noeud * noeudOrigine = new Noeud();
          Noeud * noeudChargeOut = new Noeud();
          Noeud * noeudChargeIn = new Noeud();
          flotInstance >> numeroDemande >> coordX >> coordY >> tempsDeService
              >> chargement >> fenetreMin >> fenetreMax;

          chargement = chargement * lambdaCharge;

          temp.setOrigineX(coordX);
          temp.setOrigineY(coordY);
          temp.setFOrigineMin(fenetreMin);
          temp.setFOrigineMax(fenetreMax);
          temp.setQi(chargement);

          noeudOrigine->setX(coordX);
          noeudOrigine->setY(coordY);
          noeudOrigine->setStatus(0);
          noeudOrigine->setFPropageMin(fenetreMin);
          noeudOrigine->setFPropageMax(fenetreMax);
          noeudOrigine->setFMin(fenetreMin);
          noeudOrigine->setFMax(fenetreMax);
          noeudOrigine->setFPropageMinSave(fenetreMin);
          noeudOrigine->setFPropageMaxSave(fenetreMax);
          noeudOrigine->setQi(chargement);
          noeudOrigine->setIndiceDemande(i);
          noeudOrigine->setK(-1);
          noeudOrigine->setIndiceDsDist(i);
          noeudOrigine->setTempsDeService(tempsDeService);

          noeudChargeIn->setStatus(5);
          noeudChargeIn->setFPropageMin(fenetreMin);
          noeudChargeIn->setFMin(fenetreMin);
          noeudChargeIn->setFPropageMinSave(fenetreMin);
          noeudChargeIn->setQi(chargement);
          noeudChargeIn->setIndiceDemande(i);
          noeudChargeIn->setK(-1);
          noeudChargeIn->setIndiceDsDist(-1);
          noeudChargeIn->setTempsDeService(tempsDeService);

          noeudChargeOut->setStatus(4);
          noeudChargeOut->setFPropageMin(fenetreMin);

          temp.setNoeudOrigine(noeudOrigine);
          temp.setNoeudIn(noeudChargeIn);
          temp.setNoeudOut(noeudChargeOut);
          tabDemandes.push_back(temp);
        }
      // On lit les destinations
      for (int i = 0; i < nombreDemandes; i++)
        {
          Noeud * noeudDestination = new Noeud();
          flotInstance >> numeroDemande >> coordX >> coordY >> tempsDeService
              >> chargement >> fenetreMin >> fenetreMax;
          tabDemandes[i].setDestinationX(coordX);
          tabDemandes[i].setDestinationY(coordY);
          tabDemandes[i].setFDestinationMin(fenetreMin);
          tabDemandes[i].setFDestinationMax(fenetreMax);
          noeudDestination->setX(coordX);
          noeudDestination->setY(coordY);
          noeudDestination->setStatus(1);
          noeudDestination->setFPropageMin(fenetreMin);
          noeudDestination->setFPropageMax(fenetreMax);
          noeudDestination->setFPropageMinSave(fenetreMin);
          noeudDestination->setFPropageMaxSave(fenetreMax);
          noeudDestination->setFMin(fenetreMin);
          noeudDestination->setFMax(fenetreMax);
          noeudDestination->setQi(chargement);
          noeudDestination->setIndiceDemande(i);
          noeudDestination->setK(-1);
          noeudDestination->setIndiceDsDist(i + nombreDemandes);
          noeudDestination->setTempsDeService(tempsDeService);

          tabDemandes[i].getNoeudIn()->setFPropageMaxSave(fenetreMax);
          tabDemandes[i].getNoeudIn()->setFMax(fenetreMax);
          tabDemandes[i].getNoeudIn()->setFPropageMax(fenetreMax);

          tabDemandes[i].getNoeudOut()->setFPropageMaxSave(fenetreMax);
          tabDemandes[i].getNoeudOut()->setFMax(fenetreMax);
          tabDemandes[i].getNoeudOut()->setFPropageMax(fenetreMax);

          tabDemandes[i].setNoeudDestination(noeudDestination);
        }
      flotInstance.close();
    }
  else
    {
      cout << "Impossible d'ouvrir le fichier d'instances" << endl;
    }
}

/*
 * methode qui ecrit un quatreuplet et renvoie son adresse
 * cette methode permet d exclure toute allocation en memoire
 */
QuatreUplet *
Metier::newQuatreUplet(int k, list<Noeud *>::iterator itX,
    list<Noeud *>::iterator itY, double v)
{
  indiceTabTousQuatreuplet++;
  tabTousQuatreuplet[indiceTabTousQuatreuplet].setXIt(itX);
  tabTousQuatreuplet[indiceTabTousQuatreuplet].setYIt(itY);
  tabTousQuatreuplet[indiceTabTousQuatreuplet].setV(v);
  tabTousQuatreuplet[indiceTabTousQuatreuplet].setK(k);

  return &tabTousQuatreuplet[indiceTabTousQuatreuplet];
}

Noeud *
Metier::newNoeud()
{
  indiceTabTousNoeud++;

  return &tabTousNoeud[indiceTabTousNoeud];
}

/*
 *   initTournees() initie les tournees, depot compris
 */
void
Metier::initTournees(Parametres & param)
{
  // On connait les informations de l instances telle que le nombre de vehicule
  for (int i = 0; i < nombreVoitures; i++)
    {
      Demande temp;
      temp.setDelta(param.getTempsMaxTournee());
      temp.setDeltaSave(param.getTempsMaxTournee());
      temp.setOrigineX(coordDepotX);
      temp.setOrigineY(coordDepotY);
      temp.setDestinationX(coordDepotX);
      temp.setDestinationY(coordDepotY);
      temp.setFOrigineMin(FminDepot);
      temp.setFOrigineMax(FmaxDepot);
      temp.setQi(0.0);
      Noeud * noeudDepotDebut = new Noeud;
      Noeud * noeudDepotFIn = new Noeud;
      noeudDepotDebut->setX(coordDepotX);
      noeudDepotDebut->setY(coordDepotY);
      noeudDepotFIn->setX(coordDepotX);
      noeudDepotFIn->setY(coordDepotY);
      noeudDepotDebut->setK(i);
      noeudDepotFIn->setK(i);
      noeudDepotDebut->setQi(0.0);
      noeudDepotFIn->setQi(0.0);
      noeudDepotDebut->setChT(0.0);
      noeudDepotFIn->setChT(0.0);
      noeudDepotDebut->setStatus(2);
      noeudDepotFIn->setStatus(3);
      noeudDepotDebut->setIndiceDsDist((nombreDemandes * 2));
      noeudDepotFIn->setIndiceDsDist((nombreDemandes * 2));
      noeudDepotDebut->setIndiceDemande(nombreDemandes);
      noeudDepotFIn->setIndiceDemande(nombreDemandes);
      noeudDepotDebut->setFPropageMin(FminDepot);
      noeudDepotFIn->setFPropageMin(FminDepot);
      noeudDepotDebut->setFPropageMax(FmaxDepot);
      noeudDepotFIn->setFPropageMax(FmaxDepot);
      noeudDepotDebut->setFMin(FminDepot);
      noeudDepotFIn->setFMin(FminDepot);
      noeudDepotDebut->setFMax(FmaxDepot);
      noeudDepotFIn->setFMax(FmaxDepot);
      noeudDepotDebut->setFPropageMinSave(FminDepot);
      noeudDepotFIn->setFPropageMinSave(FminDepot);
      noeudDepotDebut->setFPropageMaxSave(FmaxDepot);
      noeudDepotFIn->setFPropageMaxSave(FmaxDepot);
      noeudDepotDebut->setTempsDeService(0);
      noeudDepotFIn->setTempsDeService(0);
      Tournee nouvelleTournee;
      nouvelleTournee.ajoutNoeud(noeudDepotDebut);
      nouvelleTournee.ajoutNoeud(noeudDepotFIn);
      temp.setNoeudOrigine(noeudDepotDebut);
      temp.setNoeudDestination(noeudDepotFIn);
      tabDemandes.push_back(temp);
      tabTournees.push_back(nouvelleTournee);
    }
  // Les compteurs d insertion sont initialises
  compteurJ = nombreDemandes;
  // Aucune demande n a encore ete inseree
  tabBoolJ.assign(nombreDemandes, true);
  // Aucune demande n a encore ete rejete
  tabrejet.assign(tabDemandes.size(), false);
  // La valeur de la tournee alors que tout le monde reste au depot est de 0
  tabValTournees.assign(tabTournees.size(), 0);
}

/*
 *   initSelection() initie des caracteristiques d insertions de la demande
 *   ATTENTION - cette methode doit etre envoye apres initTournees
 */
void
Metier::initSelection(ofstream & sortie)
{
  double tempv;

  indiceTabTousQuatreuplet = -1;
  indiceTabTousNoeud = -1;

  int tailleTab = nombreVoitures * nombreVoitures * nombreDemandes
      * nombreDemandes * 2;
  if (tabTousQuatreuplet)
    {
      delete[] tabTousQuatreuplet;
    }
  if (tabTousNoeud)
    {
      delete[] tabTousNoeud;
    }

  tabTousQuatreuplet = new QuatreUplet[tailleTab];
  tabTousNoeud = new Noeud[tailleTab];

  for (int i = 0; i < nombreDemandes; i++)
    {
      Selection tempSelection;
      tempSelection.setNbCarLibre(nombreVoitures);
      tempSelection.setN1(N1);
      tempSelection.setN2(N2);
      for (int k = 0; k < nombreVoitures; k++)
        {
          tempv = testInsertion(k, i, tabTournees[k].getItDebut(),
              tabTournees[k].getItDebut(), tabDemandes[i].getNoeudOrigine(),
              tabDemandes[i].getNoeudDestination(), sortie);
          if (tempv > 0.0 - calcul.getEpsilon())
            {
              tempSelection.insertListeTriee(
                  newQuatreUplet(k, tabTournees[k].getItDebut(),
                      tabTournees[k].getItDebut(), tempv));
            }
        }
      tabSelection.push_back(tempSelection);
    }
}

/*
 * Methode pour calculer les distances
 * entre les demandes et depot. Ce dernier
 * est place en bout de tableau
 * la premiere partie nombreDemandeSansDepot depend des origines
 * des demandes et la seconde les destinations
 */
void
Metier::calculDIST()
{
  vector<double> v;

  for (int i = 0; i < DIST.size(); i++)
    {
      for (int j = 0; j < DIST[i].size(); j++)
        {
          DIST[i].erase(DIST[i].begin(), DIST[i].end());
        }
      DIST.erase(DIST.begin(), DIST.end());
    }

  for (int i = 0; i < nombreDemandes * 2 + 1; i++)
    {
      DIST.push_back(v);
      for (int j = 0; j < nombreDemandes * 2 + 1; j++)
        {
          DIST[i].push_back(-1);
        }
    }
  for (int i = 0; i < nombreDemandes; i++)
    {
      for (int j = 0; j < nombreDemandes; j++)
        {
          DIST[i][j] = calcul.calculDistance(tabDemandes[i].getOrigineX(),
              tabDemandes[j].getOrigineX(), tabDemandes[i].getOrigineY(),
              tabDemandes[j].getOrigineY());
          DIST[i + nombreDemandes][j + nombreDemandes] = calcul.calculDistance(
              tabDemandes[i].getDestinationX(),
              tabDemandes[j].getDestinationX(),
              tabDemandes[i].getDestinationY(),
              tabDemandes[j].getDestinationY());
          DIST[i][j + nombreDemandes] = calcul.calculDistance(
              tabDemandes[i].getOrigineX(), tabDemandes[j].getDestinationX(),
              tabDemandes[i].getOrigineY(), tabDemandes[j].getDestinationY());
          DIST[i + nombreDemandes][j] = calcul.calculDistance(
              tabDemandes[i].getDestinationX(), tabDemandes[j].getOrigineX(),
              tabDemandes[i].getDestinationY(), tabDemandes[j].getOrigineY());
        }
    }
  // Calcul des distances depuis et jusqu au depot
  for (int i = 0; i < nombreDemandes; i++)
    {
      DIST[nombreDemandes * 2][i] = calcul.calculDistance(coordDepotX,
          tabDemandes[i].getOrigineX(), coordDepotY,
          tabDemandes[i].getOrigineY());
      DIST[i][nombreDemandes * 2] = DIST[nombreDemandes * 2][i];
      DIST[nombreDemandes * 2][i + nombreDemandes] = calcul.calculDistance(
          coordDepotX, tabDemandes[i].getDestinationX(), coordDepotY,
          tabDemandes[i].getDestinationY());
      DIST[i + nombreDemandes][nombreDemandes * 2] = DIST[nombreDemandes * 2][i
          + nombreDemandes];
    }
  DIST[nombreDemandes * 2][nombreDemandes * 2] = 0;
  // On affecte directement a la matrice a qui on ajoute pas les temps de service
  DISTSansService = DIST;
}

/*
 * Addition des temps de service de chaque noeud
 * sur DIST, donc 2 ajouts par distance entre deux noeuds
 */
void
Metier::additionDistTpsService()
{
  for (int i = 0; i < nombreDemandes; i++)
    {
      for (int j = 0; j < nombreDemandes; j++)
        {
          // Ici nous n augmentons qu a partir des orgines dont depot et non jusqu au depot
          DIST[i][j] +=
              (((tabDemandes[i].getNoeudOrigine())->getTempsDeService()))
                  * parametres.getUniteTempsDeService();
          DIST[i][j + nombreDemandes] +=
              ((tabDemandes[i].getNoeudOrigine())->getTempsDeService())
                  * parametres.getUniteTempsDeService();
          DIST[i + nombreDemandes][j] +=
              (((tabDemandes[i].getNoeudOrigine())->getTempsDeService()))
                  * parametres.getUniteTempsDeService();
          DIST[i + nombreDemandes][j + nombreDemandes] +=
              (((tabDemandes[i].getNoeudOrigine())->getTempsDeService()))
                  * parametres.getUniteTempsDeService();
        }
      /*
       // Le deuxieme noeud sera toujours une origine
       DIST[nombreDemandes *2][i] += (((tabDemandes[i].getNoeudOrigine())->getTempsDeService()))
       * parametres.getUniteTempsDeService();
       */
      // L avant dernier noeud sera toujours une destination
      DIST[i + nombreDemandes][nombreDemandes * 2] +=
          (((tabDemandes[i].getNoeudOrigine())->getTempsDeService()))
              * parametres.getUniteTempsDeService();
      DIST[i][nombreDemandes * 2] +=
          (((tabDemandes[i].getNoeudOrigine())->getTempsDeService()))
              * parametres.getUniteTempsDeService();
    }
}

/*
 * Soustraction des temps de service sur les durees maximum
 * ici on ajoute la moitie de chaque temps de service des deux
 * noeuds de la demande.
 */
void
Metier::additionDeltaTpsService()
{
  for (int i = 0; i < nombreDemandes; i++)
    {
      tabDemandes[i].setDelta(
          tabDemandes[i].getDelta()
              + ((tabDemandes[i].getNoeudOrigine())->getTempsDeService()
                  * parametres.getUniteTempsDeService()));
    }
}

/*
 * Affichage de la matrice DIST
 */
void
Metier::affichageDIST(ofstream & sortie)
{
  afficherSeparationCOUT(sortie);
  sortie << endl << "Affichage de DIST" << endl;
  for (int i = 0; i < nombreDemandes * 2 + 1; i++)
    {
      for (int j = 0; j < nombreDemandes * 2 + 1; j++)
        {
          sortie << DIST[i][j] << " ";
        }
      sortie << endl;
    }
  sortie << endl << "Fin Affichage" << endl;
  sortie << endl << "Affichage de DISTSansService" << endl;
  for (int i = 0; i < nombreDemandes * 2 + 1; i++)
    {
      for (int j = 0; j < nombreDemandes * 2 + 1; j++)
        {
          sortie << DISTSansService[i][j] << " ";
        }
      sortie << endl;
    }
  sortie << endl << "Fin Affichage DISTSansService" << endl;
  afficherSeparationCOUT(sortie);
}

/*
 * Methode qui produit une reduction prealable des fenetres de temps
 * avant toute insertion
 */
void
Metier::pretraitementSurFenetre()
{
  Noeud * noeudOrigine;
  Noeud * noeudDestination;
  double DeltaTemp;
  for (vector<Demande>::iterator itDemande = tabDemandes.begin();
      itDemande != tabDemandes.end(); itDemande++)
    {
      DeltaTemp = (*itDemande).getDelta();

      noeudOrigine = (*itDemande).getNoeudOrigine();
      noeudDestination = (*itDemande).getNoeudDestination();

      noeudOrigine->setFMin(
          calcul.SUP(noeudOrigine->getFMin(),
              DIST[2 * nombreDemandes][noeudOrigine->getIndiceDsDist()]));

      noeudDestination->setFMin(
          calcul.SUP(noeudDestination->getFMin(),
              DIST[2 * nombreDemandes][noeudOrigine->getIndiceDsDist()]
                  + DIST[noeudOrigine->getIndiceDsDist()][noeudDestination->getIndiceDsDist()]));

      noeudOrigine->setFMin(
          calcul.SUP(noeudOrigine->getFMin(),
              noeudDestination->getFMin() - DeltaTemp));

      noeudOrigine->setFMax(
          calcul.INF(noeudOrigine->getFMax(),
              noeudDestination->getFMax()
                  - DIST[noeudOrigine->getIndiceDsDist()][noeudDestination->getIndiceDsDist()]));

      noeudDestination->setFMax(
          calcul.INF(noeudDestination->getFMax(),
              noeudOrigine->getFMax() + DeltaTemp));

      noeudDestination->setFMin(
          calcul.SUP(noeudDestination->getFMin(),
              noeudOrigine->getFMin()
                  + DIST[noeudOrigine->getIndiceDsDist()][noeudDestination->getIndiceDsDist()]));
    }
}

/*
 * Recupere l adresse d un noeud jumeau s il existe
 * Null sinon
 */
Noeud *
Metier::ptSurJumeau(Noeud * frere)
{
  int indiceDemandeDepot;
  if ((frere->getStatus() > 1) && (frere->getStatus() < 4))
    {
      indiceDemandeDepot = frere->getIndiceDemande() + frere->getK();
    }
  else if (frere->getStatus() < 2)
    {
      indiceDemandeDepot = frere->getIndiceDemande();
    }      // Controle de sortie
  else
    return NULL;
  // Si le noeud est l origine
  if (tabDemandes[indiceDemandeDepot].getNoeudOrigine() == frere)
    return tabDemandes[indiceDemandeDepot].getNoeudDestination();
  else
    return tabDemandes[indiceDemandeDepot].getNoeudOrigine();
}

/*
 * Regle pour la propagation des fenetres de temps
 * suite a une insertion
 * La methose renvoi vrai si changement il y a eu
 */
bool
Metier::R1Propagation(Noeud * itx, Noeud * ity, Calcul & calcul)
{
  // Les temps de service sont deja dans DIST
  // et sont soustrait dans les fenetres de chaque
  // noeud et dans le temps maximum
  double DistanceEntreNoeud;

  DistanceEntreNoeud = DIST[itx->getIndiceDsDist()][ity->getIndiceDsDist()];

  if ((itx->getFPropageMin() + DistanceEntreNoeud)
      > ity->getFPropageMin() + calcul.getEpsilon())
    {
      // On realoque un iterateur sur le noeud modifier
      ity->setFPropageMin(itx->getFPropageMin() + DistanceEntreNoeud);
      return true;
    }
  return false;
}

/*
 * Regle pour la propagation des fenetres de temps
 * suite a une insertion
 */
bool
Metier::R2Propagation(Noeud * itx, Noeud * ity, Calcul & calcul)
{
  // Les temps de service sont deja dans DIST
  // et sont soustrait dans les fenetres de chaque
  // noeud et dans le temps maximum
  double DistanceEntreNoeud;

  DistanceEntreNoeud = DIST[itx->getIndiceDsDist()][ity->getIndiceDsDist()];

  if ((ity->getFPropageMax() - DistanceEntreNoeud) + calcul.getEpsilon()
      < itx->getFPropageMax())
    {
      // On realoque un iterateur sur le noeud modifier
      itx->setFPropageMax(ity->getFPropageMax() - DistanceEntreNoeud);
      return true;
    }
  return false;
}

/*
 * Regle pour la propagation des fenetres de temps
 * suite a une insertion x est homologue de y & x<<=y
 */
bool
Metier::R3Propagation(Noeud * itx, Noeud * ity, double delta, Calcul & calcul)
{
  if (itx->getFPropageMin() + calcul.getEpsilon()
      < (ity->getFPropageMin() - delta))
    {
      // On realoque un iterateur sur le noeud modifier
      itx->setFPropageMin(ity->getFPropageMin() - delta);
      return true;
    }
  return false;
}

/*
 * Regle pour la propagation des fenetres de temps
 * suite a une insertion x est homologue de y & x<<=y
 */
bool
Metier::R4Propagation(Noeud * itx, Noeud * ity, double delta, Calcul & calcul)
{
  if (ity->getFPropageMax()
      > (itx->getFPropageMax() + delta + calcul.getEpsilon()))
    {
      // On realoque un iterateur sur le noeud modifier
      ity->setFPropageMax(itx->getFPropageMax() + delta);
      return true;
    }
  return false;
}

/*
 * Regle pour la propagation des fenetres de temps
 * suite a une insertion
 * Renvoi si finalement l'insertion permet
 * une tournee temps valide
 */
bool
Metier::R5Propagation(Noeud * itx)
{
  if (itx->getFPropageMin() > (itx->getFPropageMax() + calcul.getEpsilon()))
    {
      // Non ! l'insertion ne doit pas se faire !!
      return false;
    }
  else
    {
      return true;
    }
}

/*
 * Methode de propagation des fenetres de temps
 * en entree nous avons :
 *    - l'indice de la tournee ou les contraintes de temps vont etre propagees
 *    - la liste d iterateurs sur une liste de pointeur sur noeuds
 *    qui tenteront d etre inseres, liste generique mais
 *    qui tres probablement ne contiendra que l origine et la destinatin d une
 *    demande en entree.
 */
bool
Metier::propagerFenetreTemps(const int indiceTournee,
    list<list<Noeud *>::iterator> & ListeitListPointeurSurNoeud,
    Calcul & calcul, ofstream & sortie)
{
  list<Noeud *>::iterator z;
  list<Noeud *>::iterator pred;
  list<Noeud *>::iterator succ;
  Noeud * zjumeau = NULL;

  // On sauve le end() pour ne pas faire de longs acces
  list<Noeud*>::iterator itFInListNoeudTournee =
      tabTournees[indiceTournee].getItEnd();

  fromFPrSaveToFPr(indiceTournee, tabTournees[indiceTournee].getItDebut(),
      itFInListNoeudTournee);

  while (ListeitListPointeurSurNoeud.size())
    {
      ListeitListPointeurSurNoeud.unique();
      z = (*ListeitListPointeurSurNoeud.begin());
      ListeitListPointeurSurNoeud.pop_front();
      //
      // Regles Sucesseurs sur DIST
      //
      // Regles R1 & R2
      if (z != tabTournees[indiceTournee].getItDebut())
        {
          pred = z;
          pred--;
          // On lance la regle et on sauvegarde le noeud si changement
          if (R1Propagation(*pred, *z, calcul))
            {
              list<Noeud *>::iterator nouveauPourListe = z;
              ListeitListPointeurSurNoeud.push_back(nouveauPourListe);
            }
          if (R2Propagation(*pred, *z, calcul))
            {
              list<Noeud *>::iterator nouveauPourListe = pred;
              ListeitListPointeurSurNoeud.push_back(nouveauPourListe);
            }
        }
      if (z != (--tabTournees[indiceTournee].getItEnd()))
        {
          succ = z;
          succ++;
          if (R1Propagation(*z, *succ, calcul))
            {
              list<Noeud *>::iterator nouveauPourListe = succ;
              ListeitListPointeurSurNoeud.push_back(nouveauPourListe);
            }
          if (R2Propagation(*z, *succ, calcul))
            {
              list<Noeud *>::iterator nouveauPourListe = z;
              ListeitListPointeurSurNoeud.push_back(nouveauPourListe);
            }
        }
      //
      // Regles Jumeaux sur Delta
      zjumeau = ptSurJumeau(*z);
      if (zjumeau)
        {
          // Si z est la destination (rappel : depot ne peut etre present ici)
          if (((*z)->getStatus() == 3) || ((*z)->getStatus() == 1))
            {
              // S il y a eu modification de la fenetre
              if (R3Propagation(zjumeau, *z,
                  tabDemandes[(*z)->getIndiceDemande()].getDelta(), calcul))
                {
                  // Petite recherche (et c est dommage)
                  // du jumeau en N comparaisons d adresses au max
                  list<Noeud *>::iterator nouveauPourListe = find(
                      tabTournees[indiceTournee].getItDebut(),
                      tabTournees[indiceTournee].getItEnd(), zjumeau);
                  if (nouveauPourListe == tabTournees[indiceTournee].getItEnd())
                    {
                      sortie
                          << "Probleme avec FIND jumeau de Propagate si 0 ou 2"
                          << endl;
                    }
                  else
                    ListeitListPointeurSurNoeud.push_back(nouveauPourListe);
                }
              if (R4Propagation(zjumeau, *z,
                  tabDemandes[(*z)->getIndiceDemande()].getDelta(), calcul))
                {
                  list<Noeud *>::iterator nouveauPourListe = z;
                  ListeitListPointeurSurNoeud.push_back(nouveauPourListe);
                }
            }
          else // Sinon.... c est l origine
            {

              if (R3Propagation(*z, zjumeau,
                  tabDemandes[(*z)->getIndiceDemande()].getDelta(), calcul))
                {
                  list<Noeud *>::iterator nouveauPourListe = z;
                  ListeitListPointeurSurNoeud.push_back(nouveauPourListe);
                }

              if (R4Propagation(*z, zjumeau,
                  tabDemandes[(*z)->getIndiceDemande()].getDelta(), calcul))
                {
                  // Petite recherche (et c est dommage)
                  // du jumeau en N comparaisons d adresses au max
                  list<Noeud *>::iterator nouveauPourListe = find(
                      tabTournees[indiceTournee].getItDebut(),
                      tabTournees[indiceTournee].getItEnd(), zjumeau);
                  if (nouveauPourListe == tabTournees[indiceTournee].getItEnd())
                    {
                      sortie
                          << "Probleme avec FIND jumeau de Propagate si 1 ou 3 "
                          << endl;
                    }
                  else
                    ListeitListPointeurSurNoeud.push_back(nouveauPourListe);
                }
            }
        }
      else
        cout << " Probleme dans la recherche de jumeau " << endl;

      //        //
      //        // Test de reussite
      //        //
      if (!R5Propagation(*z))
        {
          return false;
        }
    }
  return true;
}

/*
 * Methode d evaluation du temps gloable d une tournee
 */
double
Metier::TpsGlobalTournee(int indiceTournee)
{
  return (*(--tabTournees[indiceTournee].getItEnd()))->getT()
      - (*tabTournees[indiceTournee].getItDebut())->getT();
}

/*
 * Methode d evaluation du temps gloable d une tournee
 */
double
Metier::TpsGlobalTourneeSave(int indiceTournee)
{
  return (*(--tabTournees[indiceTournee].getItEnd()))->getSave()
      - (*tabTournees[indiceTournee].getItDebut())->getSave();
}

/*
 * Methode d evaluation du temps individuel soit la somme
 * de chaque connexion
 */
double
Metier::TpsDemandesTournee(int indiceTournee)
{
  double somme = 0.0;

  // On fait sauter les deux depot englobant la tournee
  for (list<Noeud *>::iterator itTournee =
      (++tabTournees[indiceTournee].getItDebut());
      itTournee != (--tabTournees[indiceTournee].getItEnd()); itTournee++)
    {
      if ((*itTournee)->getStatus() == 1) // C est une destination
        {
          somme += (*itTournee)->getT();
        }
      else if ((*itTournee)->getStatus() == 0)
        {
          somme -= (*itTournee)->getT();
        }
    }
  return somme;
}

/*
 * Methode d evaluation du temps individuel soit la somme
 * de chaque connexion
 */
double
Metier::TpsDemandesTourneeSave(int indiceTournee)
{
  double somme = 0.0;

  // On fait sauter les deux depot englobant la tournee
  for (list<Noeud *>::iterator itTournee =
      (++tabTournees[indiceTournee].getItDebut());
      itTournee != (--tabTournees[indiceTournee].getItEnd()); itTournee++)
    {
      if ((*itTournee)->getStatus() == 1) // Ce n est ni depot ni origine
        {
          somme += (*itTournee)->getSave();
        }
      else if ((*itTournee)->getStatus() == 0)
        {
          somme -= (*itTournee)->getSave();
        }
    }
  return somme;
}

/*
 * Methode calculant le temps supplementaire pris par une tournee
 * par rapport a DIST
 */
double
Metier::TpsAttenteTournee(int indiceTournee, double & tpsGlobal)
{
  double somme = 0.0;
  double miniDist = 0.0;
  list<Noeud *>::iterator itTourneePred;
  for (list<Noeud *>::iterator itTournee =
      (++tabTournees[indiceTournee].getItDebut());
      itTournee != (tabTournees[indiceTournee].getItEnd()); itTournee++)
    {
      itTourneePred = itTournee;
      itTourneePred--;

      if (((*itTourneePred)->getIndiceDsDist() > -1)
          && ((*itTournee)->getIndiceDsDist() > -1))
        miniDist =
            DIST[(*itTourneePred)->getIndiceDsDist()][(*itTournee)->getIndiceDsDist()];
      else
        miniDist = calcul.calculDistanceAvecService(*itTourneePred, *itTournee);

      somme += miniDist;

    }
  somme = tpsGlobal - somme;
  if (somme < calcul.getEpsilon())
    return 0.0;
  return somme;
}

/*
 * Methode de perf pour toutes les tournees en cours
 */
double
Metier::EvalTouteTournee()
{
  double perfGlobale = 0.0;

  for (int i = 0; i < nombreVoitures; i++)
    {
      perfGlobale = EvalTournee(i);
    }
  return perfGlobale;
}

/*
 * Methode de perf pour toutes les tournees
 */
double
Metier::EvalTouteTourneeSave()
{
  double perfGlobale = 0.0;

  for (int i = 0; i < nombreVoitures; i++)
    {
      perfGlobale = EvalTourneeSave(i);
    }
  return perfGlobale;
}

/*
 * Methode d evaluation des temps de passage d une tournee
 * selon les trois criteres
 */
double
Metier::EvalTournee(int indiceTournee)
{
  // En commentaire : fonction Objectif de Jorgensen
  /*
   double tpsGlobal = TpsGlobalTournee(indiceTournee);
   return A * calculDistanceParcourue(indiceTournee)
   + B * TpsDemandesTourneeExcess(indiceTournee)
   + C * EvalWaitPassenger(indiceTournee) + D * tpsGlobal
   + E * nombreDemandes * EvalEarlyArrival(indiceTournee);
   */

  double tpsGlobal = TpsGlobalTournee(indiceTournee);
  return A * TpsGlobalTournee(indiceTournee)
      + B * TpsDemandesTournee(indiceTournee)
      + C * TpsAttenteTournee(indiceTournee, tpsGlobal)
      + D * calculDistanceParcourue(indiceTournee);
}

/*
 * Methode d evaluation des temps de passage d une tournee
 * selon les trois criteres
 */
double
Metier::EvalTourneeSave(int indiceTournee)
{
  // En commentaire : fonction Objectif de Jorgensen
  /*
   double tpsGlobal = TpsGlobalTourneeSave(indiceTournee);
   return A * calculDistanceParcourue(indiceTournee) + B
   * TpsDemandesTourneeExcessSave(indiceTournee) + C
   * EvalWaitPassengerSave(indiceTournee) + D * tpsGlobal + E
   * nombreDemandes * EvalEarlyArrivalSave(indiceTournee);
   */

  double tpsGlobal = TpsGlobalTourneeSave(indiceTournee);
  return A * TpsGlobalTourneeSave(indiceTournee)
      + B * TpsDemandesTourneeSave(indiceTournee)
      + C * TpsAttenteTournee(indiceTournee, tpsGlobal)
      + D * calculDistanceParcourue(indiceTournee);
}

/*
 * Methode d evaluation de wait passenger
 */
double
Metier::EvalEarlyArrival(int indiceTournee)
{
  double EarlyArrival = 0.0;
  double somme = 0.0;
  double miniDist = 0.0;
  list<Noeud *>::iterator itTourneePred;

  for (list<Noeud *>::iterator itTournee =
      (++tabTournees[indiceTournee].getItDebut());
      itTournee != (--tabTournees[indiceTournee].getItEnd()); itTournee++)
    {
      itTourneePred = itTournee;
      itTourneePred--;

      if (((*itTourneePred)->getIndiceDsDist() > -1)
          && ((*itTournee)->getIndiceDsDist() > -1))
        miniDist =
            DIST[(*itTourneePred)->getIndiceDsDist()][(*itTournee)->getIndiceDsDist()];
      else
        miniDist = calcul.calculDistanceAvecService(*itTourneePred, *itTournee);

      somme = (*itTournee)->getFMin() - ((*itTourneePred)->getT() + miniDist);

      if (somme > 0.0)
        EarlyArrival += somme;
    }
  return EarlyArrival;
}

/*
 * Methode d evaluation de wait passenger
 */
double
Metier::EvalWaitPassenger(int indiceTournee)
{
  double EvalWaitPassenger = 0.0;
  double somme = 0.0;
  double miniDist = 0.0;
  list<Noeud *>::iterator itTourneePred;

  for (list<Noeud *>::iterator itTournee =
      (++tabTournees[indiceTournee].getItDebut());
      itTournee != (--tabTournees[indiceTournee].getItEnd()); itTournee++)
    {
      itTourneePred = itTournee;
      itTourneePred--;

      if (((*itTourneePred)->getIndiceDsDist() > -1)
          && ((*itTournee)->getIndiceDsDist() > -1))
        miniDist =
            DIST[(*itTourneePred)->getIndiceDsDist()][(*itTournee)->getIndiceDsDist()];
      else
        miniDist = calcul.calculDistanceAvecService(*itTourneePred, *itTournee);

      somme = (*itTourneePred)->getT() + miniDist;

      somme = (*itTournee)->getT() - somme;
      EvalWaitPassenger += somme
          * ((*itTournee)->getChT() - (*itTournee)->getQi());
    }
  return EvalWaitPassenger;
}

/*
 * Methode calculant la difference entre le ride et ce qu il aurait du etre
 */
double
Metier::TpsDemandesTourneeExcess(int indiceTournee)
{
  double somme = 0.0;
  double sommeDISTRide = 0.0;
  double miniDist = 0.0;
  Noeud * jumeauIt;

  // On fait sauter les deux depot englobant la tournee
  for (list<Noeud *>::iterator itTournee =
      (++tabTournees[indiceTournee].getItDebut());
      itTournee != (--tabTournees[indiceTournee].getItEnd()); itTournee++)
    {
      if ((*itTournee)->getStatus() == 1) // C est une destination
        {
          somme += (*itTournee)->getT();
        }
      else if ((*itTournee)->getStatus() == 0)
        {
          jumeauIt = ptSurJumeau(*itTournee);

          if (((*itTournee)->getIndiceDsDist() > -1)
              && ((jumeauIt)->getIndiceDsDist() > -1))
            miniDist =
                DIST[(*itTournee)->getIndiceDsDist()][(jumeauIt)->getIndiceDsDist()];
          else
            miniDist = calcul.calculDistanceAvecService(*itTournee, jumeauIt);

          sommeDISTRide += miniDist;

          somme -= (*itTournee)->getT();
        }
    }
  return somme - sommeDISTRide;
}

/*
 * Methode d evaluation de wait passenger
 */
double
Metier::EvalEarlyArrivalSave(int indiceTournee)
{
  double EarlyArrival = 0.0;
  double somme = 0.0;
  double miniDist = 0.0;
  list<Noeud *>::iterator itTourneePred;

  for (list<Noeud *>::iterator itTournee =
      (++tabTournees[indiceTournee].getItDebut());
      itTournee != (--tabTournees[indiceTournee].getItEnd()); itTournee++)
    {
      itTourneePred = itTournee;
      itTourneePred--;

      if (((*itTourneePred)->getIndiceDsDist() > -1)
          && ((*itTournee)->getIndiceDsDist() > -1))
        miniDist =
            DIST[(*itTourneePred)->getIndiceDsDist()][(*itTournee)->getIndiceDsDist()];
      else
        miniDist = calcul.calculDistanceAvecService(*itTourneePred, *itTournee);

      somme = (*itTournee)->getFMin()
          - ((*itTourneePred)->getSave() + miniDist);

      if (somme > 0.0)
        EarlyArrival += somme;
    }
  return EarlyArrival;
}

/*
 * Methode d evaluation de wait passenger
 */
double
Metier::EvalWaitPassengerSave(int indiceTournee)
{
  double EvalWaitPassenger = 0.0;
  double somme = 0.0;
  list<Noeud *>::iterator itTourneePred;

  for (list<Noeud *>::iterator itTournee =
      (++tabTournees[indiceTournee].getItDebut());
      itTournee != (--tabTournees[indiceTournee].getItEnd()); itTournee++)
    {
      itTourneePred = itTournee;
      itTourneePred--;

      if (((*itTourneePred)->getIndiceDsDist() > -1)
          && ((*itTournee)->getIndiceDsDist() > -1))
        somme =
            (*itTourneePred)->getSave()
                + DIST[(*itTourneePred)->getIndiceDsDist()][(*itTournee)->getIndiceDsDist()];
      else
        somme = (*itTourneePred)->getSave()
            + calcul.calculDistanceAvecService(*itTourneePred, *itTournee);

      somme = (*itTournee)->getSave() - somme;
      EvalWaitPassenger += somme
          * ((*itTournee)->getChT() - (*itTournee)->getQi());
    }
  return EvalWaitPassenger;
}

/*
 * Methode calculant la difference entre le ride et ce qu il aurait du etre
 */
double
Metier::TpsDemandesTourneeExcessSave(int indiceTournee)
{
  double somme = 0.0;
  double sommeDISTRide = 0.0;
  Noeud * jumeauIt;

  // On fait sauter les deux depot englobant la tournee
  for (list<Noeud *>::iterator itTournee =
      (++tabTournees[indiceTournee].getItDebut());
      itTournee != (--tabTournees[indiceTournee].getItEnd()); itTournee++)
    {
      if ((*itTournee)->getStatus() == 1) // C est une destination
        {
          somme += (*itTournee)->getSave();
        }
      else if ((*itTournee)->getStatus() == 0)
        {
          jumeauIt = ptSurJumeau(*itTournee);
          if (((*itTournee)->getIndiceDsDist() > -1)
              && ((jumeauIt)->getIndiceDsDist() > -1))
            sommeDISTRide +=
                DIST[(*itTournee)->getIndiceDsDist()][(jumeauIt)->getIndiceDsDist()];
          else
            sommeDISTRide += calcul.calculDistanceAvecService(*itTournee,
                jumeauIt);
          somme -= (*itTournee)->getSave();
        }
    }
  return somme - sommeDISTRide;
}

/*
 * Fonction calculant la distance parcourue par les vehicules
 * si indiceTournne est < 0 on calcule la distance globale
 */
double
Metier::calculDistanceParcourue(int indiceTournee)
{
  double distanceTotale = 0.0;
  list<Noeud *>::iterator itNoeudPred;
  if (indiceTournee < 0) // Alors on calcule toute les distances
    {
      for (vector<Tournee>::iterator itTournees = tabTournees.begin();
          itTournees != tabTournees.end(); itTournees++)
        {
          // On teste si la tournee n est pas vide
          list<Noeud *>::iterator itTemp = (++(*itTournees).getItDebut());
          itTemp++;
          if (itTemp != (*itTournees).getItEnd())
            {
              // Pour toute la tournee
              for (list<Noeud *>::iterator itNoeud =
                  (++(*itTournees).getItDebut());
                  itNoeud != (*itTournees).getItEnd(); itNoeud++)
                {
                  // On recupere le predecesseur
                  itNoeudPred = itNoeud;
                  itNoeudPred--;
                  if (((*itNoeudPred)->getIndiceDsDist() > -1)
                      && ((*itNoeud)->getIndiceDsDist() > -1))
                    distanceTotale +=
                        DISTSansService[(*itNoeudPred)->getIndiceDsDist()][(*itNoeud)->getIndiceDsDist()];
                  else
                    distanceTotale += calcul.calculDistance(*itNoeudPred,
                        *itNoeud);
                }
            }
        }
    }
  else // Alors on ne calcule que pour une seule tournee
    {
      for (list<Noeud *>::iterator itNoeud =
          (++(tabTournees[indiceTournee].getItDebut()));
          itNoeud != tabTournees[indiceTournee].getItEnd(); itNoeud++)
        {
          // On recupere le predecesseur
          itNoeudPred = itNoeud;
          itNoeudPred--;

          if (((*itNoeudPred)->getIndiceDsDist() > -1)
              && ((*itNoeud)->getIndiceDsDist() > -1))
            distanceTotale +=
                DISTSansService[(*itNoeudPred)->getIndiceDsDist()][(*itNoeud)->getIndiceDsDist()];
          else
            distanceTotale += calcul.calculDistance(*itNoeudPred, *itNoeud);
        }
    }
  return distanceTotale;
}

/*
 * Methode deffinissant un temps de passage
 * renvoyant une premiere evaluation d une tournee
 */
double
Metier::evalTour1(int indiceTournee)
{
  list<Noeud *>::iterator x;
  list<Noeud *>::iterator y;
  double somme;

  x = tabTournees[indiceTournee].getItDebut();
  // On pousse a droite de la fenetre de temps d emblee
  (*x)->setT((*x)->getFPropageMax());
  while (x != (--tabTournees[indiceTournee].getItEnd()))
    {
      // y est le successeur
      y = x;
      y++;
      somme = (*x)->getT()
          + DIST[(*x)->getIndiceDsDist()][(*y)->getIndiceDsDist()];
      if ((*y)->getFPropageMin() < somme)
        (*y)->setT(somme);
      else
        (*y)->setT((*y)->getFPropageMin());
      x = y;
    }
  EvalTournee(indiceTournee);
}

/*
 * Methode definissant un etat (E2) pour evalTour2
 */
bool
Metier::E2(Noeud * x, Noeud * xsucc)
{
  return ((calculLambdaEval2(x->getStatus()) < 0)
      &&((x->getStatus() == 0) || (x->getStatus() == 2))
      && ((x->getT()
          != calcul.INF(x->getFPropageMax(),
              xsucc->getT()
                  - DIST[x->getIndiceDsDist()][xsucc->getIndiceDsDist()]))));
}

/*
 * Methode definissant un etat (E3) pour evalTour2
 */
bool
Metier::E3(Noeud * xpred, Noeud * x)
{
  return ((calculLambdaEval2(x->getStatus()) > 0)
      && ((x->getStatus() == 1) || (x->getStatus() == 3))
      && ((x->getT()
          != calcul.SUP(x->getFPropageMin(),
              xpred->getT()
                  + DIST[xpred->getIndiceDsDist()][x->getIndiceDsDist()]))));
}

double
Metier::calculLambdaEval2(int status)
{
  // A OPTIMISER : ces calculs doivent etre faits en amont
  if (status == 0)
    return -B;
  if (status == 1)
    return B;
  if (status == 2)
    return -(A + B + C);
  if (status == 3)
    return A + B + C;
}

/*
 * Methode appelant la precedente et qui affine le boulot
 */
double
Metier::evalTour2(int indiceTournee, ofstream & sortie)
{
  list<Noeud *>::iterator xit;
  list<Noeud *>::iterator xsuccit;
  list<Noeud *>::iterator xpredit;
  bool Continue = true;
  bool E2Bool;
  bool E3Bool;

  evalTour1(indiceTournee);
  // Tant qu un scan de la tournee a apporte des modifications
  while (Continue)
    {
      Continue = false;
      // On scanne et effectue les changements sur toute la tournee
      for (xit = tabTournees[indiceTournee].getItDebut();
          xit != tabTournees[indiceTournee].getItEnd(); xit++)
        {
          // Les EiBool ne prennent pas forcement de nouvelles valeurs
          // il faut donc les initialiser a chaque for
          E3Bool = false;
          E2Bool = false;
          // Si itx a un predecesseur
          if (xit != tabTournees[indiceTournee].getItDebut())
            {
              xpredit = xit;
              xpredit--;
              E3Bool = E3(*xpredit, *xit);
            }
          else if (xit != (--tabTournees[indiceTournee].getItEnd()))
            { // itx a un successeur
              xsuccit = xit;
              xsuccit++;
              E2Bool = E2(*xit, *xsuccit);
            }
          if (E3Bool)
            {
              // Il faudra relancer le FOR
              Continue = true;
              (*xit)->setT(
                  calcul.SUP((*xit)->getFPropageMin(),
                      (*xpredit)->getT()
                          + DIST[(*xpredit)->getIndiceDsDist()][(*xit)->getIndiceDsDist()]));
            }
          else if (E2Bool)
            {
              // Il faudra relancer le FOR
              Continue = true;
              (*xit)->setT(
                  calcul.INF((*xit)->getFPropageMax(),
                      (*xsuccit)->getT()
                          - DIST[(*xit)->getIndiceDsDist()][(*xsuccit)->getIndiceDsDist()]));
            }
        }
    }
  return EvalTournee(indiceTournee);
}

/*
 * Test si l insertion ne change pas la validite en terme
 * de charge de la tournee, renvoi bool vrai si tout va
 * bien - entre x NON compris alors que y l est
 */
bool
Metier::testCharge(int indiceTournee, list<Noeud *>::iterator x,
    list<Noeud *>::iterator y, int indiceDemande)
{
  list<Noeud *>::iterator itTournee = x;
  list<Noeud *>::iterator itFinSegement = y;
  itFinSegement++;
  // On teste si l'insertion apres x puis apres y ne pose aucun probleme
  while (itTournee != itFinSegement)
    {
      if ((*itTournee)->getChT() + tabDemandes[indiceDemande].getQi()
          > capaciteVehicule + calcul.getEpsilon())
        {
          return false;
        }
      else
        {
          // if ((*itTournee)->getStatus()==3)
          itTournee++;
        }
    }
  return true;
}

/*
 * test2Charge concerne la preemption de vehicule. elle appelle a deux reprise
 * la methode precedente pour les deux tournees considerees
 */
bool
Metier::test2Charge(int indiceTournee1, list<Noeud *>::iterator x1,
    list<Noeud *>::iterator y1, int indiceTournee2, list<Noeud *>::iterator x2,
    list<Noeud *>::iterator y2, int indiceDemande)
{
  return (testCharge(indiceTournee1, x1, y1, indiceDemande))
      && (testCharge(indiceTournee2, x2, y2, indiceDemande));
}

/*
 * Maj de la charge courante avec la nouvelle charge
 * de la nouvelle demande inseree a droite de x et y
 */
void
Metier::PropageCharge(int indiceTournee, list<Noeud *>::iterator xsucc,
    list<Noeud *>::iterator ysucc, int indiceDemande, ofstream & sortie)
{
  /*
   double chargeQ = tabDemandes[indiceDemande].getQi();
   // Ici xsucc a forcement un precedent meme si c est un depot
   list<Noeud *>::iterator x = xsucc;
   x--;
   // Meme chose pour le cote destination
   list<Noeud *>::iterator y = ysucc;
   y--;
   list<Noeud *>::iterator itTourneeXsucctoY = xsucc;
   itTourneeXsucctoY++;

   // On affecte la charge courante supplee de la charge de la demande
   (*xsucc)->setChT((*x)->getChT() + chargeQ);
   // On affecte la charge courante avant que la charge ne soit ajoutee
   if (*y == *xsucc)
   {
   (*ysucc)->setChT((*x)->getChT());
   }
   else
   {
   (*ysucc)->setChT((*y)->getChT());
   }

   // On fait la MAJ le long du chemin a droite de itTourneeXsucctoY jusqu a
   // droite de y
   for (; itTourneeXsucctoY != ysucc; itTourneeXsucctoY++)
   {
   (*itTourneeXsucctoY)->setChT((*itTourneeXsucctoY)->getChT() + chargeQ);
   }

   */

  double chargeQ;

  for (list<Noeud *>::iterator x = tabTournees[indiceTournee].getItDebut();
      x != (--tabTournees[indiceTournee].getItEnd()); x++)
    {
      xsucc = x;
      xsucc++;

      chargeQ = tabDemandes[(*xsucc)->getIndiceDemande()].getQi();

      if (((*xsucc)->getStatus() == 1) || ((*xsucc)->getStatus() == 4))
        {
          chargeQ = -chargeQ;
        }
      else if (((*xsucc)->getStatus() == 2) || ((*xsucc)->getStatus() == 3))
        {
          chargeQ = 0.0;
        }
      (*xsucc)->setChT((*x)->getChT() + chargeQ);
    }
}

/*
 * Fonction qui recupere les fenetre sauvegarde depuis la derniere insertion
 * entre deux noeuds ces derniers compris
 */
void
Metier::fromFPrSaveToFPrxy(int indiceTournee, list<Noeud *>::iterator x,
    list<Noeud *>::iterator y)
{
  list<Noeud *>::iterator fin = y;
  fin++;

  // On affecte les fenetres sauvees aux propagees des noeuds
  // On affecte les fenetres d entrees aux propagees des noeuds
  for (list<Noeud*>::iterator itListNoeudTournee = x; itListNoeudTournee != fin;
      itListNoeudTournee++)
    {
      (*itListNoeudTournee)->setFPropageMin(
          (*itListNoeudTournee)->getFPropageMinSave());
      (*itListNoeudTournee)->setFPropageMax(
          (*itListNoeudTournee)->getFPropageMaxSave());
    }
}

/*
 * Fonction initialisant les fenetre propagee a leur fenetre initiale
 * entre deux noeuds x et y (compris) d une tournee
 */
void
Metier::fromFPrSaveToFPr(int indiceTournee, list<Noeud *>::iterator x,
    list<Noeud *>::iterator y)
{
  // On affecte les fenetres sauvees aux propagees des noeuds
  // On affecte les fenetres d entrees aux propagees des noeuds
  for (list<Noeud*>::iterator itListNoeudTournee = x; itListNoeudTournee != y;
      itListNoeudTournee++)
    {
      (*itListNoeudTournee)->setFPropageMin(
          (*itListNoeudTournee)->getFPropageMinSave());
      (*itListNoeudTournee)->setFPropageMax(
          (*itListNoeudTournee)->getFPropageMaxSave());
    }
}

/*
 * testUnNoeud determine la validite d un noeud entre deux autres
 * retourne VRAI si c est valide.
 */
bool
Metier::testUnNoeud(list<Noeud *>::iterator z, list<Noeud *>::iterator zz,
    Noeud * u, int indiceDemande, int indiceTournee)
{
  double Fmin;
  double Fmax;

  fromFPrSaveToFPrxy(indiceTournee, z, zz);

  // Si c est une destination
  if (u->getStatus())
    {
      Fmin = tabDemandes[indiceDemande].getFDestinationMin();
      Fmax = tabDemandes[indiceDemande].getFDestinationMax();
    }
  else // Sinon une origine - les depots ne sont plus inseres a ce niveau
    {
      Fmin = tabDemandes[indiceDemande].getFOrigineMin();
      Fmax = tabDemandes[indiceDemande].getFOrigineMax();
    }
  return ((((*z)->getFPropageMin()
      + DIST[(*z)->getIndiceDsDist()][u->getIndiceDsDist()]) <= Fmax)
      && (Fmin + DIST[u->getIndiceDsDist()][(*zz)->getIndiceDsDist()]
          <= (*zz)->getFPropageMax())
      && ((*z)->getFPropageMin()
          + DIST[(*z)->getIndiceDsDist()][u->getIndiceDsDist()]
          + DIST[u->getIndiceDsDist()][(*zz)->getIndiceDsDist()]
          <= (*zz)->getFPropageMax())
      && (((*z)->getChT()) + u->getQi() <= capaciteVehicule));
}

/*
 * testDeuxNoeud determine la validite de deux noeud entre deux autres
 * retourne VRAI si c est valide.
 */
double
Metier::testDeuxNoeudslist(list<Noeud *>::iterator z,
    list<Noeud *>::iterator zz, Noeud * u, Noeud * v, int indiceDemande,
    int indiceTournee)
{
  double FminU;
  double FmaxU;
  double FminV;
  double FmaxV;

  // On initialise les fenetre de temps
  fromFPrSaveToFPrxy(indiceTournee, z, zz);
  // U par defaut est l origine et V la destination
  FminU = tabDemandes[indiceDemande].getFOrigineMin();
  FmaxU = tabDemandes[indiceDemande].getFOrigineMax();
  FminV = tabDemandes[indiceDemande].getFDestinationMin();
  FmaxV = tabDemandes[indiceDemande].getFDestinationMax();
  return ((((*z)->getFPropageMin()
      + DIST[(*z)->getIndiceDsDist()][u->getIndiceDsDist()]) <= FmaxU)
      && (FminU + DIST[u->getIndiceDsDist()][v->getIndiceDsDist()] <= FmaxV)
      && (FminV + DIST[v->getIndiceDsDist()][(*zz)->getIndiceDsDist()]
          <= (*zz)->getFPropageMax())
      && ((*z)->getFPropageMin()
          + DIST[(*z)->getIndiceDsDist()][u->getIndiceDsDist()]
          + DIST[u->getIndiceDsDist()][v->getIndiceDsDist()] <= FmaxV)
      && ((*z)->getFPropageMin()
          + DIST[(*z)->getIndiceDsDist()][u->getIndiceDsDist()]
          + DIST[u->getIndiceDsDist()][v->getIndiceDsDist()]
          + DIST[v->getIndiceDsDist()][(*zz)->getIndiceDsDist()]
          <= (*zz)->getFPropageMax())
      && (FminU + DIST[u->getIndiceDsDist()][v->getIndiceDsDist()]
          + DIST[v->getIndiceDsDist()][(*zz)->getIndiceDsDist()]
          <= (*zz)->getFPropageMax())
      && (((*z)->getChT()) + u->getQi() <= capaciteVehicule));
}

/*
 * Test l insertion, renvoi la nouvelle valeur de la tournee nouvelle
 * cette valeur est infinie negative sinon
 * ATTENTION dans cette methode : on insere x et y puis on les retire
 */
double
Metier::testInsertion(int indiceTournee, int indiceDemande,
    list<Noeud *>::iterator x, list<Noeud *>::iterator y, Noeud * oIt,
    Noeud * dIt, ofstream & sortie)
{
  bool insertPossible;
  double valeurInsertion = -calcul.getInfiniDouble();
  list<Noeud *>::iterator xsucc = x;
  xsucc++;
  list<Noeud *>::iterator ysucc = y;
  ysucc++;
  list<list<Noeud *>::iterator> ListeitListPointeurSurNoeud;

  if (x != y)
    {
      insertPossible = (testUnNoeud(x, xsucc, oIt, indiceDemande, indiceTournee)
          && (testUnNoeud(y, ysucc, dIt, indiceDemande, indiceTournee)));
    }
  else
    {
      // si x = y on insere entre x (donc y) et successeur(x)
      insertPossible = testDeuxNoeudslist(x, xsucc, oIt, dIt, indiceDemande,
          indiceTournee);
    }
  if (insertPossible)
    { // Le test de charge se fait a partir de x
      if (testCharge(indiceTournee, x, y, indiceDemande))
        {
          // On insere temporairement les noeuds
          // L'insertion se fair sur l iterateur donc au final
          // avant la valeur prealabl//ement pointee donc on utilise succ.
          // on insere x avant y puisque on incremente les deux successeurs avant
          list<Noeud *>::iterator nvNoeudOrigine =
              tabTournees[indiceTournee].insererNoeud(xsucc, oIt);
          list<Noeud *>::iterator nvNoeudDestination =
              tabTournees[indiceTournee].insererNoeud(ysucc, dIt);
          ListeitListPointeurSurNoeud.push_back(nvNoeudOrigine);
          ListeitListPointeurSurNoeud.push_back(nvNoeudDestination);
          insertPossible = propagerFenetreTemps(indiceTournee,
              ListeitListPointeurSurNoeud, calcul, sortie);
          // On vire les noeuds ils seront, s ils le doivent, inseres plus tard
          if (insertPossible)
            {
              valeurInsertion = evalTour2(indiceTournee, sortie);

              //valeurInsertion = evalTour1(indiceTournee);
            }
          tabTournees[indiceTournee].sortirNoeud(nvNoeudOrigine);
          tabTournees[indiceTournee].sortirNoeud(nvNoeudDestination);
        }
    }
  return valeurInsertion - tabValTournees[indiceTournee];
}

/*
 *
 */
double
Metier::INSER2(int indiceTournee, int indiceDemande, list<Noeud *>::iterator x,
    list<Noeud *>::iterator y, Noeud * oIt, Noeud * dIt, ofstream & sortie)
{
  bool insertPossible;
  double valeurInsertion = -calcul.getInfiniDouble();
  list<Noeud *>::iterator xsucc = x;
  xsucc++;
  list<Noeud *>::iterator ysucc = y;
  ysucc++;
  list<list<Noeud *>::iterator> ListeitListPointeurSurNoeud;

  if (x != y)
    {
      insertPossible = (testUnNoeud(x, xsucc, oIt, indiceDemande, indiceTournee)
          && (testUnNoeud(y, ysucc, dIt, indiceDemande, indiceTournee)));
    }
  else
    {
      // si x = y on insere entre x (donc y) et successeur(x)
      insertPossible = testDeuxNoeudslist(x, xsucc, oIt, dIt, indiceDemande,
          indiceTournee);
    }
  if (insertPossible)
    { // Le test de charge se fait a partir de x
      if (testCharge(indiceTournee, x, y, indiceDemande))
        {
          // On insere temporairement les noeuds
          // L'insertion se fair sur l iterateur donc au final
          // avant la valeur prealabl//ement pointee donc on utilise succ.
          // on insere x avant y puisque on incremente les deux successeurs avant
          list<Noeud *>::iterator nvNoeudOrigine =
              tabTournees[indiceTournee].insererNoeud(xsucc, oIt);
          list<Noeud *>::iterator nvNoeudDestination =
              tabTournees[indiceTournee].insererNoeud(ysucc, dIt);
          ListeitListPointeurSurNoeud.push_back(nvNoeudOrigine);
          ListeitListPointeurSurNoeud.push_back(nvNoeudDestination);
          insertPossible = propagerFenetreTemps(indiceTournee,
              ListeitListPointeurSurNoeud, calcul, sortie);
          // On vire les noeuds ils seront, s ils le doivent, inseres plus tard
          if (insertPossible)
            {
              valeurInsertion = tabDemandes[indiceDemande].amplitude();

            }
          tabTournees[indiceTournee].sortirNoeud(nvNoeudOrigine);
          tabTournees[indiceTournee].sortirNoeud(nvNoeudDestination);
        }
    }
  return valeurInsertion;
}

/*
 *
 */
double
Metier::INSER1(int indiceTournee, int indiceDemande, ofstream & sortie)
{
  double max = -calcul.getInfiniDouble(), temp;

  for (list<QuatreUplet*>::iterator itUplet =
      tabSelection[indiceDemande].getDebutLibreXY();
      itUplet != tabSelection[indiceDemande].getEndLibreXY(); itUplet++)
    {
      if ((*itUplet)->getK() == indiceTournee)
        {
          temp = INSER2(indiceTournee, indiceDemande, (*itUplet)->getXIt(),
              (*itUplet)->getYIt(),
              tabDemandes[indiceDemande].getNoeudOrigine(),
              tabDemandes[indiceDemande].getNoeudDestination(), sortie);
          if (temp > max)
            {
              max = temp;
            }
        }
    }
  if (max < 0.0)
    {
      return 0.0;
    }
  else
    {
      return max;
    }
}

double
Metier::INSER(int indiceDemande, ofstream & sortie)
{
  double INSER1val = 0.0;
  for (int i = 0; i < nombreVoitures; i++)
    {
      INSER1val += INSER1(i, indiceDemande, sortie);
    }
  return INSER1val;

  /*
   double max = -calcul.getInfiniDouble();
   double temp;
   for (int i = 0; i < nombreVoitures; i++)
   {
   temp = INSER1(i, indiceDemande, sortie);
   if ( max < temp )  max = temp;
   }
   return max;*/

}

int
Metier::SelectionDemandeINSERABILITE(ofstream & sortie)
{
  int retourneNum;
  double InserValMin = calcul.getInfiniDouble(), InserVal;

  for (int i = 0; i < nombreDemandes; i++)
    {
      if (tabBoolJ[i])
        {
          InserVal = INSER(i, sortie);
          if (InserVal < InserValMin)
            {
              retourneNum = i;
              InserValMin = InserVal;
            }
        }
    }
  return retourneNum;
}

int
Metier::SelectionDemandeMaxINSERABILITE(ofstream & sortie)
{
  list<int> selection1;
  int retourneNum = -1;
  double InserValMax = -calcul.getInfiniDouble(), InserVal;

  for (int i = 0; i < nombreDemandes; i++)
    {
      if (tabBoolJ[i])
        {
          InserVal = INSER(i, sortie);
          if (InserVal > InserValMax)
            {
              retourneNum = i;
              InserValMax = InserVal;
            }
        }
    }
  return retourneNum;
}

/*
 * Test la duree max de connexion pour un noeud relais
 */
bool
Metier::testTpsMaxConnexion(int indiceTournee1, int indiceTournee2, int i0,
    list<Noeud *>::iterator x1, list<Noeud *>::iterator x2,
    list<Noeud *>::iterator y1, list<Noeud *>::iterator y2, Noeud * z,
    ofstream & sortie)
{
  // Il faut savoir qu'ici nous n'avons pas encore ins�r�.
  double distance = 0.0;
  list<Noeud *>::iterator xtemp;
  list<Noeud *>::iterator xtempSucc;

  xtemp = x1;
  xtempSucc = x1;
  xtempSucc++;
  // On traite le premier vehicule
  // Si les points d'ancrage sont identiques
  if (*x1 == *y1)
    {
      distance += calcul.calculDistanceAvecService(
          tabDemandes[i0].getNoeudOrigine(), z);
    }
  else if (*y1 == *xtempSucc)
    {
      distance += calcul.calculDistanceAvecService(
          tabDemandes[i0].getNoeudOrigine(), *y1)
          + calcul.calculDistanceAvecService(*y1, z);
    }
  else
    {
      distance += calcul.calculDistanceAvecService(
          tabDemandes[i0].getNoeudOrigine(), *xtempSucc)
          + calcul.calculDistanceAvecService(*y1, z);
      xtemp++;
      xtempSucc++;
      // On y ajoute le reste
      while (xtemp != y1)
        {
          distance += calcul.calculDistanceAvecService(*xtemp, *xtempSucc);
          xtemp++;
          xtempSucc++;
        }
    }
  // On traite le second vehicule
  xtemp = x2;
  xtempSucc = x2;
  xtempSucc++;
  // On traite le premier vehicule
  // Si les points d'ancrage sont identiques
  if (*x2 == *y2)
    {
      distance += calcul.calculDistanceAvecService(z,
          tabDemandes[i0].getNoeudDestination());
    }
  else if (*y2 == *xtempSucc)
    {
      distance += calcul.calculDistanceAvecService(z, *y2)
          + calcul.calculDistanceAvecService(*y2,
              tabDemandes[i0].getNoeudDestination());
    }
  else
    {
      distance += calcul.calculDistanceAvecService(z, *xtempSucc)
          + calcul.calculDistanceAvecService(*y2,
              tabDemandes[i0].getNoeudDestination());
      xtemp++;
      xtempSucc++;
      // On y ajoute le reste
      while (xtemp != y2)
        {
          distance += calcul.calculDistanceAvecService(*xtemp, *xtempSucc);
          xtemp++;
          xtempSucc++;
        }
    }
  return (distance < tabDemandes[i0].getDelta());
}

/*
 * Methode qui recupere la demande qui va etre inseree
 */
int
Metier::selectionDemandeE4(Calcul & calcul, ofstream & sortie)
{
  list<int> selection1;
  int minNbCarLibre = calcul.getInfiniInt();
  int retourneNum;

  // On cherche le plus petit NbCarLibre
  for (int i = 0; i < nombreDemandes; i++)
    {
      if (tabBoolJ[i])
        {
          if (minNbCarLibre > tabSelection[i].getNbCarLibre())
            {
              minNbCarLibre = tabSelection[i].getNbCarLibre();
              retourneNum = i;
            }
        }
    }
  if (minNbCarLibre == 0)
    {
      return retourneNum;
    }
  else
    {
      // Si la population n est que de 1 on tire aleatoireemnt dedant sinon on agrandit
      if ((minNbCarLibre == 1) || (minNbCarLibre > N1))
        {
          // On met de cote toutes les demandes egales a minNbCarLibre
          for (int i = 0; i < nombreDemandes; i++)
            {
              if (tabBoolJ[i])
                {
                  if (minNbCarLibre == tabSelection[i].getNbCarLibre())
                    {
                      selection1.push_back(i);
                    }
                }
            }

          int indiceAleatoire = calcul.randInt(selection1.size());
          list<int>::iterator itInt = selection1.begin();
          for (int i = 0; i < indiceAleatoire; i++)
            {
              itInt++;
            }
          return *itInt;
        }
      // Sinon on remplit selection1 avec toutes les demandes de minNbCarLibre a N1
      else
        {
          for (int i = 0; i < nombreDemandes; i++)
            {
              if (tabBoolJ[i])
                {
                  if ((tabSelection[i].getNbCarLibre() >= minNbCarLibre)
                      && (tabSelection[i].getNbCarLibre() <= N1))
                    {
                      selection1.push_back(i);
                    }
                }
            }
          int indiceAleatoire = calcul.randInt(selection1.size());
          list<int>::iterator itInt = selection1.begin();
          for (int i = 0; i < indiceAleatoire; i++)
            {
              itInt++;
            }
          return *itInt;
        }
    }
}

/*
 * Methode qui recupere le 4-uplet qui va etre inseree
 */
QuatreUplet *
Metier::selectionDemandeE5(int indiceDemande, Calcul & calcul,
    ofstream & sortie)
{
  int indiceAleatoire;
  int Ntemp;

  if (N2 > tabSelection[indiceDemande].getLibreXY().size())
    Ntemp = tabSelection[indiceDemande].getLibreXY().size();
  else
    {
      Ntemp = N2;
    }

  indiceAleatoire = calcul.randInt(Ntemp);

  list<QuatreUplet*>::iterator itInt =
      tabSelection[indiceDemande].getDebutLibreXY();
  for (int i = 0; i < indiceAleatoire; i++)
    itInt++;
  return *itInt;
}

bool
Metier::testExclusion(int indiceDemande, QuatreUplet * itUplet,
    ofstream & sortie)
{
  double SommeInserValAv = 0, SommeInserValAp = 0;

  for (int i = 0; i < nombreDemandes; i++)
    {
      if (tabBoolJ[i] && indiceDemande != i)
        {
          SommeInserValAv += INSER(i, sortie);
        }
    }

  // On fixe le seuil a 0 puisque ce sera la derniere demande qui sera inseree en
  // de fonction, sinon on calcul ce seuil selon l inserabilite globale
  if (compteurJ)
    SEUIL = 1 * (SommeInserValAv);
  else
    SEUIL = 0.0;

  list<Noeud *>::iterator xsucc = (itUplet)->getXIt();
  xsucc++;
  list<Noeud *>::iterator ysucc = (itUplet)->getYIt();
  ysucc++;

  list<Noeud *>::iterator nvNoeudOrigine =
      tabTournees[(itUplet)->getK()].insererNoeud(xsucc,
          tabDemandes[indiceDemande].getNoeudOrigine());
  list<Noeud *>::iterator nvNoeudDestination =
      tabTournees[(itUplet)->getK()].insererNoeud(ysucc,
          tabDemandes[indiceDemande].getNoeudDestination());

  for (int i = 0; i < nombreDemandes; i++)
    {
      if (tabBoolJ[i] && indiceDemande != i)
        {
          SommeInserValAp += INSER(i, sortie);
        }
    }

  tabTournees[(itUplet)->getK()].sortirNoeud(nvNoeudOrigine);
  tabTournees[(itUplet)->getK()].sortirNoeud(nvNoeudDestination);

  if ((SEUIL > (SommeInserValAv - SommeInserValAp)) || (SEUIL == 0.0))
    {
      return false;
    }
  else
    {
      return true;
    }

}

QuatreUplet *
Metier::selectionE5Inserabilite(int indiceDemande, Calcul & calcul,
    ofstream & sortie)
{
  double maxMinINSERXY = -calcul.getInfiniDouble();
  double minINSER1 = calcul.getInfiniDouble();
  double minINSER2 = calcul.getInfiniDouble();
  double sommeMax = -calcul.getInfiniDouble();
  double tempSomme = 0;
  double tempINSER;
  int tempIndiceDemandeProchaine, tempIndiceDemandeProchaine2;

  QuatreUplet* UpletSave;

  indiceDemandeProchaine2 = -1;
  indiceDemandeProchaine = -1;

  for (list<QuatreUplet*>::iterator itUplet =
      tabSelection[indiceDemande].getDebutLibreXY();
      itUplet != tabSelection[indiceDemande].getEndLibreXY(); itUplet++)
    {
      list<Noeud *>::iterator xsucc = (*itUplet)->getXIt();
      xsucc++;
      list<Noeud *>::iterator ysucc = (*itUplet)->getYIt();
      ysucc++;

      list<Noeud *>::iterator nvNoeudOrigine =
          tabTournees[(*itUplet)->getK()].insererNoeud(xsucc,
              tabDemandes[indiceDemande].getNoeudOrigine());
      list<Noeud *>::iterator nvNoeudDestination =
          tabTournees[(*itUplet)->getK()].insererNoeud(ysucc,
              tabDemandes[indiceDemande].getNoeudDestination());

      minINSER1 = calcul.getInfiniDouble();
      minINSER2 = calcul.getInfiniDouble();

      tempSomme = 0;

      for (int i = 0; i < nombreDemandes; i++)
        {
          if ((tabBoolJ[i]) && (i != indiceDemande))
            {
              tempINSER = INSER(i, sortie);
              tempSomme += tempINSER;
              if (tempINSER < minINSER2)
                {
                  if (tempINSER < minINSER1)
                    {
                      minINSER2 = minINSER1;
                      tempIndiceDemandeProchaine2 = tempIndiceDemandeProchaine;
                      minINSER1 = tempINSER;
                      tempIndiceDemandeProchaine = i;
                    }
                  else
                    {
                      minINSER2 = tempINSER;
                      tempIndiceDemandeProchaine2 = i;
                    }
                }
            }
        }
      if (minINSER1 + minINSER2 > maxMinINSERXY)
        {
          maxMinINSERXY = minINSER1 + minINSER2;
          //    UpletSave = *itUplet;
          indiceDemandeProchaine2 = tempIndiceDemandeProchaine2;
          indiceDemandeProchaine = tempIndiceDemandeProchaine;
        }

      if (tempSomme > sommeMax)
        {
          sommeMax = tempSomme;
          UpletSave = *itUplet;
        }

      tabTournees[(*itUplet)->getK()].sortirNoeud(nvNoeudOrigine);
      tabTournees[(*itUplet)->getK()].sortirNoeud(nvNoeudDestination);
    }
  return UpletSave;
}

/*
 * insertionCoeur - Methode principale d insertion et propagation
 */
double
Metier::insertionCoeur(Calcul &, ofstream & sortie, bool processSeul)
{
  QuatreUplet * tempQuatreUplet;
  list<Noeud *>::iterator xsucc;
  list<Noeud *>::iterator ysucc;
  list<Noeud *>::iterator itListeTournee;
  list<Noeud *>::iterator itListeTournee2;
  list<Noeud *>::iterator itListeTourneeSucc;
  Noeud * noeudOrigine;
  Noeud * noeudDestination;
  list<list<Noeud *>::iterator> ListeitListPointeurSurNoeud;
  int i0;
  int k0;
  int reussi = 1;
  indiceDemandeProchaine = -1;
  double val;
  double EvalToutesTournees = 0.0;
  // Variables pour calculer le temps d'execution
  double elapsed;
  bool exclu;
  bool deuxiemePassage = false;
  vector<int> vectIndexInsertionFin;

  clock_t start, end;
  // On lance le chrono
  start = clock();

  while (compteurJ)
    {

      i0 = selectionDemandeE4(calcul, sortie);

      // On va chercher une voiture et puis remettre en place toute les possibilite
      // Pour chaque demande qui peuvent avoir changees
      if ((i0 == -1) || (!tabSelection[i0].getLibreXY().size()))
        {
          insertionRatees++;
          // On enleve i0 des demandes a insinsertionCoeurerer
          compteurJ--;
          tabBoolJ[i0] = false;
          tabrejet[i0] = true;
          //  cout << "i0 : " << i0 << endl;
          reussi = 0;
        }
      else
        {
          // On enleve i0 des demandes a inserer
          compteurJ--;
          tabBoolJ[i0] = false;
          // On recupere le 4uplet selon E5

          tempQuatreUplet = selectionDemandeE5(i0, calcul, sortie);
          // tempQuatreUplet = selectionE5Inserabilite(i0, calcul, sortie);

          exclu = false;

          // En commentaire un test de l exclusion
          // d une demande si celle impact trop
          // la flexibilite de la tournee
          /*      if (!deuxiemePassage)
           exclu = testExclusion(i0, tempQuatreUplet, sortie); */

          if (exclu)
            {
              vectIndexInsertionFin.push_back(i0);
              //  cout << "i0 : " << i0 << endl;
            }
          else
            {
              // On a selectionne la voiture
              k0 = tempQuatreUplet->getK();
              tabDemandes[i0].setKpourTous(k0);

              // En commentaire : petit affichage de la demande inseree
              //          sortie << " iO : " << i0 << " et compteur j " << compteurJ
              //              << " val11 " << tabBoolJ[i0] << " vehicule selectionne k0 : "
              //              << k0 << endl;
              // On insere la demande dans la tournee k0
              // On prend le successeur puisque l heuristique parle d insertion a droite
              // alors que la STL realise une insertion a gauche
              // On commence par y car on incremente un par un

              ysucc = tempQuatreUplet->getYIt();
              ysucc++;
              ysucc = tabTournees[k0].insererNoeud(ysucc,
                  tabDemandes[i0].getNoeudDestination());
              xsucc = tempQuatreUplet->getXIt();
              xsucc++;
              xsucc = tabTournees[k0].insererNoeud(xsucc,
                  tabDemandes[i0].getNoeudOrigine());
              //Il faut propager le poid dans le segment de la demande
              PropageCharge(k0, xsucc, ysucc, i0, sortie);
              // On met de cote les valeur de tk mais pour cela on doit propager
              // On vide la liste
              ListeitListPointeurSurNoeud.erase(
                  ListeitListPointeurSurNoeud.begin(),
                  ListeitListPointeurSurNoeud.end());
              ListeitListPointeurSurNoeud.push_back(xsucc);
              ListeitListPointeurSurNoeud.push_back(ysucc);
              // On propage les fenetre pour pouvoir placer les rdv t
              propagerFenetreTemps(k0, ListeitListPointeurSurNoeud, calcul,
                  sortie);
              // A TESTER
              for (itListeTournee = tabTournees[k0].getItDebut();
                  itListeTournee != tabTournees[k0].getItEnd();
                  itListeTournee++)
                {
                  (*itListeTournee)->setFPropageMinSave(
                      (*itListeTournee)->getFPropageMin());
                  (*itListeTournee)->setFPropageMaxSave(
                      (*itListeTournee)->getFPropageMax());
                }
              // A TESTER
              // On calcule les rdv t et on sauve la valeur de la tournee actuelle
              tabValTournees[k0] = evalTour2(k0, sortie);
              // On sauve les rdv t et FPropage
              // A TESTER
              for (itListeTournee = tabTournees[k0].getItDebut();
                  itListeTournee != tabTournees[k0].getItEnd();
                  itListeTournee++)
                {
                  (*itListeTournee)->setSave((*itListeTournee)->getT());
                }

              /*

               // A TESTER
               // MAJ de LibreXY et NbCarLibre
               // On met a jour tous les 4uplets deja present
               // Pour toutes les demandes
               for (int numDemande = 0; numDemande < nombreDemandes;
               numDemande++)
               {
               // Si la demande n est pas encore inseree ou alors a ete rejete ensuite
               if (tabBoolJ[numDemande]
               || (find(vectIndexInsertionFin.begin(),
               vectIndexInsertionFin.end(), numDemande)
               != vectIndexInsertionFin.end()))
               {
               // On met de cote les adresse des noeuds de la demande a inserer
               noeudOrigine = tabDemandes[numDemande].getNoeudOrigine();
               noeudDestination =
               tabDemandes[numDemande].getNoeudDestination();
               list<list<QuatreUplet*>::iterator> listeAEffacer;
               list<QuatreUplet *> listeAAjouter;
               // Pour tous les 4uplets deja present dans LibreXY
               int i = 0;
               for (list<QuatreUplet*>::iterator itUplet =
               tabSelection[numDemande].getDebutLibreXY();
               itUplet != tabSelection[numDemande].getEndLibreXY();
               itUplet++)
               {
               i++;
               // Si on parle bien du meme vehicule
               if ((*itUplet)->getK() == k0)
               {
               val = testInsertion(k0, numDemande,
               (*itUplet)->getXIt(), (*itUplet)->getYIt(),
               noeudOrigine, noeudDestination, sortie);
               if (val < 0)
               {
               // Il faut enlever ce 4Uplet
               listeAEffacer.push_back(itUplet);
               }
               else
               {
               // Il faut juste mettre a jour val et reinserer pour
               // garder le caractere trie de la liste
               (*itUplet)->setV(val);
               listeAEffacer.push_back(itUplet);
               listeAAjouter.push_back(*itUplet);
               }
               if ((*itUplet)->getXIt() != (*itUplet)->getYIt())
               {
               itListeTournee = (*itUplet)->getXIt();
               itListeTournee++;
               if (((*itListeTournee)->getIndiceDemande()
               == i0)
               // && ((*itListeTournee)->getStatus() == 0)
               )
               {
               val = testInsertion(k0, numDemande,
               itListeTournee, (*itUplet)->getYIt(),
               noeudOrigine, noeudDestination,
               sortie);
               if (val > 0)
               {

               listeAAjouter.push_back(
               newQuatreUplet(k0, itListeTournee,
               (*itUplet)->getYIt(), val));
               }
               }

               itListeTournee = (*itUplet)->getYIt();
               itListeTournee++;
               if (((*itListeTournee)->getIndiceDemande()
               == i0)
               //      && ((*itListeTournee)->getStatus() == 1)
               )
               {
               val = testInsertion(k0, numDemande,
               (*itUplet)->getXIt(), itListeTournee,
               noeudOrigine, noeudDestination,
               sortie);
               if (val > 0)
               {
               listeAAjouter.push_back(
               newQuatreUplet(k0,
               (*itUplet)->getXIt(),
               itListeTournee, val));
               }
               }
               }
               else
               {
               itListeTournee = (*itUplet)->getXIt();
               itListeTournee++;
               if ((*itListeTournee)->getIndiceDemande()
               == i0)
               {
               val = testInsertion(k0, numDemande,
               itListeTournee, itListeTournee,
               noeudOrigine, noeudDestination,
               sortie);
               if (val > 0)
               {
               listeAAjouter.push_back(
               newQuatreUplet(k0, itListeTournee,
               itListeTournee, val));
               }
               }
               if ((*itListeTournee)->getIndiceDemande()
               == i0)
               {
               val = testInsertion(k0, numDemande,
               (*itUplet)->getXIt(), itListeTournee,
               noeudOrigine, noeudDestination,
               sortie);
               if (val > 0)
               {
               listeAAjouter.push_back(
               newQuatreUplet(k0,
               (*itUplet)->getXIt(),
               itListeTournee, val));
               }
               }
               itListeTournee2 = (*itUplet)->getYIt();
               itListeTournee2++;
               itListeTournee2++;
               itListeTournee = (*itUplet)->getXIt();
               itListeTournee++;
               if (((*itListeTournee)->getIndiceDemande()
               == i0)
               && ((*itListeTournee2)->getIndiceDemande()
               == i0))
               {
               val = testInsertion(k0, numDemande,
               itListeTournee, itListeTournee2,
               noeudOrigine, noeudDestination,
               sortie);
               if (val > 0)
               {
               listeAAjouter.push_back(
               newQuatreUplet(k0, itListeTournee,
               itListeTournee2, val));
               }
               val = testInsertion(k0, numDemande,
               itListeTournee2, itListeTournee2,
               noeudOrigine, noeudDestination,
               sortie);
               if (val > 0)
               {
               listeAAjouter.push_back(
               newQuatreUplet(k0,
               itListeTournee2,
               itListeTournee2, val));
               }
               val = testInsertion(k0, numDemande,
               (*itUplet)->getXIt(), itListeTournee2,
               noeudOrigine, noeudDestination,
               sortie);
               if (val > 0)
               {
               listeAAjouter.push_back(
               newQuatreUplet(k0,
               (*itUplet)->getXIt(),
               itListeTournee2, val));
               }

               }
               }
               itListeTournee2 = (*itUplet)->getYIt();
               itListeTournee2++;
               itListeTournee = (*itUplet)->getXIt();
               itListeTournee++;
               if (((*itListeTournee)->getIndiceDemande() == i0)
               && ((*itListeTournee2)->getIndiceDemande()
               == i0)
               && ((*itListeTournee)->getStatus() == 0)
               && ((*itListeTournee2)->getStatus() == 1))
               {
               val = testInsertion(k0, numDemande,
               itListeTournee, itListeTournee2,
               noeudOrigine, noeudDestination, sortie);
               if (val > 0)
               {
               listeAAjouter.push_back(
               newQuatreUplet(k0, itListeTournee,
               itListeTournee2, val));
               }
               }
               }
               }
               // On efface les quatreUplet qui le doivent
               for (list<list<QuatreUplet *>::iterator>::iterator it =
               listeAEffacer.begin(); it != listeAEffacer.end();
               it++)
               {
               tabSelection[numDemande].getLibreXY().erase(*it);
               }
               for (list<QuatreUplet*>::iterator it =
               listeAAjouter.begin(); it != listeAAjouter.end();
               it++)
               {
               tabSelection[numDemande].insertListeTriee(*it);
               }
               if (!tabSelection[numDemande].kPresent(k0))
               {
               tabSelection[numDemande].decrementeNbCarLibre();
               }
               }
               }
               }
               */

              tabSelection.erase(tabSelection.begin(), tabSelection.end());
              bool boolVhLibre;
              double tempv;
              int k;

              for (int numDemande = 0; numDemande < nombreDemandes;
                  numDemande++)
                {
                  int NbCarLibreCourant = 0;

                  Selection tempSelection;
                  tempSelection.setN1(N1);
                  tempSelection.setN2(N2);
                  // Si la demande doit etre traitee
                  if (tabBoolJ[numDemande])
                    {
                      k = 0;
                      for (vector<Tournee>::iterator itTournees =
                          tabTournees.begin(); itTournees != tabTournees.end();
                          itTournees++)
                        {
                          boolVhLibre = false;
                          // We skip the last depot (no insertion possible at this location)
                          // x is the predecessor of y
                          for (list<Noeud *>::iterator itNoeudx =
                              (*itTournees).getItDebut();
                              itNoeudx != --(*itTournees).getItEnd();
                              itNoeudx++)
                            {
                              // we must have: x <<= y
                              for (list<Noeud *>::iterator itNoeudy = itNoeudx;
                                  itNoeudy != --(*itTournees).getItEnd();
                                  itNoeudy++)
                                {
                                  tempv =
                                      testInsertion(k, numDemande, itNoeudx,
                                          itNoeudy,
                                          tabDemandes[numDemande].getNoeudOrigine(),
                                          tabDemandes[numDemande].getNoeudDestination(),
                                          sortie);
                                  if (tempv > 0.0 - calcul.getEpsilon())
                                    {
                                      tempSelection.insertListeTriee(
                                          newQuatreUplet(k, itNoeudx, itNoeudy,
                                              tempv));

                                      // We add a NbCarLibre if it s the first time
                                      if (!boolVhLibre)
                                        {
                                          boolVhLibre = true;
                                          NbCarLibreCourant++;
                                        }
                                    }
                                }
                            }
                          k++;
                        }
                    }
                  tabSelection.push_back(tempSelection);
                  tabSelection[numDemande].setNbCarLibre(NbCarLibreCourant);

                }
            }

          if (!compteurJ)
            {
              if (!deuxiemePassage)
                {
                  // On reeinsere les demandes exclues
                  deuxiemePassage = true;
                  compteurJ = vectIndexInsertionFin.size();
                  for (vector<int>::iterator it = vectIndexInsertionFin.begin();
                      it != vectIndexInsertionFin.end(); it++)
                    {
                      tabBoolJ[*it] = true;
                      tabrejet[*it] = true;
                    }
                  // On vide le vecteur pour le deuxieme passage.
                  vectIndexInsertionFin.empty();
                }
            }

        }
    }
  end = clock();
  elapsed = ((double) end - start) / CLOCKS_PER_SEC;

  if (processSeul)
    {
      if (!reussi)
        {
          tabTempsExe.push_back(elapsed);
          tabTpsGlobal.push_back(calcul.getInfiniDouble());
          tabTpsAttente.push_back(calcul.getInfiniDouble());
          tabTpsDemande.push_back(calcul.getInfiniDouble());
          tabDistance.push_back(calcul.getInfiniDouble());
          tabPerformance.push_back(calcul.getInfiniDouble());
          tabEarlyArrival.push_back(calcul.getInfiniDouble());
          tabWaitPassenger.push_back(calcul.getInfiniDouble());
          tabRideExcess.push_back(calcul.getInfiniDouble());
          return 0.0;
        }
      else
        {
          // Formatage des resultats
          double sommeTpsGlobal = 0.0;
          double sommeTpsDemande = 0.0;
          double sommeTpsAttente = 0.0;
          double sommePerformance = 0.0;
          double sommeEarlyArrival = 0.0;
          double sommeWaitPassenger = 0.0;
          double sommeRideExcess = 0.0;
          EvalToutesTournees = 0.0;
          double distanceParcourue;
          double tpsGlobal;
          for (int i = 0; i < nombreVoitures; i++)
            {
              tpsGlobal = TpsGlobalTourneeSave(i);
              sommeTpsGlobal += tpsGlobal;
              sommeTpsDemande += TpsDemandesTourneeSave(i);
              sommeTpsAttente += TpsAttenteTournee(i, tpsGlobal);
              sommeEarlyArrival += EvalEarlyArrivalSave(i);
              sommeWaitPassenger += EvalWaitPassengerSave(i);
              sommeRideExcess += TpsDemandesTourneeExcessSave(i);

              EvalToutesTournees += EvalTourneeSave(i);
            }
          // On somme pour avoir la performance
          sommePerformance = EvalToutesTournees;

          // On entre les resultats de la replication ici
          tabTempsExe.push_back(elapsed);

          tabTpsGlobal.push_back(sommeTpsGlobal);
          tabTpsAttente.push_back(sommeTpsAttente);
          tabTpsDemande.push_back(sommeTpsDemande);

          tabEarlyArrival.push_back(sommeEarlyArrival);
          tabWaitPassenger.push_back(sommeWaitPassenger);
          tabRideExcess.push_back(sommeRideExcess);
          distanceParcourue = calculDistanceParcourue(-1);
          tabDistance.push_back(distanceParcourue);

          tabPerformance.push_back(sommePerformance);
          return 1.0;
        }
    }
  else
    return elapsed;
}

void
Metier::effaceUplet(int numDemande, list<QuatreUplet*>::iterator it)
{
  tabSelection[numDemande].effaceQuatreUplet(it);
}

/*
 * Fonction metant a jour les bornes sur les durees max de connexion
 */
void
Metier::majDelta(double lambdaDeDelta)
{
  double tempDISTLambda;
  for (int i = 0; i < nombreDemandes; i++)
    {
      tempDISTLambda =
          lambdaDeDelta
              * DIST[tabDemandes[i].getNoeudOrigine()->getIndiceDsDist()][tabDemandes[i].getNoeudDestination()->getIndiceDsDist()];
      if (tabDemandes[i].getDeltaSave() > tempDISTLambda)
        {
          tabDemandes[i].setDelta(tempDISTLambda);
        }
      else
        {
          tabDemandes[i].setDelta(tabDemandes[i].getDeltaSave());
        }
    }
}

/*
 * Fonction metant a valeur d origine les temps de connexion
 */
void
Metier::oldDelta()
{
  for (int i = 0; i < nombreDemandes; i++)
    {
      tabDemandes[i].setDelta(tabDemandes[i].getDeltaSave());
    }
}

/*
 * Fonction princpale pour le DARP classique en guise de main
 */
void
Metier::executionMetier()
{
  // insertionRatees donne le nombre d insertion qui n a pu se faire
  insertionRatees = 0.0;
  // On prepare les fichiers d instances et de solutions
  preparationFichiers();
  // On fixe le type de temps de service en secondeww
  parametres.setUniteTempsDeService('m');
  cout << " N1 N2 " << N1 << " " << N2 << " et Nb Replications : "
      << nombreReplication << " nombreInstancesTraitees " << nbInstances
      << endl;
  int numInstance = nbInstances - 1;
  // On alloue la place necessaire
  allocationReplication();
  cout << "La resolution de l instance pr" << numInstance + 1 << " debute."
      << endl;
  //Declaration des fichiers de sorties
  ofstream flotBasique(nomFichiersSortiesInstances[numInstance].data(),
      ios::out);
  // Init Stat globales sur l ensemble des iterations de chaque instance
  nbReplicationReussie = 0;
  sommeTpsExe = 0.0;
  premiereReplication = true;

  for (int i = 0; i < nombreReplication; ++i)
    {
      desalloueReplication();
      // Lecture du fichier d instance
      lireInstances(nomFichiersInstances[numInstance].data());
      // On calcule les distances entre chaque noeud

      calculDIST();
      // On integre les temps de services aux distances
      additionDistTpsService();
      additionDeltaTpsService();

      // On peut initialiser les tournees
      initTournees(parametres);
      // On initie l aide a la selection
      initSelection(flotBasique);
      // On lance la methode principale

      nbReplicationReussie += insertionCoeur(calcul, flotBasique, true);

      idInst = "D";
      idInst += manipulateurString.fromIntToString(nombreDemandes);
      idInst += "K";
      idInst += manipulateurString.fromIntToString(nombreVoitures);
      idInst += "R";
      idInst += manipulateurString.fromIntToString(nombreReplication);

      /*    fromTourneesToGraphVIZ(i);

       string nomTemp = "neato -Tjpg ";
       nomTemp += idInst;
       nomTemp += ".r";
       nomTemp += manipulateurString.fromIntToString(i);
       nomTemp += ".neato -o ";
       nomTemp += idInst;
       nomTemp += ".r";
       nomTemp += manipulateurString.fromIntToString(i);
       nomTemp += ".jpg";
       system(nomTemp.data());
       */

      sommeTpsExe += tabTempsExe[i];
      premiereReplication = false;
    }

  cout << "La resolution de l instance pr" << numInstance + 1
      << " est terminee." << endl;

  flotBasique
      << (100
          * (((nombreReplication * nombreDemandes) - insertionRatees)
              / (nombreReplication * nombreDemandes))) << endl
      << "% reussi de D." << endl;

  flotBasique << " nombreDemandes " << nombreDemandes << endl;

  flotBasique << " il y a eu " << insertionRatees << " insertion Ratees Cote."
      << endl;

  ecritureResultats(flotBasique);
  // On affiche la derniere tournee
  affichageTournees(flotBasique, -1);
  // Fermeture des fichiers de sorties
  flotBasique.close();
  cout << "Le programme se termine." << endl;
}

/*
 * Methode ecrivant la tournee dans un fichier texte
 */
void
Metier::fromTourneesToTxt(int numReplication)
{
  string nomFichier = "tournees.n.";
  nomFichier += manipulateurString.fromIntToString(numReplication);
  nomFichier += ".txt";

  ofstream sortie(nomFichier.data(), ios::out);

  afficherSeparationCOUT(sortie);
  list<Noeud *>::iterator itTourneePred;
  int i = 0;
  double miniDist = 0.0;

  sortie << "                 Affichage du tableau des tournees " << endl;
  for (vector<Tournee>::iterator itTournees = tabTournees.begin();
      itTournees != tabTournees.end(); itTournees++, i++)
    {
      afficherSeparationCOUT(sortie);
      sortie << "Tournne n " << i << endl;
      sortie << *itTournees << endl;
      sortie
          << "Affichage des DIST (avec tps de service) entre chaque noeud avec"
              " calcul si besoin pour les noeuds Relais : " << endl;
      for (list<Noeud *>::iterator itTourneeNoeud =
          (++tabTournees[i].getItDebut());
          itTourneeNoeud != (tabTournees[i].getItEnd()); itTourneeNoeud++)
        {
          itTourneePred = itTourneeNoeud;
          itTourneePred--;

          if (((*itTourneePred)->getIndiceDsDist() > -1)
              && ((*itTourneeNoeud)->getIndiceDsDist() > -1))
            miniDist =
                DIST[(*itTourneePred)->getIndiceDsDist()][(*itTourneeNoeud)->getIndiceDsDist()];
          else
            miniDist = calcul.calculDistanceAvecService(*itTourneePred,
                *itTourneeNoeud);

          sortie << miniDist << " ";

        }
      sortie << endl
          << "Affichage des DIST (sans tps de service) entre chaque noeud avec"
              " calcul si besoin pour les noeuds Relais : " << endl;
      for (list<Noeud *>::iterator itTourneeNoeud =
          (++tabTournees[i].getItDebut());
          itTourneeNoeud != (tabTournees[i].getItEnd()); itTourneeNoeud++)
        {
          itTourneePred = itTourneeNoeud;
          itTourneePred--;

          miniDist = calcul.calculDistance(*itTourneePred, *itTourneeNoeud);

          sortie << miniDist << " ";

        }
      sortie << endl;
    }

  afficherSeparationCOUT(sortie);
  sortie.close();
}

/*
 * Methode ecrivant la tournee dans un fichier texte
 */
void
Metier::fromTourneesToGraphVIZ(int numReplication)
{
  int i = 0;
  list<Noeud *>::iterator itTourneePred;
  vector<Tournee>::iterator itTournees;
  string nomFichier = idInst;
  double r, g, b;

  nomFichier += ".r";
  nomFichier += manipulateurString.fromIntToString(numReplication);
  nomFichier += ".neato";

  ofstream sortie(nomFichier.data(), ios::out);

  sortie << "digraph G {" << endl;
  for (itTournees = tabTournees.begin(); itTournees != tabTournees.end();
      itTournees++, i++)
    {
      r = (double) calcul.randInt(20);
      g = (double) calcul.randInt(20);
      b = (double) calcul.randInt(20);

      r /= 20.0;
      g /= 20.0;
      b /= 20.0;

      for (list<Noeud *>::iterator itTourneeNoeud =
          (++tabTournees[i].getItDebut());
          itTourneeNoeud != (tabTournees[i].getItEnd()); itTourneeNoeud++)
        {
          itTourneePred = itTourneeNoeud;
          itTourneePred--;
          // On prepare le nom du noeud
          string nomNoeudPred;
          if (((*itTourneePred)->getStatus() == 2))
            {
              nomNoeudPred = "DepotDk";
              nomNoeudPred += manipulateurString.fromIntToString(
                  (*itTourneePred)->getK());
            }
          else if (((*itTourneePred)->getStatus() == 3))
            {
              nomNoeudPred = "DepotAk";
              nomNoeudPred += manipulateurString.fromIntToString(
                  (*itTourneePred)->getK());
            }
          else
            {
              nomNoeudPred = "d";
              nomNoeudPred += manipulateurString.fromIntToString(
                  (*itTourneePred)->getIndiceDemande());
              nomNoeudPred += "s";
              nomNoeudPred += manipulateurString.fromIntToString(
                  (*itTourneePred)->getStatus());
            }

          sortie << nomNoeudPred << " [ label = \"" << nomNoeudPred << "\"";

          sortie << " pos = \"" << (*itTourneePred)->getX() << ","
              << (*itTourneePred)->getY() << "!\"" << " color = \"" << r << ","
              << g << "," << b << "\" fontsize = \"" << 8 << "\"";

          if (((*itTourneePred)->getStatus() == 2)
              || ((*itTourneePred)->getStatus() == 3))
            {
              sortie << " shape=polygon,sides=4,skew=.4 ";
            }
          else if (((*itTourneePred)->getStatus() == 4)
              || ((*itTourneePred)->getStatus() == 5))
            {
              sortie << " shape=polygon,sides=4,distortion=.7 ";
            }
          else if (((*itTourneePred)->getStatus() == 1))
            {
              sortie << " shape=invtriangle ";
            }
          else
            {
              sortie << " shape=triangle ";
            }

          sortie << " ]" << " ;" << endl;
        }
      itTourneePred = --(tabTournees[i].getItEnd());

      string nomNoeudPred;
      if (((*itTourneePred)->getStatus() == 2))
        {
          nomNoeudPred = "DepotDk";
          nomNoeudPred += manipulateurString.fromIntToString(
              (*itTourneePred)->getK());
        }
      else if (((*itTourneePred)->getStatus() == 3))
        {
          nomNoeudPred = "DepotAk";
          nomNoeudPred += manipulateurString.fromIntToString(
              (*itTourneePred)->getK());
        }
      else
        {
          nomNoeudPred = "d";
          nomNoeudPred += manipulateurString.fromIntToString(
              (*itTourneePred)->getIndiceDemande());
          nomNoeudPred += "s";
          nomNoeudPred += manipulateurString.fromIntToString(
              (*itTourneePred)->getStatus());
        }

      sortie << nomNoeudPred << " [ label = \"" << nomNoeudPred << "\"";

      sortie << " pos = \"" << (*itTourneePred)->getX() << ","
          << (*itTourneePred)->getY() << "!\"" << " color = \"" << r << "," << g
          << "," << b << "\" fontsize = \"" << 8 << "\"";

      if (((*itTourneePred)->getStatus() == 2)
          || ((*itTourneePred)->getStatus() == 3))
        {
          sortie << " shape=polygon,sides=4,skew=.4 ";
        }
      else if (((*itTourneePred)->getStatus() == 4)
          || ((*itTourneePred)->getStatus() == 5))
        {
          sortie << " shape=polygon,sides=4,distortion=.7 ";
        }
      else if (((*itTourneePred)->getStatus() == 1))
        {
          sortie << " shape=invtriangle ";
        }
      else
        {
          sortie << " shape=triangle ";
        }

      sortie << " ]" << " ;" << endl;
    }
  i = 0;
  for (itTournees = tabTournees.begin(); itTournees != tabTournees.end();
      itTournees++, i++)
    {
      r = (double) calcul.randInt(10);
      g = (double) calcul.randInt(10);
      b = (double) calcul.randInt(10);

      r /= 10.0;
      g /= 10.0;
      b /= 10.0;
      for (list<Noeud *>::iterator itTourneeNoeud =
          (++tabTournees[i].getItDebut());
          itTourneeNoeud != (tabTournees[i].getItEnd()); itTourneeNoeud++)
        {
          itTourneePred = itTourneeNoeud;
          itTourneePred--;
          // On prepare le nom du noeud
          string nomNoeudPred;
          string nomNoeud;

          if (((*itTourneePred)->getStatus() == 2))
            {
              nomNoeudPred = "DepotDk";
              nomNoeudPred += manipulateurString.fromIntToString(
                  (*itTourneePred)->getK());
            }
          else if (((*itTourneePred)->getStatus() == 3))
            {
              nomNoeudPred = "DepotAk";
              nomNoeudPred += manipulateurString.fromIntToString(
                  (*itTourneePred)->getK());
            }
          else
            {
              nomNoeudPred = "d";
              nomNoeudPred += manipulateurString.fromIntToString(
                  (*itTourneePred)->getIndiceDemande());
              nomNoeudPred += "s";
              nomNoeudPred += manipulateurString.fromIntToString(
                  (*itTourneePred)->getStatus());
            }

          if (((*itTourneeNoeud)->getStatus() == 2))
            {
              nomNoeud = "DepotDk";
              nomNoeud += manipulateurString.fromIntToString(
                  (*itTourneeNoeud)->getK());
            }
          else if (((*itTourneeNoeud)->getStatus() == 3))
            {
              nomNoeud = "DepotAk";
              nomNoeud += manipulateurString.fromIntToString(
                  (*itTourneeNoeud)->getK());
            }
          else
            {
              nomNoeud = "d";
              nomNoeud += manipulateurString.fromIntToString(
                  (*itTourneeNoeud)->getIndiceDemande());
              nomNoeud += "s";
              nomNoeud += manipulateurString.fromIntToString(
                  (*itTourneeNoeud)->getStatus());
            }

          sortie << nomNoeudPred << " -> " << nomNoeud << " [ label = \""
              << (*itTourneeNoeud)->getFMin() << "]" << setprecision(4)
              << (*itTourneeNoeud)->getSave() << "["
              << (*itTourneeNoeud)->getFMax() << "\"";

          sortie << " pos = \"" << (*itTourneeNoeud)->getX() << ","
              << (*itTourneeNoeud)->getY() << "!\"" << " color = \"" << r << ","
              << g << "," << b << "\" fontsize = \"" << 8 << "\"";

          if (i % 3 == 0)
            {
              sortie << " ]" << " ;" << endl;
            }
          else if (i % 3 == 1)
            {
              sortie << " style=\"dotted\" ]" << " ;" << endl;
            }
          else if (i % 3 == 2)
            {
              sortie << " style=\"bold\" ]" << " ;" << endl;
            }

        }
    }
  sortie << "}" << endl;

  sortie.close();
}

/*
 * Destructeur
 */
Metier::~Metier()
{

}

//
// Fonctions hors class
//

// affichage utilise par les algorithmes STL
template<typename T>
  void
  affichage(T instanceT)
  {
    cout << instanceT << endl;
  }

