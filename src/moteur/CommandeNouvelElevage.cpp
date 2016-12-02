/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CommandeNouvelElevage.h"
#include "Etats/NotificationChangementEtat.h"

namespace moteur
{
CommandeNouvelElevage::CommandeNouvelElevage ()
{
    
}

CommandeNouvelElevage::CommandeNouvelElevage (std::string nm, std::shared_ptr<Etats::Race> rac, std::shared_ptr<Etats::Temps> tmp, std::shared_ptr<Etats::Ferme> frm, std::shared_ptr<Etats::EtatsObserver> observ, Rendu::FenetrePrincipale *fenPrincipale)
{
    nom=nm;
    race=rac;
    temps=tmp;
    ferme=frm;
    observer=observ;
}

CommandeNouvelElevage::~CommandeNouvelElevage ()
{
    
}

void CommandeNouvelElevage::effectuerCommande ()
{
    std::shared_ptr<Etats::Elevage> elevage = std::make_shared<Etats::Elevage>(nom, race, temps, ferme);
    ferme->ajouterElevageListe(elevage);
    std::shared_ptr<Etats::NotificationChangementEtat> notif =std::make_shared<Etats::NotificationChangementEtat>(Etats::ChangementEtatsID::LISTE_ELEVAGE_CHANGE, elevage, fenetrePrincipale);
    observer->ajouterNotifications(notif);
}

}