/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DbManager.cpp
 * Author: ruben
 * 
 * Created on 5 novembre 2016, 23:38
 */
/*
#include "DbManager.hpp"
//#include "FenetrePremiereOuverture.hpp"

DbManager::DbManager() {
    dbConnexion=QSqlDatabase::addDatabase("QSQLITE");
    dbConnexion.setDatabaseName("elevage_numerique.db");
    if(!dbConnexion.open()) throw ERROR_OPN_CONNECTION;
}

DbManager::DbManager(const DbManager& orig) {
}

DbManager::~DbManager() {
    dbConnexion.close();
}

bool DbManager::chargerFerme()//FenetrePremiereOuverture* fen)
{
    QSqlQuery query;
    
    if(!query.exec("SELECT * FROM ferme"))
    {
            //QMessageBox::critical(NULL, QObject::tr("Erreur"), QObject::tr("La table ferme n'a pas été trouvée ! "), QMessageBox::Ok, QMessageBox::Ok);
        //FenetrePremiereOuverture feneteInit;//= new FenetrePremiereOuverture;
        //feneteInit.show();
        
            
        //double budgt=fen->getBudget();
        //double emprt=fen->getEmprunts();
        
        while (budgt<0 && emprt<0)
        {
            
            budgt=feneteInit.getBudget();
            emprt=feneteInit.getEmprunts();
        }//
        if (budgt>=0 && emprt>=0)
        {query.exec("CREATE TABLE ferme(ferme varchar(10),budget REAL, argent_emprunte REAL)");
        query.prepare("INSERT INTO ferme VALUES('ferme', :budget, :emprunts)");
        query.bindValue(":budget", budgt);
        query.bindValue(":emprunts", emprt);
        query.exec();
        }
        //while (feneteInit.isVisible()){}
        //QMessageBox::critical(NULL, QObject::tr("valeurs inserées"), QString("les valeurs insérées sont\nbudget : "+QString::number(budgt, 'g', 6)+"\nemprunts"+QString::number(emprt, 'g', 6)), QMessageBox::Ok, QMessageBox::Ok);
        //feneteInit.~FenetrePremiereOuverture();
        //delete feneteInit;
        return false;
    }
    else
    {
        query.exec("SELECT * FROM ferme");
        return true;
    }
    //if(query.exec("SELECT * FROM ferme"))
}

void DbManager::gererValeurs()//FenetrePremiereOuverture* fen)//double bud, double emp)
{
    //QMessageBox::critical(NULL, QObject::tr("valeurs inserées"), QString("les valeurs insérées sont\nbudget : "+QString::number(fen->getBudget(), 'g', 6)+"\nemprunts"+QString::number(fen->getEmprunts(), 'g', 6)), QMessageBox::Ok, QMessageBox::Ok);
    //chargerFerme(fen);
    //chargerFerme(fen);
}//*/