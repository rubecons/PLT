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
    
    
    Elevage::Elevage (std::string nom, std::shared_ptr<Race> race, std::shared_ptr<Temps> tps, std::shared_ptr<Ferme> frm)
    {
        nomElevage=nom;
        raceElevage=race;
        temps=tps;
        ferme=frm;
        ferme->incrementNbElevage++;
        idElevage=(raceElevage->getIDRace())+std::to_string(ferme->incrementNbElevage);
    }
    
    Elevage::~Elevage ()
    {
    }
    
    void Elevage::rajouterAnimalListe (std::shared_ptr<Animal> animal)
    {
        animauxElevage.push_back(animal);
    }
    
    void Elevage::supprimerAnimalListe (std::vector<std::shared_ptr<Animal>>::iterator it)//Animal* animal)
    {
        animauxElevage.erase(it);
    }
    
    std::string Elevage::getIdElevage ()
    {
        return idElevage;
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
    
    std::shared_ptr<Temps> Elevage::getTemps ()
    {
        return temps;
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
    
    void Elevage::setTemps (std::shared_ptr<Temps> tps)
    {
        temps=tps;
    }
}