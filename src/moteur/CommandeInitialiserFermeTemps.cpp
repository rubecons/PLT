/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CommandeInitialiserFermeTemps.h"
#include <iostream>

namespace moteur
{
CommandeInitialiserFermeTemps::CommandeInitialiserFermeTemps ()
{
    
}

CommandeInitialiserFermeTemps::CommandeInitialiserFermeTemps (std::shared_ptr<Etats::Ferme> frm, std::shared_ptr<Etats::Temps> tps, double bud, double empr, int ms, int an)
{
    ferme=frm;
    temps=tps;
    budget=bud;
    emprunts=empr;
    mois=ms;
    annee=an;
}

CommandeInitialiserFermeTemps::~CommandeInitialiserFermeTemps ()
{
    
}

void CommandeInitialiserFermeTemps::effectuerCommande ()
{
/*    std::cout<< "test entré dans l'executionn de la commande"<<std::endl;
    ferme=std::make_shared<Etats::Ferme>(budget, emprunts);std::cout<< "test création ferme"<<std::endl;
    temps=std::make_shared<Etats::Temps>(mois, annee);std::cout<< "test création temps"<<std::endl;
std::cout<< "date : " << temps->getMois()+1 << "/"<<temps->getAnnee() <<" | ferme : Budget: "<< ferme->getBudget() <<" € | Emprunts:"<< ferme->getEmprunt()<<" €\n\n"<<std::endl;
*/
    ferme->setBudget(budget);
    ferme->emprunter(emprunts);
    temps->setAnnee(annee);
    temps->setMois(mois);
}

}
