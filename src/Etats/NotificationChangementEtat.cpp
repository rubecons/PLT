/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "NotificationChangementEtat.h"
#include <iostream>

namespace Etats
{
NotificationChangementEtat::NotificationChangementEtat ()
{
}

NotificationChangementEtat::NotificationChangementEtat (ChangementEtatsID etatNotif, std::shared_ptr<Elevage> ptrElvaj, Rendu::FenetrePrincipale *fenPrincipale)
{
    id=etatNotif;
    ptrElevage=ptrElvaj;
    fenetrePrincipale=fenPrincipale;
}

NotificationChangementEtat::~NotificationChangementEtat (){}

void NotificationChangementEtat::actualiserChangementRendu (std::shared_ptr<Ferme> frm)
{std::cout<< "test : execution de la notif"<<std::endl;
    if(id==ChangementEtatsID::TOUT_CHANGE)
    {
    }
    if(id==ChangementEtatsID::TOUT_CHANGE || id==ChangementEtatsID::LISTE_ELEVAGE_CHANGE)//servir à actualiser la liste des élevages, ne se produit que quand on créée un élevage (ou qu'on le désactive)
    {
        std::cout<< "test : bonne section"<<std::endl;
        std::cout<< ptrElevage->getNomElevage() <<std::endl;
        fenetrePrincipale-> addItemListeElevage(ptrElevage->getNomElevage());
    }
    if(id==ChangementEtatsID::TOUT_CHANGE || id==ChangementEtatsID::BUDGET_TEMPS_CHANGE || id==ChangementEtatsID::ELEVAGE_CHANGE)//sert à actualiser le budget, la date (ne se produit quand il y a un modification du budget, ou un mois suivant, ou quand on achete ou vend une bete)
    {
        const std::string date=frm->getTemps()->getNomMois()[frm->getTemps()->getMois()].append(" ").append(std::to_string(frm->getTemps()->getAnnee()));
        const std::string budget=std::string("Budget = ").append(std::to_string(frm->getBudget())).append(" €");

        fenetrePrincipale->setTexteStatusBar2(date);//->setText(date.c_str());
        fenetrePrincipale->setTexteStatusBar3(budget);//->setText(budget.c_str());
    }
    if(id==ChangementEtatsID::TOUT_CHANGE || id==ChangementEtatsID::ELEVAGE_CHANGE)//sert a actualiser la liste d'élevage(se produit quand il y a une modification des betes d'un élévage)
    {
    }
    
    //QTableView *item= new QTableView;//(stackedLayout);//, this, QListWidgetItem::Type);
    //fenetrePrincipale->addWidgetStackedLayout(item);
}

std::shared_ptr<Elevage> NotificationChangementEtat::getPtrElevage ()
{
    return ptrElevage;
}

int NotificationChangementEtat::getIDNotification ()
{
    return id;
}

}