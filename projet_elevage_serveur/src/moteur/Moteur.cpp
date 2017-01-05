/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Moteur.h"
//#include <QLabel>
#include <iostream>

//#define MULTITHREAD

namespace moteur
{
    
Moteur::Moteur ()
{
    
}

void Moteur::ajouterCommande (std::shared_ptr<Commande> com)
{
#ifdef MULTITHREAD
    corentinFDP.lock();
#endif
    mesCommandes.push_back(com);
#ifdef MULTITHREAD
    corentinFDP.unlock();
#endif
}

void Moteur::execCommande ()
{
#ifdef MULTITHREAD
    while(1)
    {std::cout<<"t";
#endif    
        while(mesCommandes.empty()==false)
        {
#ifdef MULTITHREAD
            corentinFDP.lock();
#endif
            //std::cout<<"mutex lock ";
            mesCommandes.front()->effectuerCommande();
            mesCommandes.pop_front();
#ifdef MULTITHREAD
            corentinFDP.unlock();
#endif
            //std::cout<<"mutex unlock ";
        }
#ifdef MULTITHREAD
    }
#endif    
    
}
            
}