/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ferme.h"
#include <iterator>

namespace Etats{

Ferme::Ferme()
{
}    
    
Ferme::Ferme (std::shared_ptr<Temps> tps) 
{
    temps=tps;
}

Ferme::Ferme (double b, double em,std::shared_ptr<Temps> tps) 
{
    budget=b;
    argentEmprunte=em;
    temps=tps;
}

Ferme::~Ferme ()
{
    
}

void Ferme::setTemps (std::shared_ptr<Temps> tps)
{
    temps=tps;
}

std::shared_ptr<Temps> Ferme::getTemps ()
{
    return temps;
}

void Ferme::ajouterElevageListe (std::shared_ptr<Elevage> elevage)
{
    mesElevages.push_back(elevage);
    //mesElevages.sort();
    
    /*if(mesElevages.empty())
    {
        mesElevages.push_back(elevage);
    }
    else
    {
        
    }//*/
}

/*bool Ferme::supprimerElevageListe (std::string nom);//std::shared_ptr<Elevage> elevage)
{
    std::list<Elevage*>::iterator iter=mesElevages.begin();
    while (((*iter)->nomElevage)!=nom && iter!=mesElevages.end())
    {
        iter++;
    }
    if(((*iter)->nomElevage)==nom && iter!=mesElevages.end())
    {
        mesElevages.remove(iter);
        return true;
    }
    else
    {
        return false;
    }
}*/

bool Ferme::supprimerElevageListe (std::string IDElevage)//std::shared_ptr<Elevage> elevage)
{
    /*std::list<Elevage*>::iterator iter=mesElevages.begin();
    while (((*iter)->nomElevage)!=nom && iter!=mesElevages.end())
    {
        iter++;
    }//*/
    for(auto elevage : mesElevages)
    {
        if(elevage->getIdElevage()==IDElevage && elevage->getEtat()==EtatElevage::ACTIF)
        {
            elevage->setEtat(EtatElevage::ARRET);
            //animal.reset();
            return true;
        }
        
    }
    /*if(select<(int)(mesElevages.end()-mesElevages.begin()))
    {
        mesElevages.erase(mesElevages.begin()+select);
        return true;
    }
    else
    {
        return false;
    }*/
    return false;
}

void Ferme::ajouterRaceListe (std::shared_ptr<Race> race)
{
    //std::list<std::shared_ptr<Race>> mesRaces;
    mesRaces.push_back(race);
}

bool Ferme::supprimerRaceListe (int select)
{
    //std::list<std::shared_ptr<Race>> mesRaces;
    if(select<(int)(mesRaces.end()-mesRaces.begin()))
    {
        mesRaces.erase(mesRaces.begin()+select);
        return true;
    }
    else
    {
        return false;
    }
}

double Ferme::getBudget ()
{
    return budget;
}

void Ferme::setBudget (double budgetInitial)
{
    budget=budgetInitial;
}

std::vector<std::shared_ptr<Elevage>> Ferme::getElevages ()
{
    return mesElevages;
}

double Ferme::getEmprunt ()
{
    return argentEmprunte;
}

std::vector<std::shared_ptr<Race>> Ferme::getRaces ()
{
    return mesRaces;
}

void Ferme::emprunter (double sommeEmprunt)
{
    argentEmprunte+=sommeEmprunt;
}

void Ferme::remboursementEmprunt (double sommeRemboursee)
{
    argentEmprunte-=sommeRemboursee;
}

double Ferme::plusBudget (double argentAjoute)
{
    budget+=argentAjoute;
    return budget;
}

double Ferme::moinsBudget (double argentDepense)
{
    budget-=argentDepense;
    return budget;
}
    
}