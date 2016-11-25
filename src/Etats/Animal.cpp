/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Animal.h"
#include "EtatAnimal.h"
#include <cmath>


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
    etat = EtatAnimal::VIVANT;
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
    //this->~Animal();
}

void Animal::vendreAnimal ()
{
    double poids;
    if(((IDelevage->getTemps()->getMois()-dateNaissance[0])+(12*(IDelevage->getTemps()->getAnnee()-dateNaissance[1])))<IDelevage->getRace()->getAgeMoyenMaturite(sexe))
    {
        poids=(((IDelevage->getTemps()->getMois()-dateNaissance[0])+(12*(IDelevage->getTemps()->getAnnee()-dateNaissance[1])))*(double)((IDelevage->getRace()->getPoidsMoyenAdulte(sexe)-IDelevage->getRace()->getPoidsMoyenNaissance())/IDelevage->getRace()->getAgeMoyenMaturite(sexe)))+(IDelevage->getRace()->getPoidsMoyenNaissance());
    }
    else
    {
        poids=IDelevage->getRace()->getPoidsMoyenAdulte(sexe);
    }
    double gain =poids*(IDelevage->getRace()->getPrixVenteKilo());
    
    IDelevage->getFerme()->plusBudget(gain);//*/
    //~Animal();
}

std::string Animal::getIDAnimal ()
{
    return IDanimal;
}

EtatAnimal Animal::getEtat ()
{
    return etat;
}

void Animal::setEtat (EtatAnimal state)
{
    etat=state;
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
    return sexe;
}

void Animal::setSexe (bool sxe)
{
    sexe=sxe;
}

std::array<int, 2> Animal::getDateNaissance ()
{
    return dateNaissance;
}

void Animal::setDateNaissance (int anneeNaissance, int moisNaissance)
{
    dateNaissance={moisNaissance, anneeNaissance};
}

/*int Animal::getPoids ()
{
    
}

void Animal::setPoids (int poids)
{
    
}*/

std::vector<std::string> Animal::getAncetres ()
{
    return ancetres;
}

void Animal::setAncetres (std::shared_ptr<Animal> ancetresPere, std::shared_ptr<Animal> ancetresMere)
{
    ancetres.push_back(ancetresPere->getIDAnimal());
    ancetres.push_back(ancetresMere->getIDAnimal());

    for(int i=0;i<(IDelevage->getRace()->getNbGenerations())-1;i++)// P= {p, m | pp, mp, pm, mm | ppp, mpp, pmp, mmp, ppm, mpm, pmm, mmm}
    {
        int valInit=0;
        if(i!=0)
        {
            for(int l=1;l<i+1;l++)
            {
                valInit+=std::exp2(l);
            }
        }
        //std::cout<< "valInit= "<<valInit <<std::endl;
        for(int j=valInit ; j<std::exp2(i+1)+valInit ; j++)
        {
            ancetres.push_back(ancetresPere->ancetres[j]);
        }
        //*
        for(int j=valInit ; j<std::exp2(i+1)+valInit ; j++)
        {
            ancetres.push_back(ancetresMere->ancetres[j]);
        }//*/
    }
}

}