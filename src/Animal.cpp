/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "./Etats/Animal.h"

/*Animal () : 
Animal ()
~Animal () {
    
}//*/

void Animal::tuerAnimal ()
{
 //   delete
}

void Animal::vendreAnimal ()
{
    //int gain =poids*(IDelevage->raceElevage->prixVenteKilo);
}

int Animal::getIDAnimal ()
{
    return IDanimal;
}

int Animal::getIDElevage ()
{
    return IDelevage;
}

void Animal::setIDElevage (int ID)
{
    IDelevage=ID;
}
/*/
string Animal::getNomAnimal ()
{
    
}

void Animal::setNomAnimal (string nom)
{
    
}//*/

bool Animal::getSexe ()
{
    
}

void Animal::setSexe (bool sexe)
{
    
}

std::array<int, 2> Animal::getDateNaissance ()
{
    
}

void Animal::setDateNaissance (int anneeNaissance, int moisNaissance)
{
    
}

int Animal::getPoids ()
{
    
}

void Animal::setPoids (int poids)
{
    
}

std::vector<int> getAncetres ()
{
    
}

void Animal::setAncetres (std::shared_ptr<std::vector<int>> ancetresPere, std::shared_ptr<std::vector<int>> ancetresMere)
{
    
}