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
    //fenetre.setFixedSize(300, 200);
    setWindowTitle(QString("Élevage Numérique"));
    setGeometry(0,25,400,300);
    setWindowIcon(QIcon("./rapport/taureau.png"));
    
    
    /*ceci est la création de la menubar ave la facon de openclassrooms
    QMenu *menuFerme=menuBar() -> addMenu("Ferme");
    QMenu *menuBudget= menuBar() -> addMenu("Budget");
    QMenu *menuAide=menuBar() -> addMenu("Aide");  */
    
    QMenu *menuAide=new QMenu("&Aide");
    QMenu *menuBudget= new QMenu("&Budget");
    QMenu *menuFerme=new QMenu("&Ferme");
    
    //QMenuBar *barreMenu=new QMenuBar();
    menuBar()->addMenu(menuFerme);
    menuBar()->addMenu(menuBudget);
    menuBar()->addMenu(menuAide);
    /*QMenuBar *barreMenu=new QMenuBar();
    barreMenu->addMenu(menuFerme);
    barreMenu->addMenu(menuBudget);
    barreMenu->addMenu(menuAide);//*/
    
        QAction *actionNouvelElevage=new QAction ("Nouvel Élevage", this);
        QAction *actionNouvelleRace=new QAction ("Nouvelle Race", this);
        QAction *actionNouvelleBete=new QAction ("Nouvelle Bête", this);
    
        actionNouvelElevage->setShortcut(QKeySequence("Ctrl+E"));
        actionNouvelleRace->setShortcut(QKeySequence("Ctrl+R"));
        actionNouvelleBete->setShortcut(QKeySequence("Ctrl+B"));
        
    QMenu *actionNouveau = new QMenu ("Nouveau");
        //actionNouveau->addAction(actionNouvelElevage);
        
    
    QAction *actionEnregistrer = new QAction ("Enregistrer", this);
    QAction *actionStatistiqueFerme = new QAction ("Statistiques de la Ferme", this);
    
    //actionNouveau->setShortcut(QKeySequence("Ctrl+N"));
    actionEnregistrer->setShortcut(QKeySequence("Ctrl+S"));
    actionStatistiqueFerme->setShortcut(QKeySequence("Ctrl+F"));
    
    menuFerme->addMenu(actionNouveau);
    menuFerme->addAction(actionEnregistrer);
    menuFerme->addAction(actionStatistiqueFerme);
    
    QAction *actionEmprunter = new QAction ("Emprunter", this);
    menuBudget->addAction(actionEmprunter);
    
    
    
    QAction *boutonQuit= new QAction("Quitter", this);
    menuAide->addAction(boutonQuit);
    
            
    /*QPushButton *boutonQuit =new QPushButton("Quitter",this);
    boutonQuit->move(30, 30);*/
    QObject::connect (boutonQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
}
/*
FenetrePrincipale::FenetrePrincipale(const FenetrePrincipale& orig) {
}

FenetrePrincipale::~FenetrePrincipale() {
}
*/
