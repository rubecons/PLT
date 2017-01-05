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
#include "Etats/EtatsObserver.h"
#include <iostream>
#include <thread>
#include <sstream>
#include <microhttpd.h>
#include <string.h>


#include "solution/ServicesManager.hpp"
#include "solution/VersionService.hpp"
#include "solution/UserService.hpp"

//#define TEST
//#define MULTITHREAD

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
using namespace solution;


class Request {
public:
    struct MHD_PostProcessor *pp = nullptr;
    std::string data;
    ~Request() {
        if (pp) MHD_destroy_post_processor (pp);
    }
};


// Fonction pour gérer les données imporantes en upload (non implanté ici)
static int
post_iterator(void *cls,
        enum MHD_ValueKind kind,
        const char *key,
        const char *filename,
        const char *content_type,
        const char *transfer_encoding,
        const char *data, uint64_t off, size_t size) 
{
    return MHD_NO;
}

// Détruit les données d'une requête
static void
request_completed (void *cls, struct MHD_Connection *connection,
                   void **con_cls, enum MHD_RequestTerminationCode toe)
{
  Request *request = (Request*)*con_cls;
  if (request) {
      delete request;
      *con_cls = nullptr;
  }
}

// Gestionnaire principal
static int
main_handler (void *cls,      
          struct MHD_Connection *connection,
          const char *url, // 
          const char *method,
          const char *version,
          const char *upload_data, size_t *upload_data_size, void **ptr) 
{
    // Données pour une requête (en plusieurs appels à cette fonction)
    Request *request = (Request*)*ptr;

    // Premier appel pour cette requête
    if (!request) { 
        request = new Request();
        if (!request) {
            return MHD_NO;
        }
        *ptr = request;
        if (strcmp(method, MHD_HTTP_METHOD_POST) == 0
         || strcmp(method, MHD_HTTP_METHOD_PUT) == 0) {
            request->pp = MHD_create_post_processor(connection,1024,&post_iterator,request);
            if (!request->pp) {
                std::cerr << "Failed to setup post processor for " << url << std::endl;
                return MHD_NO;
            }
        }
        return MHD_YES;
    }    
    
    // Cas où il faut récupérer les données envoyés par l'utilisateur
    if (strcmp(method, MHD_HTTP_METHOD_POST) == 0
     || strcmp(method, MHD_HTTP_METHOD_PUT) == 0) {
        MHD_post_process(request->pp,upload_data,*upload_data_size);
        if (*upload_data_size != 0) {
            request->data = upload_data;
            *upload_data_size = 0;
            return MHD_YES;
        }    
    }

    HttpStatus status;
    std::string response;
    try {

        ServicesManager *manager = (ServicesManager*) cls;
        status = manager->queryService(response,request->data,url,method);
    }
    catch(ServiceException& e) {
        status = e.status();
        response = e.what();
        response += "\n";
    }
    catch(std::exception& e) {
        status = HttpStatus::SERVER_ERROR;
        response = e.what();
        response += "\n";
    }
    catch(...) {
        status = HttpStatus::SERVER_ERROR;
        response = "Unknown exception\n";
    }

    struct MHD_Response *mhd_response;
    mhd_response = MHD_create_response_from_buffer(response.size(),(void *)response.c_str(),MHD_RESPMEM_MUST_COPY);
    if (strcmp(method,MHD_HTTP_METHOD_GET) == 0) {
        MHD_add_response_header(mhd_response,"Content-Type","application/json; charset=utf-8");
    }
    int ret = MHD_queue_response(connection, status, mhd_response);
    MHD_destroy_response(mhd_response);
    return ret;
}

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    
    try {
        ServicesManager servicesManager;
        servicesManager.registerService(make_unique<VersionService>());

        UserDB userDB;
        userDB.addUser(make_unique<User>("Paul",23));
        servicesManager.registerService(make_unique<UserService>(std::ref(userDB)));

        struct MHD_Daemon *d;
        if (argc != 2) {
            printf("%s PORT\n", argv[0]);
            return 1;
        }
        d = MHD_start_daemon(// MHD_USE_SELECT_INTERNALLY | MHD_USE_DEBUG | MHD_USE_POLL,
                MHD_USE_SELECT_INTERNALLY | MHD_USE_DEBUG,
                // MHD_USE_THREAD_PER_CONNECTION | MHD_USE_DEBUG | MHD_USE_POLL,
                // MHD_USE_THREAD_PER_CONNECTION | MHD_USE_DEBUG,
                atoi(argv[1]),
                NULL, NULL, 
                &main_handler, (void*) &servicesManager,
                MHD_OPTION_NOTIFY_COMPLETED, request_completed, NULL,
                MHD_OPTION_END);
        if (d == NULL)
            return 1;
        std::cout << "Pressez <entrée> pour arrêter le serveur" << std::endl;
        (void) getc(stdin);
        MHD_stop_daemon(d);
    }
    catch(std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    
    
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
    std::shared_ptr<Temps> temps= std::make_shared<Temps>();
    std::shared_ptr<EtatsObserver> observer = std::make_shared<EtatsObserver>();
    std::shared_ptr<Moteur> moteur=std::make_shared<Moteur>();
    std::shared_ptr<Ferme> ferme=std::make_shared<Ferme>(temps);
    
    observer->setFerme(ferme);
    //observer->setTemps(temps);
    
    
    //test
    std::shared_ptr<Race> vacheLimousine=std::make_shared<Race>("Bos Taurus Limousin", 264, 264, 1100, 800, 11, 15, 0.55, 0.46, 9, 2, 1, 45, 2.80, 3);
    ferme->ajouterRaceListe(vacheLimousine);
    std::shared_ptr<Elevage> elevageVache = std::make_shared<Elevage>("Elevage Limousines", vacheLimousine, ferme);
    ferme->ajouterElevageListe(elevageVache);
    
    
    //FenetrePrincipale* fenPrincipale;
    FenetreNouvelleRace * fenNouvelleRace= new FenetreNouvelleRace(ferme, moteur);
    FenetreNouvelElevage* fenNouvelElevage=new FenetreNouvelElevage(ferme, moteur, observer);
    FenetrePrincipale *fenPrincipale=new FenetrePrincipale(ferme, moteur, fenNouvelleRace, fenNouvelElevage);
    FenetrePremiereOuverture* feneteInit=new FenetrePremiereOuverture(ferme, moteur, fenPrincipale, observer);
        //feneteInit.show();
    fenNouvelElevage->setFenetrePrincipale(fenPrincipale);
    
    
    //fenPrincipale->addItemListeElevage("Elevage Limousines");

#ifdef MULTITHREAD    
    std::thread threadMoteur(&Moteur::execCommande, moteur);
    std::thread threadActualisationRendu(&EtatsObserver::actualiserRendu, observer);
#endif
    
    
    std::shared_ptr<CommandeAfficherFenetre> afficheFenetre = std::make_shared<CommandeAfficherFenetre>(ferme, feneteInit);
    moteur->ajouterCommande(afficheFenetre);

#ifndef MULTITHREAD   
    moteur->execCommande();
#endif    
    
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
