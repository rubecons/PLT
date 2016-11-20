/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Temps.h"

namespace Etats {

Temps::Temps()
{
    
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
    if(mois==1)annee++;
}

}

