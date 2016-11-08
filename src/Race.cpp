/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "./Etats/Race.h"

Race::Race ()
{
    
}

Race::~Race ()
{
    
}
        
int Race::getIDRace ()
{
    return idRace;
}

QString Race::getNomRace ()
{
    return nomRace;
}

int Race::getEsperanceDeVie (bool sexe) //sexe=true si c'est un male, false si c'est une femelle
{
//    if (sexe==true)return *esperanceDeVie;
//    else return *(esperanceDeVie+1);
}

int Race::getPoidsMoyenAdulte (bool sexe)
{
    //if (sexe==true)return *poidsMoyenAdulte;
    //else return *(poidsMoyenAdulte+1);
}

int Race::getAgeMoyenMaturite (bool sexe)
{
   // if (sexe==true)return *ageMoyenMaturite;
   // else return *(ageMoyenMaturite+1);
}

double Race::getPrixNourritureVeterinaire (bool sexe)
{
 //   if (sexe==true)return *prixNourritureVeterinaire;
 //   else return *(prixNourritureVeterinaire+1);
}

int Race::getDureeGestation ()
{
    return dureeGestation;
}

int Race::getDureeEntre2Grossesses()
{
    return dureeEntre2Grossesses;
}

int Race::getNbEnfantsPortee ()
{
    return nbEnfantsPortee;
}

double Race::getPrixVenteKilo ()
{
    return prixVenteKilo;
}

/*double Race::getGainVente_adulte ()
{
    return ;
}//*/

int Race::getNbGenerations ()
{
    return nbGenerations;
}

int Race::getNbAncetres ()
{
    return nbAncetres;
}

void Race::setNomRace (QString &nom)
{
    nomRace=nom;
}

void Race::setEsperanceDeVie (bool sexe, int duree_esperancedevie)
{
//    if (sexe==true) *esperanceDeVie=duree_esperancedevie;
//    else *(esperanceDeVie+1)=duree_esperancedevie;
}

void Race::setPoidsMoyenAdulte (bool sexe, int poids)
{
  //  if (sexe==true) *poidsMoyenAdulte=poids;
 //   else *(poidsMoyenAdulte+1)=poids;
}

void Race::setAgeMoyenMaturite (bool sexe, int age)
{
 //   if (sexe==true) *ageMoyenMaturite=age;
 //   else *(ageMoyenMaturite+1)=age;
}

void Race::setPrixNourritureVeterinaire (bool sexe, double prix)
{
  //  if (sexe==true) *prixNourritureVeterinaire=prix;
  //  else *(prixNourritureVeterinaire+1)=prix;
}

void Race::setDureeGestation (int duree)
{
    dureeGestation=duree;
}

void Race::setDureeEntre2Grossesses(int duree)
{
    dureeEntre2Grossesses=duree;
}

void Race::setNbEnfantsPortee (int nombre)
{
    nbEnfantsPortee=nombre;
}

void Race::setPrixVenteKilo (double prix)
{
    prixVenteKilo=prix;
}

/*void Race::setGainVente_adulte (double prix)
{
    
}//*/

void Race::setNbGenerations (int nbGen)
{
    nbGenerations=nbGen;
}




