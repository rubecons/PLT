/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Moteur.h"
#include <QLabel>

namespace moteur
{
    
Moteur::Moteur ()
{
    
}

void Moteur::ajouterCommande (std::shared_ptr<Commande> com)
{
    corentinFDP.lock();
    mesCommandes.push_back(com);
    corentinFDP.unlock();
}

void Moteur::execCommande (std::shared_ptr<Etats::Ferme> frm, std::shared_ptr<Etats::Temps> tps, Rendu::FenetrePrincipale *fenetrePpale)
{
    while(1)
    {
        while(mesCommandes.empty()==false)
        {
            corentinFDP.lock();
            mesCommandes.back()->effectuerCommande();
            mesCommandes.pop_back();
            corentinFDP.unlock();
        }
    }
    
    
    //const std::string date=tps->getNomMois()[tps->getMois()].append(" ").append(std::to_string(tps->getAnnee()));
    //const std::string budget=std::string("Budget = ").append(std::to_string(frm->getBudget())).append(" €");
    
    //fenetrePpale->setTexteStatusBar2(date);//->setText(date.c_str());
    //fenetrePpale->setTexteStatusBar3(budget);//->setText(budget.c_str());
}
            
}