/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "NotificationChangementEtat.h"

namespace Etats
{
NotificationChangementEtat::NotificationChangementEtat ()
{
}

NotificationChangementEtat::NotificationChangementEtat (ChangementEtatsID etatNotif, std::shared_ptr<Elevage> ptrElvaj)
{
    id=etatNotif;
    ptrElevage=ptrElvaj;
}

NotificationChangementEtat::~NotificationChangementEtat (){}

void NotificationChangementEtat::actualiserChangementRendu ()
{}

std::shared_ptr<Elevage> NotificationChangementEtat::getPtrElevage ()
{
    return ptrElevage;
}

ChangementEtatsID NotificationChangementEtat::getIDNotification ()
{
    return id;
}

}