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
#include <memory>
#include <QApplication>
#include "Rendu/FenetrePremiereOuverture.h"
#include "Rendu/FenetreNouvelElevage.h"
#include "Rendu/FenetrePrincipale.h"
#include "Rendu/FenetreNouvelleBete.h"
#include "Rendu/FenetreNouvelleRace.h"
#include "Etats/Ferme.h"
#include "Etats/Temps.h"
#include "Etats/Race.h"
#include "Etats/Elevage.h"
#include <iostream>
#include "Etats/AnimalFemelle.h"
#include "Etats/Animal.h"
#include "Etats/AnimalMale.h"
#include "moteur/Moteur.h"
#include "moteur/PasserMoisSuivant.h"
#include "moteur/CommandeVendreBete.h"
#include "moteur/CommandeNouvelElevage.h"

#define TEST

using namespace Rendu;
using namespace Etats;
using namespace moteur;


int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    //QApplication app(argc, argv);
    
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
#ifdef TEST
    // INITIALISATION DE LA FERME POUR TEST
    
    
    std::shared_ptr<Moteur> moteur=std::make_shared<Moteur>();
    std::shared_ptr<Ferme> ferme=std::make_shared<Ferme>(54245,865);
    std::shared_ptr<Temps> temps= std::make_shared<Temps>(11, 2016);
    
    std::shared_ptr<Race> vacheLimousine=std::make_shared<Race>("Bos Taurus Limousin", 264, 264, 1100, 800, 11, 15, 0.55, 0.46, 9, 2, 1, 45, 2.80, 3);
    ferme->ajouterRaceListe(vacheLimousine);
    std::shared_ptr<Elevage> elevageVache = std::make_shared<Elevage>("Elevage Limousines", vacheLimousine, temps, ferme);
    ferme->ajouterElevageListe(elevageVache);
    
    std::shared_ptr<Animal> vache1 =  std::make_shared<AnimalMale>(elevageVache, 2, 2014, std::vector<std::string>(14)={"E1", "E2","E3", "E4","E5", "E6","E7", "E8", "E9", "E10","E11", "E12","E13", "E14"});
    
    std::shared_ptr<Animal> vache2 =  std::make_shared<AnimalFemelle>(elevageVache, 7, 2013, std::vector<std::string>(14)={"E15", "E2","E3", "E4","E5", "E6","E7", "E8", "E9", "E10","E11", "E12","E13", "E14"});
    elevageVache->rajouterAnimalListe(vache1);
    elevageVache->rajouterAnimalListe(vache2);
    
    // VISIONNAGE DE LA BASE DE DONNEE APRES INITIALISATION
    
    
    std::cout<< "date : " << temps->getMois()+1 << "/"<<temps->getAnnee() <<" | ferme : Budget: "<< ferme->getBudget() <<" € | Emprunts:"<< ferme->getEmprunt()<<" €\n\n"<<std::endl;
    for (auto elevage : ferme->getElevages())
    {
        if(elevage->getEtat()==EtatElevage::ACTIF)
        {
            std::cout<<"elevage "<< elevage->getNomElevage()<<".  |  race de l'elevage"<< elevage->getRace()->getNomRace()<<std::endl;
            for(auto a : elevage->getAnimaux())
            {
                if(a->getEtat()==EtatAnimal::VIVANT)
                std::cout<<"    animal : "<< a->getIDAnimal()<<std::endl;
            }
            std::cout<<"fin  de l'elevage "<< elevage->getNomElevage()<<"\n\n"<<std::endl;
        }
    }
    
    // TEST MOTEUR
    std::cout<< "l'animal vache1, était à la base " << /*vache1->getSexe()<<std::endl;/*/typeid(*vache1).name()<< " et s'appelle " << vache1->getIDAnimal() <<std::endl;
    //std::cout<< "l'animal vache2, était à la base " << vache2->getSexe()<<std::endl;
    if(vache1->getSexe())
    {
        AnimalMale* pointeurAnimalMale=static_cast<AnimalMale*>(vache1.get());
        AnimalFemelle* pointeurAnimalFemelle=static_cast<AnimalFemelle*>(vache2.get());
        pointeurAnimalMale->accoupler(pointeurAnimalFemelle);
        //std::cout<< "l'animal vache1, était à la base " << /*vache1->getSexe()<<std::endl;/*/typeid(*pointeurAnimalMale).name()<< " et s'appelle " << pointeurAnimalMale->getIDAnimal()<<std::endl;
        //std::cout<< "l'animal vache2, était à la base " << static_cast<AnimalFemelle*>(vache2)<<std::endl;
    }
    
    
    
    std::cout<< "test "<<std::endl;
    std::shared_ptr<PasserMoisSuivant> moisSuivant=std::make_shared<PasserMoisSuivant>(temps, ferme);
    moteur->ajouterCommande(moisSuivant);
    //moteur->execCommande();
    
    std::shared_ptr<CommandeVendreBete> vendreBete=std::make_shared<CommandeVendreBete>(vache2, ferme);
    moteur->ajouterCommande(vendreBete);
    //moteur->execCommande();
    
    std::shared_ptr<CommandeNouvelElevage> nouvelElevage=std::make_shared<CommandeNouvelElevage>("Deuxieme Elevage de vache", vacheLimousine,temps,ferme);
    moteur->ajouterCommande(nouvelElevage);
    moteur->execCommande();
    
    // TEST APRES TEST MOTEUR
    
    /*
    std::cout<< "date : " << temps->getMois()+1 << "/"<<temps->getAnnee() <<" | ferme : Budget: "<< ferme->getBudget() <<" € | Emprunts:"<< ferme->getEmprunt()<<" €\n\n"<<std::endl;
    for (auto  elevage : ferme->getElevages())
    {
        if(elevage->getEtat()==EtatElevage::ACTIF)
        {
           std::cout<<"elevage"<< elevage->getNomElevage()<<".  |  race de l'elevage"<< elevage->getRace()->getNomRace()<<std::endl;
           for(auto a : elevage->getAnimaux())
           {
               if(a->getEtat()==EtatAnimal::VIVANT)
               std::cout<<"    animal : "<< a->getIDAnimal()<<std::endl;
           }
           std::cout<<"fin  de l'elevage "<< elevage->getNomElevage()<<"\n\n"<<std::endl;
        }
    }*/
    std::cout<< "test "<<std::endl;
    
    ferme.reset(); temps.reset(); vacheLimousine.reset(); elevageVache.reset();
    
    
#endif
    
    /*FenetrePremiereOuverture feneteInit(ferme, temps);//dbConn);
    feneteInit.show();
    
    FenetrePrincipale fenPrincipale(ferme, temps); // = new FenetrePrincipale();
    fenPrincipale.show();
    
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
    
    
    //return app.exec();
}
