/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Temps.h"

namespace Etats {

Temps::Temps()
{
    nomMois={"janvier", "février","mars","avril", "mai", "juin", "juillet", "août", "septembre", "octobre", "novembre", "décembre"};
    /*
    nomMois[8]="septembre";
    nomMois[9]="octobre";
    nomMois[10]="novembre";
    nomMois[11]="décembre";//*/
}

Temps::Temps(int m, int a)
{
    annee=a;
    mois=m;
}

int Temps::getAnnee()
{
    return annee;
}

int Temps::getMois()
{
    return mois;
}

void Temps::setAnnee (int an)
{
    annee=an;
}

void Temps::setMois (int ms)
{
    mois=ms;
}

/*void Temps::upAnnee ()
{
    annee++;
}//*/

void Temps::upMois ()
{
    mois=(mois+1)%12;
    if(mois==0)annee++;
}

std::array<std::string, 12> Temps::getNomMois ()
{
    return nomMois;
}

}

