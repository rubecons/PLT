/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AnimalMale.h"
#include "AnimalFemelle.h"

namespace Etats{
    
    AnimalMale::AnimalMale ()
    {
        
    }//*/
    
    AnimalMale::AnimalMale (std::shared_ptr<Elevage> elvaj, int ms, int an, std::vector<std::string> ancet) : Animal(elvaj, true, ms, an, ancet)
    {
        
    }
    /*
    AnimalMale::~AnimalMale ()
    {
        
    }
    
    void AnimalMale::tuerAnimalMale ()
    {
        
    }
    
    void AnimalMale::vendreAnimal ()
    {
        
    }//*/
    
    bool AnimalMale::accoupler (AnimalFemelle* femelle)
    {
        if(femelle->getSexe()==false)
        {
            if(femelle->accoupler(this))
                return true;
            else return false;
        }
        else return false;
    }
    
}