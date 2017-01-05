/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CommandeAfficherFenetre.h"

namespace moteur
{
CommandeAfficherFenetre::CommandeAfficherFenetre ()
{
    
}

CommandeAfficherFenetre::CommandeAfficherFenetre (std::shared_ptr<Etats::Ferme> frm, QWidget* fen)
{
    ferme=frm;
    //temps=tps;
    fenetre=fen;
}

CommandeAfficherFenetre::~CommandeAfficherFenetre ()
{
    
}

void CommandeAfficherFenetre::effectuerCommande ()
{
    fenetre->show();
}

}