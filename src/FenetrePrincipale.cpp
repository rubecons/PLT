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

#include "FenetrePrincipale.hpp"


FenetrePrincipale::FenetrePrincipale()
{
    //new QMainWindow;// fenetrePrincipale;
 
    // Configuration de la fenetre principale
    setWindowTitle(QString("Élevage Numérique"));
    setGeometry(0, 25, 800, 450);
    setWindowIcon(QIcon("./rapport/taureau.png"));

    creationMenuBar();
    creationStatusBar();
    creationZoneCentrale();
}

void FenetrePrincipale::creationMenuBar()
{

    //ici on créée les différents menus de la barre de menus, on fait appel aux fonctions qui crééent des sous-menus et des actions de menus
    QMenu* menuFerme=new QMenu("&Ferme");
    menuBar()->addMenu(menuFerme);
        QMenu* menuNouveau=creationMenu(menuFerme, ("Nouveau"));
            QAction* actionNouvelElevage=creationActionDansMenu(menuNouveau, "Nouvel Élevage", this, QKeySequence("Ctrl+E"), SIGNAL(triggered()), qApp, SLOT());
            QAction* actionNouvelleRace=creationActionDansMenu(menuNouveau, "Nouvelle Race", this, QKeySequence("Ctrl+R"), SIGNAL(triggered()), qApp, SLOT());
            QAction* actionNouvelleBete=creationActionDansMenu(menuNouveau, "Nouvelle Bête", this, QKeySequence("Ctrl+B"), SIGNAL(triggered()), qApp, SLOT());

        QAction* actionEnregistrer=creationActionDansMenu(menuFerme, "Enregistrer", this, QKeySequence("Ctrl+S"), SIGNAL(triggered()), qApp, SLOT());
        QAction* actionStatistiqueFerme=creationActionDansMenu(menuFerme, "Statistiques de la ferme", this, QKeySequence("Ctrl+F"), SIGNAL(triggered()), qApp, SLOT());

        
    QMenu* menuBudget= new QMenu("&Budget");
    menuBar()->addMenu(menuBudget);
        QAction *actionEmprunter=creationActionDansMenu(menuBudget, "Emprunter", this, SIGNAL(triggered()), qApp, SLOT());
    
    QMenu* menuAide=new QMenu("&Aide");
    menuBar()->addMenu(menuAide);//*/
    //QMenuBar *barreMenu=new QMenuBar();
    
    //ici on place les différents menus créés plus haut dans la menubar
    
    
    //*/
        QAction *actionQuitter=creationActionDansMenu(menuAide, "Quitter", this, SIGNAL(triggered()), qApp, SLOT(quit()));

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

void FenetrePrincipale::creationStatusBar()
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
    //*
    QLabel* texteStatusBar2= new QLabel(QString("mois année"), this, Qt::FramelessWindowHint);
    barreStatut -> addPermanentWidget (texteStatusBar2, 15);
    QLabel* texteStatusBar3= new QLabel(QString("Budget = 0 €"), this, Qt::FramelessWindowHint);
    barreStatut -> addPermanentWidget (texteStatusBar3, 15);//*/
    /*/QWidgetAction* actionStatusBar = new QWidgetAction(this);
    //actionStatus
    barreStatut -> addPermanentWidget (actionStatusBar, 15);
    connect(actionStatusBar, SIGNAL(triggered), qApp, SLOT(quit()));//*/
    
    //texteStatusBar -> move(50, 0);//*/
    
    //statusBar() -> addWidget(texteStatusBar, 80);
}

void FenetrePrincipale::creationZoneCentrale()
{
    QWidget* zoneCentrale = new QWidget;            //on créée un widget pour la zone centrale
    setCentralWidget(zoneCentrale);                 //on dit que la zone centrale est le wiget précedemment créé
    
    QHBoxLayout* layoutPrincipal= new QHBoxLayout;  //on créée un layout horizontal
    zoneCentrale->setLayout(layoutPrincipal);//*/   //on intègre le layout horizontal dans la zone centrale

        QVBoxLayout* layoutVerticalDeGauche= new QVBoxLayout;//on créée un layout vertical
        layoutPrincipal->addLayout(layoutVerticalDeGauche);//on ajoute le layout vertical en première position du layout horizontal
            QScrollArea* aireScrollListeElevage = new QScrollArea;//on créée une zone déroulante
            layoutVerticalDeGauche-> addWidget (aireScrollListeElevage);
            aireScrollListeElevage->setFixedWidth(150);
                QListWidget* listeElevage = new QListWidget(aireScrollListeElevage);//On créée la liste d'élevages
                aireScrollListeElevage->setWidget(listeElevage);//On intègre la liste d'élevages à la zone déroulante
                aireScrollListeElevage->setWidgetResizable(true);
                /*
                listeElevage -> addItem("elevage1");
                listeElevage -> addItem("elevage2");
                listeElevage -> addItem("elevage3");//*/
                
                
                //listeElevage->setFixedWidth(150);
                //
            
            //layoutVerticalDeGauche-> addWidget (listeElevage);//On intègre la zone déroulante en haut du layout verticale à gauche
            
            QPushButton* boutonAjouterElevage = new QPushButton(QString("Nouvel Élevage"), this);//On créée un bouton de nouvel élevage
            QObject::connect(boutonAjouterElevage, SIGNAL(clicked()), qApp, SLOT());
            layoutVerticalDeGauche->addWidget(boutonAjouterElevage);//On rajoute le bouton de nouvel élevage en 2eme position verticale du layout verticale de gauche
                    
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
        QStackedLayout *stackedLayout = new QStackedLayout(zoneCentrale);
        //aireScrollContenuElevage->setWidget(stackedLayout);
        layoutVerticalDeDroite->addLayout(stackedLayout);
        connect(listeElevage, SIGNAL(currentRowChanged(int)), stackedLayout, SLOT(setCurrentIndex(int)));
    
        QPushButton* boutonNouvelleBete= new QPushButton("Nouvel Animal", this);
        layoutVerticalDeDroite->addWidget(boutonNouvelleBete);
        connect(boutonNouvelleBete, SIGNAL(clicked()), qApp, SLOT());
    /*QLabel *elevage1 = new QLabel("page1");
    stackedLayout->addWidget(elevage1);
    
    QLabel *elevage2 = new QLabel("page2");
    stackedLayout->addWidget(elevage2);
    
    QLabel *elevage3 = new QLabel("page3");
    stackedLayout->addWidget(elevage3);*/
    
    creationElevage("elevage1",listeElevage ,stackedLayout);
    creationElevage("elevage2",listeElevage ,stackedLayout);
    creationElevage("elevage3",listeElevage ,stackedLayout);
    
    
   /* QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stackedLayout);
    zoneCentrale->setLayout(mainLayout);//*/
}

/*QWidget* */void FenetrePrincipale::creationElevage(const QString &nom,QListWidget* listeParent , QStackedLayout* stackedLayout)
{
    listeParent -> addItem(nom);
    QWidget *item= new QWidget;//(stackedLayout);//, this, QListWidgetItem::Type);
    stackedLayout -> addWidget(item);
    
    //return item;
}

/*
FenetrePrincipale::FenetrePrincipale(const FenetrePrincipale& orig) {
}

FenetrePrincipale::~FenetrePrincipale() {
}
*/
