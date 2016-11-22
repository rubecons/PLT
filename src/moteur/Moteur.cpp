/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Moteur.h"

namespace moteur
{
    
Moteur::Moteur ()
{
    
}

void Moteur::ajouterCommande (std::shared_ptr<Commande> com)
{
    mesCommandes.push_back(com);
}

void Moteur::execCommande ( )
{
    while(mesCommandes.empty()==false)
    {
        mesCommandes.back()->effectuerCommande();
        mesCommandes.pop_back();
    }
}
            
}