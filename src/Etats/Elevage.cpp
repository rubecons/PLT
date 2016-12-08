/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Elevage.h"


namespace Etats{
    Elevage::Elevage ()
    {
    }
    
    Elevage::Elevage (std::string nom, std::shared_ptr<Race> race, std::shared_ptr<Ferme> frm)
    {
        nomElevage=nom;
        raceElevage=race;
        //temps=tps;
        ferme=frm;
        ferme->incrementNbElevage++;
        idElevage=(raceElevage->getIDRace())+std::to_string(ferme->incrementNbElevage);
        etat=EtatElevage::ACTIF;
    }
    
    Elevage::~Elevage ()
    {
    }
    
    void Elevage::rajouterAnimalListe (std::shared_ptr<Animal> animal)
    {
        animauxElevage.push_back(animal);
    }
    
    void Elevage::supprimerAnimalListe(const std::string & IDanimal, bool choixVente)
    {
        if(choixVente==true)
        {
            for(auto & animal : animauxElevage)
            {
                if(animal->getIDAnimal()==IDanimal && animal->getEtat()==EtatAnimal::VIVANT)
                {
                    double poids;
                    if(((getFerme()->getTemps()->getMois()-animal->getDateNaissance()[0])+(12*(getFerme()->getTemps()->getAnnee()-animal->getDateNaissance()[1])))<getRace()->getAgeMoyenMaturite(animal->getSexe()))
                    {
                        poids=(((getFerme()->getTemps()->getMois()-animal->getDateNaissance()[0])+(12*(getFerme()->getTemps()->getAnnee()-animal->getDateNaissance()[1])))*(double)((getRace()->getPoidsMoyenAdulte(animal->getSexe())-getRace()->getPoidsMoyenNaissance())/getRace()->getAgeMoyenMaturite(animal->getSexe())))+(getRace()->getPoidsMoyenNaissance());
                    }
                    else
                    {
                        poids=getRace()->getPoidsMoyenAdulte(animal->getSexe());
                    }
                    double gain =poids*(getRace()->getPrixVenteKilo());

                    getFerme()->plusBudget(gain);
                }
            }
        }
        
        for(auto & animal : animauxElevage)
        {
            if(animal->getIDAnimal()==IDanimal && animal->getEtat()==EtatAnimal::VIVANT)
            {
                animal->setEtat(EtatAnimal::MORT);
                //animal.reset();
            }
        }
    }
    
    std::string Elevage::getIdElevage ()
    {
        return idElevage;
    }
    
    std::vector<std::shared_ptr<Animal>> Elevage::getAnimaux ()
    {
        return animauxElevage;
    }
    
    EtatElevage Elevage::getEtat ()
    {
        return etat;
    }
    
    std::shared_ptr<Ferme> Elevage::getFerme ()
    {
        return ferme;
    }
    
    std::string Elevage::getNomElevage ()
    {
        return nomElevage;
    }
    
    std::shared_ptr<Race> Elevage::getRace ()
    {
        return raceElevage;
    }
    
    /*std::shared_ptr<Temps> Elevage::getTemps ()
    {
        return temps;
    }*/
    
    void Elevage::setEtat (EtatElevage state)
    {
        etat=state;
    }
    
    void Elevage::setFerme (std::shared_ptr<Ferme> frm)
    {
        ferme=frm;
    }
    
    void Elevage::setNomElevage (std::string nom)
    {
        nomElevage=nom;
    }
    
    void Elevage::setRace (std::shared_ptr<Race> race)
    {
        raceElevage=race;
    }
    
    /*void Elevage::setTemps (std::shared_ptr<Temps> tps)
    {
        temps=tps;
    }//*/
}