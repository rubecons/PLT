/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CommandeNouvelleBete.h"
#include "Etats/AnimalFemelle.h"
#include "Etats/Animal.h"
#include "Etats/AnimalMale.h"

namespace moteur
{
CommandeNouvelleBete::CommandeNouvelleBete ()
{
    
}

CommandeNouvelleBete::CommandeNouvelleBete (std::shared_ptr<Etats::Ferme> frm, std::shared_ptr<Etats::Elevage> elvaj, bool sx, int ms, int an, std::vector<std::string> anc)
{
    ferme=frm;
    elevage=elvaj;
    sexe=sx;
    mois=ms;
    annee=an;
    ancetres=anc;
}

CommandeNouvelleBete::~CommandeNouvelleBete ()
{
    
}

void CommandeNouvelleBete::effectuerCommande ()
{
    std::shared_ptr<Etats::Animal> nouvelleBete;
            
    if(sexe)
    {
        nouvelleBete =  std::make_shared<Etats::AnimalMale>(elevage, mois, annee, ancetres);
    }
    else
    {
        nouvelleBete =  std::make_shared<Etats::AnimalFemelle>(elevage, mois, annee, ancetres);
    }
    elevage->rajouterAnimalListe(nouvelleBete);
}

}