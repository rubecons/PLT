/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PasserMoisSuivant.h"

namespace moteur
{
PasserMoisSuivant::PasserMoisSuivant ()
{
    
}

PasserMoisSuivant::PasserMoisSuivant (std::shared_ptr<Etats::Temps> temps, std::shared_ptr<Etats::Ferme> ferme)
{
    this->temps=temps;
    this->ferme=ferme;
}

PasserMoisSuivant::~PasserMoisSuivant ()
{
    
}

void PasserMoisSuivant::effectuerCommande ()
{
    temps->upMois();
}

}