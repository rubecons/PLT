/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DbManager.hpp
 * Author: ruben
 *
 * Created on 5 novembre 2016, 23:37
 */
#include "librairiesQt.hpp"
#include "FenetrePremiereOuverture.hpp"

#ifndef DBMANAGER_HPP
#define DBMANAGER_HPP
#define ERROR_OPN_CONNECTION 1

class DbManager : public QObject{
public:
    DbManager();
    //DbManager(const DbManager& orig);
    virtual ~DbManager();
    bool chargerFerme();//FenetrePremiereOuverture* fen);
    void nouvelElevage();
    void NouvelleRace();
    void NouvelleBete();
    void afficherElevage();
    void afficherBete();
    
public slots:
    void gererValeurs();//FenetrePremiereOuverture* fen);//double bud, double emp);
    
private:
    QSqlDatabase dbConnexion;

};

#endif /* DBMANAGER_HPP */

