/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AnimalFemelle.h"

namespace Etats{
    
AnimalFemelle::AnimalFemelle ()
{
    
}

AnimalFemelle::~AnimalFemelle ()
{
}
    
void AnimalFemelle::tuerAnimal ()
{
}
    
void AnimalFemelle::vendreAnimal ()
{
}
    
void AnimalFemelle::accoupler (bool isEnceinte, std::shared_ptr<Animal> male)
{
}
    
std::vector<std::shared_ptr<Animal>> AnimalFemelle::mettreBas (bool isEnceinte, std::array<int,2> dateAccouplement, int dureeGestation)
{
}

}