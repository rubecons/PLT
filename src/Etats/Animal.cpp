/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Animal.h"
//#include <string>
namespace Etats{
Animal::Animal (std::shared_ptr<Elevage> elvaj, bool sx, int ms, int an, std::vector<std::string> ancet)
{
    std::string se;
    IDelevage=elvaj;
    IDelevage->incrementNbAnimaux++;
    sexe=sx;
    if(sexe==true) {se="M";}
    else {se="F";}
    IDanimal=IDelevage->getIdElevage()+"-"+se+std::to_string(IDelevage->incrementNbAnimaux);
    dateNaissance={ms,an};
    
    ancetres=ancet;
}
/*
    IDanimal;
    IDelevage;
    sexe;
    dateNaissance;
    ancetres;*/

Animal::Animal ()
{
    
}

Animal::~Animal ()
{
    
}//*/

void Animal::tuerAnimal ()
{
    //~Animal();
}

void Animal::vendreAnimal ()
{
    double poids;
    if(((IDelevage->getTemps()->getMois()-dateNaissance[1])+(12*(IDelevage->getTemps()->getAnnee()-dateNaissance[2])))<IDelevage->getRace()->getAgeMoyenMaturite(sexe))
    {
        poids=(((IDelevage->getTemps()->getMois()-dateNaissance[1])+(12*(IDelevage->getTemps()->getAnnee()-dateNaissance[2])))*(double)((IDelevage->getRace()->getPoidsMoyenAdulte(sexe)-IDelevage->getRace()->getPoidsMoyenNaissance())/IDelevage->getRace()->getAgeMoyenMaturite(sexe)))+(IDelevage->getRace()->getPoidsMoyenNaissance());
    }
    else
    {
        poids=IDelevage->getRace()->getPoidsMoyenAdulte(sexe);
    }
    double gain =poids*(IDelevage->getRace()->getPrixVenteKilo());
    
    IDelevage->getFerme()->plusBudget(gain);
}

std::string Animal::getIDAnimal ()
{
    return IDanimal;
}

std::shared_ptr<Elevage> Animal::getIDElevage ()
{
    return IDelevage;
}

void Animal::setIDElevage (std::shared_ptr<Elevage> id)
{
    IDelevage=id;
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

/*int Animal::getPoids ()
{
    
}

void Animal::setPoids (int poids)
{
    
}*/

std::vector<std::string> Animal::getAncetres ()
{
    
}

void Animal::setAncetres (std::vector<std::string> ancetresPere, std::vector<std::string> ancetresMere)
{
    
}

}