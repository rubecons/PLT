/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Race.h"
#include <cmath>

namespace Etats{

Race::Race(){}
    
Race::Race (std::string nom, int esperanceDeVieMale, int esperanceDeVieFemelle, int poidsMoyenAdulteMale, int poidsMoyenAdulteFemelle, int ageMoyenMaturiteMale, int ageMoyenMaturiteFemelle, double prixNourritureVeterinaireParKiloMale, double prixNourritureVeterinaireParKiloFemelle, int dureeGest, int dureeEntre2Gross, int nbEnfants, int poidsNaissance, double prixVenteKg, int nbGen)
{
    nomRace= nom;
    
    esperanceDeVie={esperanceDeVieMale, esperanceDeVieFemelle};
    poidsMoyenAdulte={poidsMoyenAdulteMale, poidsMoyenAdulteFemelle};
    ageMoyenMaturite={ageMoyenMaturiteMale, ageMoyenMaturiteFemelle};
    prixNourritureVeterinaireParKilo={prixNourritureVeterinaireParKiloMale, prixNourritureVeterinaireParKiloFemelle};
    dureeGestation=dureeGest;
    dureeEntre2Grossesses=dureeEntre2Gross;
    nbEnfantsPortee=nbEnfants;
    poidsMoyenNaissance=poidsNaissance;
    prixVenteKilo=prixVenteKg;
    nbGenerations=nbGen;
    
    idRace="";
    std::string::size_type n=0, nn=0;
 
 
    while(n<nomRace.length())
    {
        std::string::size_type m;
        std::string buff = nomRace.substr(n,3);
        if ((m = buff.find(" ")) != std::string::npos)
        buff = nomRace.substr(n,m);

        idRace+=buff;
        
        n = nomRace.find(" ", nn);
        if (n != std::string::npos)
        {
             n++;
        }
        nn=n;
    }
    for (auto & c: idRace) c = toupper(c);
    
    
    for(int i=1; i<=nbGenerations; i++)
    {
        nbAncetres+=std::exp2(i);
    }
}

Race::~Race ()
{
    
}
        
std::string Race::getIDRace ()
{
    return idRace;
}

std::string Race::getNomRace ()
{
    return nomRace;
}

int Race::getEsperanceDeVie (bool sexe) //sexe=true si c'est un male, false si c'est une femelle
{
    if (sexe==true)
    {return esperanceDeVie[0];}
    else
    {return esperanceDeVie[1];}
}

int Race::getPoidsMoyenAdulte (bool sexe)
{
    if (sexe==true)return poidsMoyenAdulte[0];
    else return poidsMoyenAdulte[1];
}

int Race::getAgeMoyenMaturite (bool sexe)
{
   if (sexe==true)return ageMoyenMaturite[0];
   else return ageMoyenMaturite[1];
}

double Race::getPrixNourritureVeterinaireParKilo (bool sexe)
{
    if (sexe==true)return prixNourritureVeterinaireParKilo[0];
    else return prixNourritureVeterinaireParKilo[1];
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

int Race::getPoidsMoyenNaissance ()
{
    return poidsMoyenNaissance;
}

double Race::getPrixVenteKilo ()
{
    return prixVenteKilo;
}

int Race::getNbGenerations ()
{
    return nbGenerations;
}

int Race::getNbAncetres ()
{
    return nbAncetres;
}

void Race::setNomRace (std::string &nom)
{
    nomRace=nom;
}

void Race::setEsperanceDeVie (bool sexe, int duree_esperancedevie)
{
    if (sexe==true) esperanceDeVie[0]=duree_esperancedevie;
    else esperanceDeVie[1]=duree_esperancedevie;
}

void Race::setPoidsMoyenAdulte (bool sexe, int poids)
{
    if (sexe==true) poidsMoyenAdulte[0]=poids;
    else poidsMoyenAdulte[1]=poids;
}

void Race::setAgeMoyenMaturite (bool sexe, int age)
{
    if (sexe==true) ageMoyenMaturite[0]=age;
    else ageMoyenMaturite[1]=age;
}

void Race::setPrixNourritureVeterinaireParKilo (bool sexe, double prix)
{
    if (sexe==true) prixNourritureVeterinaireParKilo[0]=prix;
    else prixNourritureVeterinaireParKilo[1]=prix;
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

void Race::setPoidsMoyenNaissance (int poids)
{
    poidsMoyenNaissance=poids;
}

void Race::setPrixVenteKilo (double prix)
{
    prixVenteKilo=prix;
}

void Race::setNbGenerations (int nbGen)
{
    nbGenerations=nbGen;
}

}


