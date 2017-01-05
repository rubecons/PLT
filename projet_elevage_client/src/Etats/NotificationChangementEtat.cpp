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

NotificationChangementEtat::NotificationChangementEtat (ChangementEtatsID etatNotif, std::shared_ptr<Ferme> frm, Rendu::FenetrePrincipale *fenPrincipale)
{
    id=etatNotif;
    ferme=frm;
    fenetrePrincipale=fenPrincipale;
}

NotificationChangementEtat::~NotificationChangementEtat (){}

void NotificationChangementEtat::actualiserChangementRendu ()
{
    std::cout<< "test : execution de la notif"<<std::endl;
    if(id==ChangementEtatsID::TOUT_CHANGE)
    {
    }
    if(id==ChangementEtatsID::TOUT_CHANGE || id==ChangementEtatsID::LISTE_ELEVAGE_CHANGE)//servir à actualiser la liste des élevages, ne se produit que quand on créée un élevage (ou qu'on le désactive)
    {
        std::cout<< "test : bonne section"<<std::endl;
        std::cout<< "test : encore"<<std::endl;
        //std::cout<< fenetrePrincipale->listeElevage->size().isEmpty() <<std::endl;
        //if(fenetrePrincipale->listeElevage->size().isEmpty()==false)
        //{
            //fenetrePrincipale->clearListeElevage();
            std::cout<< "test : liste effacée"<<std::endl;
            for(auto& e : ferme->getElevages())
            {
                std::cout<< e->getNomElevage() <<"   "<<e->getRace()->getNomRace() <<std::endl;
            }std::cout<< "test : rajout élevages"<<std::endl;
            fenetrePrincipale-> addItemListeElevage();
//            for(auto& e : ferme->getElevages())
//            {
//                std::cout<< e->getNomElevage() <<std::endl;
//                //std::string nom = e->getNomElevage();
//                //fenetrePrincipale-> addItemListeElevage(nom);
//                fenetrePrincipale-> addItemListeElevage(e);
//            }
        //}
            std::cout<< "test : liste actualisée"<<std::endl;
    }std::cout<< "test : liste actualisée"<<std::endl;
    if(id==ChangementEtatsID::TOUT_CHANGE || id==ChangementEtatsID::BUDGET_TEMPS_CHANGE || id==ChangementEtatsID::ELEVAGE_CHANGE)//sert à actualiser le budget, la date (ne se produit quand il y a un modification du budget, ou un mois suivant, ou quand on achete ou vend une bete)
    {
        std::cout<< "test : changement budget/temps"<<std::endl;
        const std::string date=ferme->getTemps()->getNomMois()[ferme->getTemps()->getMois()].append(" ").append(std::to_string(ferme->getTemps()->getAnnee()));
        const std::string budget=std::string("Budget = ").append(std::to_string(ferme->getBudget())).append(" €");
std::cout<< "test : intermédiaire budget/temps"<<std::endl;
        fenetrePrincipale->setTexteStatusBar2(date);//->setText(date.c_str());
        fenetrePrincipale->setTexteStatusBar3(budget);//->setText(budget.c_str());
        
        std::cout<< "test : budget/temps actualisé"<<std::endl;
    }
    std::cout<< "test : rien"<<std::endl;
    if(id==ChangementEtatsID::TOUT_CHANGE || id==ChangementEtatsID::ELEVAGE_CHANGE)//sert a actualiser la liste d'élevage(se produit quand il y a une modification des betes d'un élévage)
    {
        
    }
    std::cout<<" fin actualisationrendu"<<std::endl;
    //QTableView *item= new QTableView;//(stackedLayout);//, this, QListWidgetItem::Type);
    //fenetrePrincipale->addWidgetStackedLayout(item);
}

//std::shared_ptr<Elevage> NotificationChangementEtat::getPtrElevage ()
//{
//    return ptrElevage;
//}

int NotificationChangementEtat::getIDNotification ()
{
    return id;
}

}