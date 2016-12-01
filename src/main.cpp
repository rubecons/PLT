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
#include "moteur/Moteur.h"
#include "moteur/CommandeAfficherFenetre.h"
#include <iostream>
#include <thread>

//#define TEST

#ifdef TEST
#include "Etats/Race.h"
#include "Etats/Elevage.h"

#include "Etats/AnimalFemelle.h"
#include "Etats/Animal.h"
#include "Etats/AnimalMale.h"
#include "moteur/PasserMoisSuivant.h"
#include "moteur/CommandeVendreBete.h"
#include "moteur/CommandeNouvelElevage.h"
#include "moteur/CommandeAccouplerBete.h"
#include "moteur/CommandeNouvelleBete.h"
#include "moteur/CommandeInitialiserFermeTemps.h"

#endif

using namespace Rendu;
using namespace Etats;
using namespace moteur;


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
        }std::cout<< "date : " << temps->getMois()+1 << "/"<<temps->getAnnee() <<" | ferme : Budget: "<< ferme->getBudget() <<" € | Emprunts:"<< ferme->getEmprunt()<<" €\n\n"<<std::endl;
        
        
    }//*/
#ifdef TEST
    // INITIALISATION DE LA FERME POUR TEST
    
    std::cout<< "test init"<<std::endl;
    std::shared_ptr<Moteur> moteur=std::make_shared<Moteur>();std::cout<< "test moteur créé"<<std::endl;
    std::shared_ptr<Ferme> ferme=std::make_shared<Ferme>();      
            
    std::cout<< "test ferme pointeur créé"<<std::endl;
    std::shared_ptr<Temps> temps= std::make_shared<Temps>();
    std::cout<< "test temps créé"<<std::endl;
    /*ferme->setBudget(6573635.0);
    ferme->emprunter(435.0);
    temps->setAnnee(2016);
    temps->setMois(7);*/
    
    std::shared_ptr<CommandeInitialiserFermeTemps> initFrmTps = std::make_shared<CommandeInitialiserFermeTemps>(ferme, temps, 335646, 543, 10, 2016);
    std::cout<< "test création commande"<<std::endl;
    moteur->ajouterCommande(initFrmTps);
    std::cout<< "test rajout commande liste"<<std::endl;
    moteur->execCommande();
    std::cout<< "test execution commande"<<std::endl; std::cout<< "test execution commande"<<std::endl;
    
    std::cout<< "date : " << temps->getMois()+1 << "/"<<temps->getAnnee() <<" | ferme : Budget: "<< ferme->getBudget() <<" € | Emprunts:"<< ferme->getEmprunt()<<" €\n\n"<<std::endl;
    
    std::shared_ptr<Race> vacheLimousine=std::make_shared<Race>("Bos Taurus Limousin", 264, 264, 1100, 800, 11, 15, 0.55, 0.46, 9, 2, 1, 45, 2.80, 3);
    ferme->ajouterRaceListe(vacheLimousine);
    std::shared_ptr<Elevage> elevageVache = std::make_shared<Elevage>("Elevage Limousines", vacheLimousine, temps, ferme);
    ferme->ajouterElevageListe(elevageVache);
    
    std::shared_ptr<Animal> vache1 =  std::make_shared<AnimalMale>(elevageVache, 2, 2014, std::vector<std::string>(14)={"E1", "E2","E3", "E4","E5", "E6","E7", "E8", "E9", "E10","E11", "E12","E13", "E14"});
    
    std::shared_ptr<Animal> vache2 =  std::make_shared<AnimalFemelle>(elevageVache, 7, 2013, std::vector<std::string>(14)={"E15", "BOSTAULIM1-M3","E17", "E18","E19", "E20","E21", "E22", "E23", "E24","E25", "E26","E27", "28"});
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
    //std::cout<< "l'animal vache1, était à la base " << /*vache1->getSexe()<<std::endl;/*/typeid(*vache1).name()<< " et s'appelle " << vache1->getIDAnimal() <<std::endl;
    /*std::cout<< "creation de vache3 et vache4" <<std::endl;
    AnimalMale* vache3= new AnimalMale(elevageVache, 2, 2014, std::vector<std::string>(14)={"E1", "E2","E3", "E4","E5", "E6","E7", "E8", "E9", "E10","E11", "E12","E13", "E14"});
    AnimalFemelle* vache4= new AnimalFemelle(elevageVache, 5, 2013, std::vector<std::string>(14)={"E15", "BOSTAULIM1-M3","E17", "E18","E19", "E20","E21", "E22", "E23", "E24","E25", "E26","E27", "28"});
    std::cout<< "la derniere fois que vache4 a enfanté etait en : " <<vache4->getDateDerniereMiseBas()[0]<<','<<vache4->getDateDerniereMiseBas()[1]<<". La vache a un age de "<< (vache4->getIDElevage()->getTemps()->getMois()-vache4->getDateNaissance()[0])+(12*(vache4->getIDElevage()->getTemps()->getAnnee()-vache4->getDateNaissance()[1])) <<" mois, alors que sa majorité sexuelle se fait à l'age de "<< vache4->getIDElevage()->getRace()->getAgeMoyenMaturite(vache4->getSexe()) <<"mois"<<std::endl;
    std::cout<< "accouplement de vache3 et vache4" <<std::endl;
    vache4->accoupler(vache3);
    std::cout<< "fin accouplement de vache3 et vache4" <<std::endl;//*/
    /*/std::cout<< "l'animal vache2, était à la base " << vache2->getSexe()<<std::endl;
    if(vache1->getSexe())
    {
        AnimalMale* pointeurAnimalMale=static_cast<AnimalMale*>(vache1.get());
        AnimalFemelle* pointeurAnimalFemelle=static_cast<AnimalFemelle*>(vache2.get());
        //AnimalMale* ptrAnMale;std::cout<< "l'animal ptrAnMale, était à la base " << vache1->getSexe()<<std::endl;typeid(ptrAnMale).name()<<std::endl;
        //pointeurAnimalMale->accoupler(pointeurAnimalFemelle);
        //std::cout<< "l'animal vache1, était à la base " << /*vache1->getSexe()<<std::endl;/*/typeid(pointeurAnimalMale).name()<< " et s'appelle " << pointeurAnimalMale->getIDAnimal()<<std::endl;
        //std::cout<< "l'animal vache2, était à la base " << /*vache1->getSexe()<<std::endl;/*/typeid(pointeurAnimalFemelle).name()<< " et s'appelle " << pointeurAnimalFemelle->getIDAnimal()<<std::endl;
        //std::cout<< "l'animal vache2, était à la base " << static_cast<AnimalFemelle*>(vache2)<<std::endl;
    //}//*/
    
    
    
    //std::cout<< "test "<<std::endl;
    std::shared_ptr<PasserMoisSuivant> moisSuivant=std::make_shared<PasserMoisSuivant>(temps, ferme);
    moteur->ajouterCommande(moisSuivant);
    //moteur->execCommande();
    
    //std::shared_ptr<CommandeVendreBete> vendreBete=std::make_shared<CommandeVendreBete>(vache2, ferme);
    //moteur->ajouterCommande(vendreBete);
    //moteur->execCommande();
    
    std::shared_ptr<CommandeNouvelElevage> nouvelElevage=std::make_shared<CommandeNouvelElevage>("Deuxieme Elevage de vache", vacheLimousine,temps,ferme);
    moteur->ajouterCommande(nouvelElevage);
    moteur->execCommande();
    
    std::shared_ptr<CommandeAccouplerBete> accouplerBete = std::make_shared<CommandeAccouplerBete>(vache1, vache2);
    moteur->ajouterCommande(accouplerBete);
    
    std::shared_ptr<CommandeNouvelleBete> cNouvelleBete= std::make_shared<CommandeNouvelleBete>(ferme, ferme->getElevages()[1], false, 7, 2015, std::vector<std::string>(14)={"E115", "BOSTAULIM1-M31","E117", "E118","E119", "E120","E121", "E122", "E123", "E124","E125", "E126","E127", "E128"});
    moteur->ajouterCommande(cNouvelleBete);
    
    moteur->execCommande();
    
    moisSuivant=std::make_shared<PasserMoisSuivant>(temps, ferme);
    moteur->ajouterCommande(moisSuivant);
    moisSuivant=std::make_shared<PasserMoisSuivant>(temps, ferme);
    moteur->ajouterCommande(moisSuivant);
    moisSuivant=std::make_shared<PasserMoisSuivant>(temps, ferme);
    moteur->ajouterCommande(moisSuivant);
    moisSuivant=std::make_shared<PasserMoisSuivant>(temps, ferme);
    moteur->ajouterCommande(moisSuivant);
    moisSuivant=std::make_shared<PasserMoisSuivant>(temps, ferme);
    moteur->ajouterCommande(moisSuivant);
    moisSuivant=std::make_shared<PasserMoisSuivant>(temps, ferme);
    moteur->ajouterCommande(moisSuivant);
    moisSuivant=std::make_shared<PasserMoisSuivant>(temps, ferme);
    moteur->ajouterCommande(moisSuivant);

    
    moteur->execCommande();
    
    
    
    // TEST APRES TEST MOTEUR
    
    ///*
    std::cout<< "date : " << temps->getMois()+1 << "/"<<temps->getAnnee() <<" | ferme : Budget: "<< ferme->getBudget() <<" € | Emprunts:"<< ferme->getEmprunt()<<" €\n\n"<<std::endl;
    for (auto  elevage : ferme->getElevages())
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
    }//*/
    //std::cout<< "test "<<std::endl;
    
    moisSuivant=std::make_shared<PasserMoisSuivant>(temps, ferme);
    moteur->ajouterCommande(moisSuivant);
    
    moteur->execCommande();
    
    
    
    // TEST APRES TEST MOTEUR
    
    ///*
    std::cout<< "date : " << temps->getMois()+1 << "/"<<temps->getAnnee() <<" | ferme : Budget: "<< ferme->getBudget() <<" € | Emprunts:"<< ferme->getEmprunt()<<" €\n\n"<<std::endl;
    for (auto  elevage : ferme->getElevages())
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
    
    
    
    
    ferme.reset(); temps.reset(); vacheLimousine.reset(); elevageVache.reset();
    
    
