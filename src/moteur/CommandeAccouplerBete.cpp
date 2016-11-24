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
{/*
    if(vache1->getSexe())
    {
        AnimalMale* pointeurAnimalMale=static_cast<AnimalMale*>(vache1.get());
        pointeurAnimalMale->accoupler(dynamic_cast<AnimalFemelle*>(vache2).get());
    }//*/
}

}