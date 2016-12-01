/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "EtatsObserver.h"

namespace Etats
{
EtatsObserver::EtatsObserver ()
{}

void EtatsObserver::ajouterNotifications (std::shared_ptr<NotificationChangementEtat> notif)
{
    mutexNotification.lock();
    mesNotifications.push_back(notif);
    mutexNotification.unlock();
}

void EtatsObserver::actualiserRendu ()
{
    while(1)
    {
        while(mesNotifications.empty()==false)
        {
            mutexNotification.lock();
            mesNotifications.back()->actualiserChangementRendu();
            mesNotifications.pop_back();
            mutexNotification.unlock();
        }
    }
}

}