/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AnimalFemelle.h"
#include "AnimalMale.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

namespace Etats{
    
AnimalFemelle::AnimalFemelle (std::shared_ptr<Elevage> elvaj, int ms, int an, std::vector<std::string> ancet) : Animal(elvaj, false, ms, an, ancet)
{
    dateDerniereMiseBas[0]=ms;//-(IDelevage->getRace()->getDureeEntre2Grossesses());
    dateDerniereMiseBas[1]=an-(getIDElevage()->getRace()->getDureeEntre2Grossesses()/12)-1;
}
/*
AnimalFemelle::~AnimalFemelle ()
{
}
    
void AnimalFemelle::tuerAnimal ()
{
}
    
void AnimalFemelle::vendreAnimal ()
{
}
    //*/
std::array<int,2> AnimalFemelle::getDateDerniereMiseBas ()
{
    return dateDerniereMiseBas;
}

bool AnimalFemelle::accoupler (AnimalMale* male)
{
    int dureeDepuisDerniereGrossesse=((getIDElevage()->getTemps()->getMois()-dateDerniereMiseBas[0])+(12*(getIDElevage()->getTemps()->getAnnee()-dateDerniereMiseBas[1])));
    int ageFemelle=(getIDElevage()->getTemps()->getMois()-getDateNaissance()[0])+(12*(getIDElevage()->getTemps()->getAnnee()-getDateNaissance()[1]));
    bool compatible=true;
    
    auto ancFem=getAncetres();
    auto ancMal= male->getAncetres();
    std::string idMale=male->getIDAnimal();
    std::string idFemelle=getIDAnimal();
    
    if(std::find(std::begin(ancFem), std::end(ancFem), idMale) != std::end(ancFem))
    {
        compatible=false;
    }
    if(std::find(std::begin(ancMal), std::end(ancMal), idFemelle) != std::end(ancMal))
    {
        compatible=false;
    }
    for(auto & a : ancMal)
    {
        if(std::find(std::begin(ancFem), std::end(ancFem), a)!=std::end(ancFem))
        {
            compatible=false;
            break;
        }
    }
    
    if(male->getSexe() && isEnceinte==false && dureeDepuisDerniereGrossesse>getIDElevage()->getRace()->getDureeEntre2Grossesses() && compatible && ageFemelle>getIDElevage()->getRace()->getAgeMoyenMaturite(getSexe()))
    {
        isEnceinte=true;
        dateAccouplement[0]=getIDElevage()->getTemps()->getMois();
        dateAccouplement[1]=getIDElevage()->getTemps()->getAnnee();
        geniteur=std::shared_ptr<AnimalMale>(male);
        
        dateDerniereMiseBas[1]=getIDElevage()->getTemps()->getAnnee()+(getIDElevage()->getRace()->getDureeGestation()/12);
        if(((getIDElevage()->getTemps()->getMois()+(getIDElevage()->getRace()->getDureeGestation()%12))%12)<(getIDElevage()->getTemps()->getMois()))
        {
            dateDerniereMiseBas[1]=dateDerniereMiseBas[1]+1;
            dateDerniereMiseBas[0]=(getIDElevage()->getTemps()->getMois()+(getIDElevage()->getRace()->getDureeGestation()%12))%12;
        }
        std::cout<<"accouplement en cours"<<std::endl;
        return true;        
    }
    else
    {
        //std::cout<<"accouplement impossible, désolé"<<std::endl;
        return false;
    }
}
    
bool AnimalFemelle::mettreBas ()//bool isEnceinte, std::array<int,2> dateAccouplement, int dureeGestation)
{
    if (isEnceinte && dateDerniereMiseBas[1]==getIDElevage()->getTemps()->getAnnee() && dateDerniereMiseBas[0]==getIDElevage()->getTemps()->getMois())
    {
        //bool sexe;
        isEnceinte=false;
        
        std::vector<std::string> ancet;
            ancet.push_back(geniteur->getIDAnimal());
            ancet.push_back(this->getIDAnimal());

            for(int i=0;i<(getIDElevage()->getRace()->getNbGenerations())-1;i++)// P= {p, m | pp, mp, pm, mm | ppp, mpp, pmp, mmp, ppm, mpm, pmm, mmm}
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
                    ancet.push_back(geniteur->getAncetres()[j]);
                }
        //*
                for(int j=valInit ; j<std::exp2(i+1)+valInit ; j++)
                {
                    ancet.push_back(this->getAncetres()[j]);
                }//*/
            }
        
        for(int i=0; i<getIDElevage()->getRace()->getNbEnfantsPortee(); i++)
        {
            bool sexeRandom= std::rand()%2;
            if(sexeRandom)
            {//il faut enlever les commentaires en dessous
                std::shared_ptr<Animal> bebe= /*(std::shared_ptr<Animal>)*/ std::make_shared<AnimalMale>(getIDElevage(), getIDElevage()->getTemps()->getMois(), getIDElevage()->getTemps()->getAnnee(), ancet);
                getIDElevage()->rajouterAnimalListe(bebe);
            }
            else
            {
                std::shared_ptr<Animal> bebe= /*(std::shared_ptr<Animal>)*/ std::make_shared<AnimalFemelle>(getIDElevage(), getIDElevage()->getTemps()->getMois(), getIDElevage()->getTemps()->getAnnee(), ancet);
                getIDElevage()->rajouterAnimalListe(bebe);
            }
            
            
        }
        return true;
    }
    else
    {
        return false;
    }
}

}