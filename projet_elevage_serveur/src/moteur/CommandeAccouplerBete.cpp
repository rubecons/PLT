/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CommandeAccouplerBete.h"
#include "Etats/AnimalFemelle.h"
#include "Etats/AnimalMale.h"

namespace moteur
{
CommandeAccouplerBete::CommandeAccouplerBete ()
{
    
}

CommandeAccouplerBete::CommandeAccouplerBete (std::shared_ptr<Etats::Animal> mal, std::shared_ptr<Etats::Animal> femel)
{
    male=mal;
    femelle=femel;
}

CommandeAccouplerBete::~CommandeAccouplerBete ()
{
    
}

void CommandeAccouplerBete::effectuerCommande ()
{
    if(male->getSexe() && femelle->getSexe()==false)
    {
        Etats::AnimalMale* pointeurAnimalMale=static_cast<Etats::AnimalMale*>(male.get());
        Etats::AnimalFemelle* pointeurAnimalFemelle=static_cast<Etats::AnimalFemelle*>(femelle.get());
        pointeurAnimalFemelle->accoupler(pointeurAnimalMale);
    }
    else if(femelle->getSexe() && male->getSexe()==false)
    {
        Etats::AnimalMale* pointeurAnimalMale=static_cast<Etats::AnimalMale*>(femelle.get());
        Etats::AnimalFemelle* pointeurAnimalFemelle=static_cast<Etats::AnimalFemelle*>(male.get());
        pointeurAnimalFemelle->accoupler(pointeurAnimalMale);
    }//*/
}

}