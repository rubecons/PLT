/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "EtatsObserver.h"
#include <iostream>
//#define MULTITHREAD

namespace Etats
{
EtatsObserver::EtatsObserver ()
{}

void EtatsObserver::ajouterNotifications (std::shared_ptr<NotificationChangementEtat> notif)
{
#ifdef MULTITHREAD    
    mutexNotification.lock();
#endif
    mesNotifications.push_back(notif);
#ifdef MULTITHREAD
    mutexNotification.unlock();
#endif
}

void EtatsObserver::actualiserRendu ()
{std::cout<< "test : actualiser rendu"<<std::endl;
#ifdef MULTITHREAD    
    while(1)
    {
#endif
        while(mesNotifications.empty()==false)
        {
#ifdef MULTITHREAD
            mutexNotification.lock();
#endif
            mesNotifications.front()->actualiserChangementRendu(ferme);
            mesNotifications.pop_front();
#ifdef MULTITHREAD
            mutexNotification.unlock();
#endif
        }
#ifdef MULTITHREAD
    }
#endif
}

void EtatsObserver::setFerme (std::shared_ptr<Ferme> frm)
{
    ferme=frm;
}

/*void EtatsObserver::setTemps (std::shared_ptr<Temps> tps)
{
    temps=tps;
}*/

}