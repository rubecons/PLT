/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AnimalMale.h"

namespace Etats{
    
    AnimalMale::AnimalMale ()
    {
        
    }//*/
    
    AnimalMale::AnimalMale (std::shared_ptr<Elevage> elvaj, bool sx, int ms, int an, std::vector<std::string> ancet) : Animal(elvaj, sx, ms, an, ancet)
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
    
    bool AnimalMale::accoupler (std::shared_ptr<Animal> femelle)
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