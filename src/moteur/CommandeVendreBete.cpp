/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "moteur/CommandeVendreBete.h"

namespace moteur
{

CommandeVendreBete::CommandeVendreBete (){}
    
CommandeVendreBete::CommandeVendreBete (std::shared_ptr<Etats::Animal> anm, std::shared_ptr<Etats::Ferme> frm)// : animal(anm), ferme(ferme)
{
    animal=anm;
    ferme=frm;
}

void CommandeVendreBete::effectuerCommande ()
{
    
}
    
}

//on créée une commande, on l'initialise. on décrit les actions que devra effectuer la commande dans effectuer commande. on rajoute cete comande dans le vector mes cmmandes de la classe moteur., et il y  a ensuite la fonction execCommandes qui se met en route, et dans laquelle on vide le vector et que dans chaque commande qu'on vide, on appelle la methode Commande.execCommande de ces commandes desquelles on vide le voector de commandes