/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FenetrePrincipale.cpp
 * Author: ruben
 * 
 * Created on 20 octobre 2016, 01:27
 */

#include "FenetrePrincipale.h"
#include <QApplication>
#include <QLabel>
#include <QScrollArea>
#include <QMenuBar>
#include <QString>
#include <iostream>
#include <QListView>
#include "moteur/CommandeAfficherFenetre.h"

namespace Rendu{

FenetrePrincipale::FenetrePrincipale()
{
    
}

FenetrePrincipale::FenetrePrincipale(std::shared_ptr<Etats::Ferme> frm, std::shared_ptr<moteur::Moteur> mot, FenetreNouvelleRace *fenNouvRace, FenetreNouvelElevage *fenNouvElevage)
{
    //QListWidget *
            listeElevage = new QListWidget(this);
    stackedLayout = new QStackedLayout(this);
    ferme=frm;
    //temps=tps;
    moteu=mot;
    fenetreNouvelleRace=fenNouvRace;
    fenetreNouvelElevage=fenNouvElevage;
    //new QMainWindow;// fenetrePrincipale;
 
    // Configuration de la fenetre principale
    setWindowTitle(QString("Élevage Numérique"));
    setGeometry(0, 25, 800, 450);
    setWindowIcon(QIcon("./rapport/taureau.png"));

    //QMenuBar* menuBarre=
    creationMenuBar();
    //creationToolBar();
    QStatusBar* barreStatus=creationStatusBar();
    creationZoneCentrale();
}

void FenetrePrincipale::creationMenuBar()
//QMenuBar* FenetrePrincipale::creationMenuBar()
{
    //QMenuBar* menuBarre=new QMenuBar;
    //ici on créée les différents menus de la barre de menus, on fait appel aux fonctions qui crééent des sous-menus et des actions de menus
    QMenu* menuFerme=new QMenu("&Ferme");
    //menuBarre->addMenu(menuFerme);
    menuBar()->addMenu(menuFerme);
        QMenu* menuNouveau=creationMenu(menuFerme, ("Nouveau"));
            QAction* actionNouvelElevage=creationActionDansMenu(menuNouveau, "Nouvel Élevage", this, QKeySequence("Ctrl+E"), SIGNAL(triggered()), qApp, SLOT());
            QAction* actionNouvelleRace=creationActionDansMenu(menuNouveau, "Nouvelle Race", this, QKeySequence("Ctrl+R"), SIGNAL(triggered()), qApp, SLOT());
            QAction* actionNouvelleBete=creationActionDansMenu(menuNouveau, "Nouvelle Bête", this, QKeySequence("Ctrl+B"), SIGNAL(triggered()), qApp, SLOT());

        QAction* actionEnregistrer=creationActionDansMenu(menuFerme, "Enregistrer", this, QKeySequence("Ctrl+S"), SIGNAL(triggered()), qApp, SLOT());
        QAction* actionStatistiqueFerme=creationActionDansMenu(menuFerme, "Statistiques de la ferme", this, QKeySequence("Ctrl+F"), SIGNAL(triggered()), qApp, SLOT());
        QAction* actionAvancerTemps=creationActionDansMenu(menuFerme, "Unité de temps suivante", this, QKeySequence("Enter"), SIGNAL(triggered()), qApp, SLOT());
        actionAvancerTemps->setIcon(QIcon("./rapport/ico_play_gris.png"));
        
    QMenu* menuBudget= new QMenu("&Budget");
    //menuBarre->addMenu(menuBudget);
    menuBar()->addMenu(menuBudget);
        QAction *actionEmprunter=creationActionDansMenu(menuBudget, "Emprunter", this, SIGNAL(triggered()), qApp, SLOT());
    
    QMenu* menuAide=new QMenu("&Aide");
    //menuBarre->addMenu(menuAide);
    menuBar()->addMenu(menuAide);//*/
    //QMenuBar *barreMenu=new QMenuBar();
    
    //ici on place les différents menus créés plus haut dans la menubar
   //*/
        QAction *actionQuitter=creationActionDansMenu(menuAide, "Quitter", this, SIGNAL(triggered()), qApp, SLOT(quit()));
   // return menuBarre;
}

QMenu* FenetrePrincipale::creationMenu(QMenu *menuPere, const QString &nomMenuFils)
{
    QMenu *menuFils = new QMenu(nomMenuFils);
    menuPere->addMenu(menuFils);
    
    return menuFils;
}

QAction* FenetrePrincipale::creationActionDansMenu(QMenu* menuPere, const QString &nomAction, QObject* parent,const QKeySequence &shortcut, const char *signal, const QObject* receiver, const char* method)
//QAction* /*void*/ FenetrePrincipale::creationActionDansMenu(QMenu* menuPere, QAction* action, const QString &nomAction, QObject* parent,const QKeySequence &shortcut, const char *signal, const QObject* receiver, const char* method)
{
    QAction *action= new QAction(nomAction, parent);
    action->setShortcut(shortcut);
    connect(action, signal, receiver, method);
    menuPere->addAction(action);
    
    return action;
}

QAction* FenetrePrincipale::creationActionDansMenu(QMenu *menuPere, const QString &nomAction, QObject* parent, const char *signal, const QObject* receiver, const char* method)
{
    QAction *action= new QAction(nomAction, parent);
    //action->setShortcut(shortcut);
    connect(action, signal, receiver, method);
    menuPere->addAction(action);
    
    return action;
}

QStatusBar* FenetrePrincipale::creationStatusBar()
{
    //QStatusBar* barreStatut = new QStatusBar(this);
    QStatusBar* barreStatut = this->statusBar();
    barreStatut -> setSizeGripEnabled(false);
    //QAction* actionStatistiqueFerme=creationActionDansMenu(barreStatut, "Budget = 0 €", this, SIGNAL(triggered()), qApp, SLOT());
    //QPushButton* boutonBudgetStatusBar=new QPushButton("Budget =0€");//<<ferme.budget<<"€"));
    //QAction* actionBudgetStatus
    //barreStatut -> addWidget( boutonBudgetStatusBar, 50);
    //barreStatut->showMessage(tr("Prêt.Prêt.Prêt.Prêt.Prêt.Prêt.Prêt."));
    QLabel* texteStatusBar= new QLabel(QString(" "), this, Qt::FramelessWindowHint);
    barreStatut -> addWidget (texteStatusBar,500);
    texteStatusBar->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    barreStatut -> addPermanentWidget (texteStatusBar2, 15);
    texteStatusBar2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    
    barreStatut -> addPermanentWidget (texteStatusBar3, 15);
    texteStatusBar3->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    /*/QWidgetAction* actionStatusBar = new QWidgetAction(this);
    //actionStatus
    barreStatut -> addPermanentWidget (actionStatusBar, 15);
    connect(actionStatusBar, SIGNAL(triggered), qApp, SLOT(quit()));//*/
    
    //texteStatusBar -> move(50, 0);//*/
    
    //statusBar() -> addWidget(texteStatusBar, 80);
    return barreStatut;
}

void FenetrePrincipale::creationZoneCentrale()
{
    QWidget* zoneCentrale = new QWidget;            //on créée un widget pour la zone centrale
    this->setCentralWidget(zoneCentrale);                 //on dit que la zone centrale est le wiget précedemment créé
    
    QHBoxLayout* layoutPrincipal= new QHBoxLayout;  //on créée un layout horizontal
    zoneCentrale->setLayout(layoutPrincipal);//*/   //on intègre le layout horizontal dans la zone centrale

        QVBoxLayout* layoutVerticalDeGauche= new QVBoxLayout;//on créée un layout vertical
        layoutPrincipal->addLayout(layoutVerticalDeGauche);//on ajoute le layout vertical en première position du layout horizontal
            QScrollArea* aireScrollListeElevage = new QScrollArea;//on créée une zone déroulante
            layoutVerticalDeGauche-> addWidget (aireScrollListeElevage);
            aireScrollListeElevage->setFixedWidth(150);
                //QListView* listeElevageView = new QListView();//aireScrollListeElevage);//On créée la liste d'élevages
                aireScrollListeElevage->setWidget(listeElevage);//On intègre la liste d'élevages à la zone déroulante
                aireScrollListeElevage->setWidgetResizable(true);
                /*
                listeElevage -> addItem("elevage1");
                listeElevage -> addItem("elevage2");
                listeElevage -> addItem("elevage3");//*/
        
            
            //layoutVerticalDeGauche-> addWidget (listeElevage);//On intègre la zone déroulante en haut du layout verticale à gauche
            QPushButton* boutonAjouterElevage=creationBoutonDansLayout("Nouvel Élevage", zoneCentrale, layoutVerticalDeGauche, SIGNAL(clicked()), this, SLOT(nouvelElevage()), true);
            
        //QScrollArea* aireScrollContenuElevage = new QScrollArea;//on créée une zone déroulante
        //layoutPrincipal -> addWidget(aireScrollContenuElevage);
    //zoneCentrale->
    
    /*
        QListWidgetItem* elevage1=creationListWidgetItem(listeElevage, "elevage1");
        QListWidgetItem* elevage2=creationListWidgetItem(listeElevage, "elevage2");
        QListWidgetItem* elevage3=creationListWidgetItem(listeElevage, "elevage3");
    //*/
        QVBoxLayout* layoutVerticalDeDroite= new QVBoxLayout;
        layoutPrincipal->addLayout(layoutVerticalDeDroite);
            //QStackedLayout *stackedLayout = new QStackedLayout(zoneCentrale);
            //aireScrollContenuElevage->setWidget(stackedLayout);
            layoutVerticalDeDroite->addLayout(stackedLayout);
            connect(listeElevage, SIGNAL(currentRowChanged(int)), stackedLayout, SLOT(setCurrentIndex(int)));
    
            QHBoxLayout* layoutHorizontalBasDroite= new QHBoxLayout;
            layoutVerticalDeDroite->addLayout(layoutHorizontalBasDroite);
                QPushButton* boutonSelectionner=creationBoutonDansLayout("Sélectionner", zoneCentrale, layoutHorizontalBasDroite, SIGNAL(clicked()), qApp, SLOT(), true);
                QPushButton* boutonAnnuler=creationBoutonDansLayout("Annuler", zoneCentrale, layoutHorizontalBasDroite, SIGNAL(clicked()), qApp, SLOT(), false);
                QPushButton* boutonSupprimerBete=creationBoutonDansLayout("Supprimer bête(s)", zoneCentrale, layoutHorizontalBasDroite, SIGNAL(clicked()), qApp, SLOT(), false);
                QPushButton* boutonNouvelleBete=creationBoutonDansLayout("Nouvelle(s) bête(s)", zoneCentrale, layoutHorizontalBasDroite, SIGNAL(clicked()), qApp, SLOT(), true);
                /*/
                QPushButton* boutonNouvelleBete= new QPushButton("Nouvel Animal", this);
                layoutVerticalDeDroite->addWidget(boutonNouvelleBete);
                connect(boutonNouvelleBete, SIGNAL(clicked()), qApp, SLOT());//*/
    /*QLabel *elevage1 = new QLabel("page1");
    stackedLayout->addWidget(elevage1);
    
    QLabel *elevage2 = new QLabel("page2");
    stackedLayout->addWidget(elevage2);
    
    QLabel *elevage3 = new QLabel("page3");
    stackedLayout->addWidget(elevage3);*/
    /*
    creationElevage("elevage1",listeElevage ,stackedLayout);
    creationElevage("elevage2",listeElevage ,stackedLayout);
    creationElevage("elevage3",listeElevage ,stackedLayout);//*/
    
    
   /* QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stackedLayout);
    zoneCentrale->setLayout(mainLayout);//*/
}

/*QWidget* */void FenetrePrincipale::addItemListeElevage(const std::string& nomElevage)
{
    
    std::cout<< "rajouter item liste elevage"<<std::endl;
    //QString nom(nomElevage.c_str());
    //const QString nom(nomElevage.c_str())
    //std::string *ptrNom = nomElevage.c_str();
    //std::cout<< nomElevage<<std::endl;
    //listeElevage ->addItem(nomElevage.c_str());
listeElevage->addItem(new QListWidgetItem(nomElevage.c_str(), listeElevage));
    std::cout<< "fin rajouter item liste elevage"<<std::endl;
    QLabel *item= new QLabel(nomElevage.c_str());//(stackedLayout);//, this, QListWidgetItem::Type);
    stackedLayout -> addWidget(item);
    
    //return item;
}
             
void FenetrePrincipale::addItemListeElevage(std::shared_ptr<Etats::Elevage> e)
{
    std::cout<< "rajouter item liste elevage"<<std::endl;
//listeElevage->addItem(e->getNomElevage().c_str());
    std::cout<< "fin rajouter item liste elevage"<<std::endl;

}

void FenetrePrincipale::addItemListeElevage()
{
    std::cout<< "rajouter item liste elevage"<<std::endl;
    for(auto& e : ferme->getElevages())
            {
                listeElevage ->addItem(e->getNomElevage().c_str());
                QCoreApplication::processEvents();
            }
    std::cout<< "fin rajouter item liste elevage"<<std::endl;

}

QPushButton* FenetrePrincipale::creationBoutonDansLayout(const QString &nom, QWidget* widgetParent, QLayout* layoutParent, const char* signal, QObject* receiver, const char* slot, bool enabled)
{
    QPushButton* bouton = new QPushButton(nom, widgetParent);
    bouton->setEnabled(enabled);
    layoutParent->addWidget(bouton);
    connect(bouton, signal, receiver, slot);
    
    return bouton;
}             
/*
void FenetrePrincipale::creationToolBar()
{
    QToolBar* barreDOutil=new QToolBar(this);
    barreDOutil->addAction(actionAvancerTemps);
    
}



/*
FenetrePrincipale::FenetrePrincipale(const FenetrePrincipale& orig) {
}
*/
FenetrePrincipale::~FenetrePrincipale()
{
}

void FenetrePrincipale::setTexteStatusBar2 (std::string texte)
{
    texteStatusBar2->clear();
    texteStatusBar2->setText(texte.c_str());
}

void FenetrePrincipale::setTexteStatusBar3 (std::string texte)
{
    texteStatusBar3->clear();
    texteStatusBar3->setText(texte.c_str());
}

void FenetrePrincipale::nouvelElevage ()
{
    std::shared_ptr<moteur::CommandeAfficherFenetre> afficheFenetre = std::make_shared<moteur::CommandeAfficherFenetre>(ferme, fenetreNouvelElevage);
    moteu->ajouterCommande(afficheFenetre);
    moteu->execCommande();
}

void FenetrePrincipale::clearListeElevage ()
{
    std::cout<< "nettoyage liste"<<std::endl;
    listeElevage->clearSelection();
    listeElevage->clearFocus();
    listeElevage->clear();
     std::cout<< "fin nettoyage liste"<<std::endl;
}

QListWidget* FenetrePrincipale::getListeElevage()
{
    return listeElevage;
}

}