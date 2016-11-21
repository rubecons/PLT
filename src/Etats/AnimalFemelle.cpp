/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AnimalFemelle.h"
#include "AnimalMale.h"
#include <cstdlib>
#include <algorithm>
//#include

namespace Etats{
    
AnimalFemelle::AnimalFemelle (std::shared_ptr<Elevage> elvaj, bool sx, int ms, int an, std::vector<std::string> ancet) : Animal(elvaj, sx, ms, an, ancet)
{
    
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
bool AnimalFemelle::accoupler (AnimalMale* male)
{
    int dureeDepuisDerniereGrossesse=((getIDElevage()->getTemps()->getMois()-dateDerniereMiseBas[0])+(12*(getIDElevage()->getTemps()->getAnnee()-dateDerniereMiseBas[1])));
    
    bool compatible=true;
    
    if(std::find(std::begin(this->getAncetres()), std::end(this->getAncetres()), male->getIDAnimal())!=std::end(this->getAncetres()))
        {
            compatible=false;
            //break;
        }
    if(std::find(std::begin(male->getAncetres()), std::end(male->getAncetres()), this->getIDAnimal())!=std::end(male->getAncetres()))
        {
            compatible=false;
            //break;
        }
    for(auto & a : male->getAncetres())
    {
        if(std::find(std::begin(this->getAncetres()), std::end(this->getAncetres()), a)!=std::end(this->getAncetres()))
        {
            compatible=false;
            break;
  
        }
    }
    
    if(male->getSexe() && isEnceinte==false && dureeDepuisDerniereGrossesse>getIDElevage()->getRace()->getDureeEntre2Grossesses() && compatible)
    {
        isEnceinte=true;
        dateAccouplement[0]=getIDElevage()->getTemps()->getMois();
        dateAccouplement[1]=getIDElevage()->getTemps()->getAnnee();
        geniteur=std::shared_ptr<AnimalMale>(male);
        
        dateDerniereMiseBas[1]=getIDElevage()->getTemps()->getAnnee()+(getIDElevage()->getRace()->getDureeGestation()/12);
        if((getIDElevage()->getTemps()->getMois()+(getIDElevage()->getRace()->getDureeGestation()%12))<(getIDElevage()->getTemps()->getMois()))
        {
            dateDerniereMiseBas[1]=dateDerniereMiseBas[1]+1;
            dateDerniereMiseBas[0]=(getIDElevage()->getTemps()->getMois()+(getIDElevage()->getRace()->getDureeGestation()%12));
        }
        return true;        
    }
    else
    {
        return false;
    }
}
    
bool AnimalFemelle::mettreBas (bool isEnceinte, std::array<int,2> dateAccouplement, int dureeGestation)
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
                //std::shared_ptr<Animal> bebe= (std::shared_ptr<Animal>) std::make_shared<AnimalMale>(getIDElevage(), sexeRandom, getIDElevage()->getTemps()->getMois(), getIDElevage()->getTemps()->getAnnee(), ancet);
                //getIDElevage()->rajouterAnimalListe(bebe);
            }
            else
            {
                //std::shared_ptr<Animal> bebe= (std::shared_ptr<Animal>) std::make_shared<AnimalFemelle>(getIDElevage(), sexeRandom, getIDElevage()->getTemps()->getMois(), getIDElevage()->getTemps()->getAnnee(), ancet);
                //getIDElevage()->rajouterAnimalListe(bebe);
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