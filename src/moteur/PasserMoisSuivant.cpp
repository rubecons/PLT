/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PasserMoisSuivant.h"
#include "Etats/AnimalFemelle.h"
#include "Etats/EtatAnimal.h"
#include "Etats/EtatElevage.h"


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
    for (auto  elevage : ferme->getElevages())
    {
        if(elevage->getEtat()==Etats::EtatElevage::ACTIF)
        {
            for(auto a : elevage->getAnimaux())
            {
                //Calcul de l'âge de l'animal
                int ageAnimal=(a->getIDElevage()->getTemps()->getMois()-a->getDateNaissance()[0])+(12*(a->getIDElevage()->getTemps()->getAnnee()-a->getDateNaissance()[1]));
                
                
                //calcul du poids de l'animal, et de ce qu'il a couté ce mois-ci + argent soustrait au budet de la ferme
                double poids;
                if((ageAnimal)<a->getIDElevage()->getRace()->getAgeMoyenMaturite(a->getSexe()))
                {
                    poids=(ageAnimal*(double)((a->getIDElevage()->getRace()->getPoidsMoyenAdulte(a->getSexe())-a->getIDElevage()->getRace()->getPoidsMoyenNaissance())/a->getIDElevage()->getRace()->getAgeMoyenMaturite(a->getSexe())))+(a->getIDElevage()->getRace()->getPoidsMoyenNaissance());
                }
                else
                {
                    poids=a->getIDElevage()->getRace()->getPoidsMoyenAdulte(a->getSexe());
                }
                double coutAnimal=poids*a->getIDElevage()->getRace()->getPrixNourritureVeterinaireParKilo(a->getSexe());
                ferme->moinsBudget(coutAnimal);
                
                //Mise bas de toutes les femelles qui arrivent au terme
                
                if(a->getEtat()==Etats::EtatAnimal::VIVANT && a->getSexe()==false)
                {
                    std::shared_ptr<Etats::AnimalFemelle> femelle=std::static_pointer_cast<Etats::AnimalFemelle>(a);
                    femelle->mettreBas();
                }
                
                //Décès de toutes les bêtes qui passent l'espérance de vie
                if(a->getEtat()==Etats::EtatAnimal::VIVANT && ageAnimal>=a->getIDElevage()->getRace()->getEsperanceDeVie(a->getSexe()))
                {
                    a->setEtat(Etats::EtatAnimal::MORT);
                }
            }
        }
    }
}

}