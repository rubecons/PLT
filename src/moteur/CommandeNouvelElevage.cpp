/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CommandeNouvelElevage.h"
#include "Etats/NotificationChangementEtat.h"
#include <iostream>

namespace moteur
{
CommandeNouvelElevage::CommandeNouvelElevage ()
{
    
}

CommandeNouvelElevage::CommandeNouvelElevage (std::shared_ptr<Etats::Ferme> frm, std::string nm, std::shared_ptr<Etats::Race> rac, Rendu::FenetrePrincipale *fenPrincipale, std::shared_ptr<Etats::EtatsObserver> observ)
{
    nom=nm;
    race=rac;
    //temps=tmp;
    ferme=frm;
    observer=observ;
}

CommandeNouvelElevage::~CommandeNouvelElevage ()
{
    
}

void CommandeNouvelElevage::effectuerCommande ()
{
    std::cout<< "test : execution de la commande"<<std::endl;
    std::shared_ptr<Etats::Elevage> elevage = std::make_shared<Etats::Elevage>(nom, race, ferme);
    ferme->ajouterElevageListe(elevage);
    std::cout<< "test : creation de la notification"<<std::endl;
    std::shared_ptr<Etats::NotificationChangementEtat> notif =std::make_shared<Etats::NotificationChangementEtat>(Etats::ChangementEtatsID::LISTE_ELEVAGE_CHANGE, elevage, fenetrePrincipale);
    observer->ajouterNotifications(notif);
    observer->actualiserRendu();
}

}