/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: ruben
 *
 * Created on 19 octobre 2016, 10:04
 */


//#include "librairiesQt.hpp"
//#include "DbManager.h"
#include <QApplication>
#include "Rendu/FenetrePremiereOuverture.h"
#include "Rendu/FenetreNouvelElevage.h"
#include "Rendu/FenetrePrincipale.h"
#include "Rendu/FenetreNouvelleBete.h"
#include "Rendu/FenetreNouvelleRace.h"



using namespace Rendu;
//using namespace Etats;


int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    
    /*DbManager* dbConn;
    
    try
    {
        dbConn = new DbManager();
    }
    catch(int e)
    {
        if(e==ERROR_OPN_CONNECTION)
        {
            QMessageBox::critical(NULL, QObject::tr("Erreur Fatale"), QObject::tr("La base de donnée n'a pas pu être ouverte ! "), QMessageBox::Ok, QMessageBox::Ok);
            return 1;
        }
    }//*/
    //dbConn->chargerFerme();
    

    /*
    if(!(dbConn->chargerFerme(feneteInit)))
    {
        //FenetrePremiereOuverture feneteInit;
        
        
        //if (feneteInit->enregistrerActif==true && feneteInit->getBudget()<0 && feneteInit->getEmprunts()<0)
        
        
        while (feneteInit->getBudget()<0 && feneteInit->getEmprunts()<0)
        {
            
            double budget=feneteInit->getBudget();
            double emprunt=feneteInit->getEmprunts();
            dbConn->chargerFerme(feneteInit);
        }
        
        
    }//*/
//Ferme ferme;
    FenetrePrincipale fenPrincipale; // = new FenetrePrincipale();
    fenPrincipale.show();
    FenetrePremiereOuverture feneteInit;//dbConn);
    feneteInit.show();
    FenetreNouvelleRace fenetreNouvelleRace;
    fenetreNouvelleRace.show();
    FenetreNouvelElevage fenetreNouvelElevage;
    fenetreNouvelElevage.show();//*/
    
    /*QWidget *firstPageWidget = new QWidget;
    QWidget *secondPageWidget = new QWidget;
    QWidget *thirdPageWidget = new QWidget;

    QStackedLayout *stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(firstPageWidget);
    stackedLayout->addWidget(secondPageWidget);
    stackedLayout->addWidget(thirdPageWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stackedLayout);
    setLayout(mainLayout);
 */   
    // create and show your widgets here
    
    //barremenu.setFloatable(false);
    //barremenu.setMovable(false);
    
    //QPushButton *boutonAide 
    
    /*fenetre.setWindowIcon(QIcon(QCoreApplication::applicationDirPath()+"/taureau.png"));//il faut changer le chemin si on est dans microsoft
    QPushButton bouton("ceci est un bouton", &fenetre);
    QPushButton bouton2("ceci est un autre bouton", &fenetre);
    bouton2.move(0, fenetre.height()/2);
    //fenetre.show();
    bouton2.show();
    bouton.show();*/
    //QQuickWindow fenetre();
    
    
    return app.exec();
}