#else
    std::shared_ptr<Moteur> moteur=std::make_shared<Moteur>();
    std::shared_ptr<Ferme> ferme=std::make_shared<Ferme>();
    std::shared_ptr<Temps> temps= std::make_shared<Temps>();
    
    //test
    std::shared_ptr<Race> vacheLimousine=std::make_shared<Race>("Bos Taurus Limousin", 264, 264, 1100, 800, 11, 15, 0.55, 0.46, 9, 2, 1, 45, 2.80, 3);
    ferme->ajouterRaceListe(vacheLimousine);
    
    
    FenetrePrincipale* fenPrincipale;
    FenetreNouvelleRace * fenNouvelleRace= new FenetreNouvelleRace(ferme, temps, moteur);
    FenetreNouvelElevage* fenNouvelElevage=new FenetreNouvelElevage(ferme, temps, moteur, fenPrincipale);
    fenPrincipale=new FenetrePrincipale(ferme, temps, moteur, fenNouvelleRace, fenNouvelElevage);
    FenetrePremiereOuverture* feneteInit=new FenetrePremiereOuverture(ferme, temps, moteur, fenPrincipale);
        //feneteInit.show();
    
    std::thread threadMoteur(&Moteur::execCommande);
    std::thread threadActualisationRendu(&EtatsObserver::actualiserRendu());
    
    std::shared_ptr<CommandeAfficherFenetre> afficheFenetre = std::make_shared<CommandeAfficherFenetre>(ferme, temps, feneteInit);
    moteur->ajouterCommande(afficheFenetre);
    
    
    
    //fenPrincipale.show();
    
    
    //fenetreNouvelleRace.show();
    
    //fenetreNouvelElevage.show();//*/
#endif    
    /*QWidget *firstPageWidget = new QWidget;
    QWidget *secondPageWidget = new QWidget;
    QWidget *thirdPageWidget = new QWidget;

    QStackedLayout *stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(firstPageWidget);
    stackedLayout->addWidget(secondPageWidget);
    stackedLayout->addWidget(thirdPageWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stackedLayout);
    setLayout(mainLayout);LL
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
