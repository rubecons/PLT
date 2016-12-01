/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FenetrePremiereOuverture.cpp
 * Author: ruben
 * 
 * Created on 6 novembre 2016, 05:02
 */
//#include "librairiesQt.hpp"
#include "FenetrePremiereOuverture.h"
#include "moteur/CommandeInitialiserFermeTemps.h"
#include "moteur/CommandeAfficherFenetre.h"
#include "moteur/Moteur.h"
//#include "moc_FenetrePremiereOuverture.cpp"
//#include "DbManager.hpp"
#include <QApplication>
#include <QComboBox>//
//#include <QDoubleSpinBox>
#include <QFormLayout>//
#include <QFrame>//
#include <QHBoxLayout>//
#include <QLabel>//
#include <QLineEdit>//
#include <QMessageBox>
#include <QObject>
//#include <QSpinBox>
#include <QVBoxLayout>//
#include <iostream>

namespace Rendu{

FenetrePremiereOuverture::FenetrePremiereOuverture()
{
    
}

FenetrePremiereOuverture::FenetrePremiereOuverture(std::shared_ptr<Etats::Ferme> frm, std::shared_ptr<Etats::Temps> tps, std::shared_ptr<moteur::Moteur> mot, FenetrePrincipale* fenPrin)
{
    ferme=frm;
    temps=tps;
    moteu=mot;
    fenetrePrincipale=fenPrin;
    //QSqlDatabase* dbConn) {
    this->setWindowTitle(QString("Initialisation"));
    
    this->setWindowIcon(QIcon("./rapport/taureau.png"));
    this->setWindowModality(Qt::WindowModal);
    
    //double budg;
    //double empru;
    
    
    QVBoxLayout* layoutVerticalPremiereOuverture=new QVBoxLayout(this);
    setLayout(layoutVerticalPremiereOuverture);
    
        QLabel* messageInfo = new QLabel ("Bienvenue dans votre gestionnaire d'élevages.\nVeuillez renseigner des premières informations sur votre exploitation :\n   Quel est le budget actuel de l'exploitation ?\n   Avez-vous effectué des empunts bancaires ? Si oui, préciser de combien.\n\n(ces informations ne vous seront plus demandées)", this);
        messageInfo->setFrameStyle(QFrame::Box | QFrame::Raised);
        layoutVerticalPremiereOuverture->addWidget(messageInfo);
                
        QFormLayout* formulaireCreationFerme= new QFormLayout;
        layoutVerticalPremiereOuverture->addLayout(formulaireCreationFerme);
    
            QLineEdit* budget= new QLineEdit();//("Nom de la race");
            budget->setValidator(validateur);
            //budget->setSingleStep(0.01);
            //budget->setSuffix(" €");
            formulaireCreationFerme->addRow("Budget actuel de l'exploitation (€):", budget);
            QObject::connect(budget, SIGNAL(textChanged(const QString&)), this, SLOT(setBudget(const QString&)));
            budget->setText("0");
            /*QComboBox* selectionEmprunts = new QComboBox(this);
            selectionEmprunts->addItem("Choisir");
            selectionEmprunts->addItem("Oui");
            selectionEmprunts->addItem("Non");
            f./Rendu/ormulaireCreationFerme->addRow("Avez-vous emprunté de l'argent ?", selectionEmprunts);
            //*/
            
            QLineEdit* emprunts= new QLineEdit();//("Nom de la race");
            emprunts->setValidator(validateur);
            QObject::connect(emprunts, SIGNAL(textChanged(const QString&)), this, SLOT(setEmprunts(const QString&)));
            emprunts->setText("0");
            //emprunts->setSingleStep(0.01);
            //emprunts->value(0.00);
            //emprunts->setSuffix(" €");
            formulaireCreationFerme->addRow("Argent déjà emprunté restant à rembourser (€):", emprunts);
            
            
        QHBoxLayout* layoutDate = new QHBoxLayout;
        layoutVerticalPremiereOuverture->addLayout(layoutDate);
            
            layoutDate->addWidget(new QLabel(tr("Date :")));
            QComboBox* mois = new QComboBox(this);mois->addItem("janvier");mois->addItem("fevrier");mois->addItem("mars");mois->addItem("avril");mois->addItem("mai");mois->addItem("juin");mois->addItem("juillet");mois->addItem("août");mois->addItem("septembre");mois->addItem("octobre");mois->addItem("novembre");mois->addItem("décembre");mois->setMaximumWidth(100);layoutDate->addWidget(mois);
            //mois->setCurrentIndex(0);
            QObject::connect(mois, SIGNAL(currentIndexChanged(int)), this, SLOT(setMois(int)));mois->setCurrentIndex(1);mois->setCurrentIndex(0);
            QLineEdit* annee = new QLineEdit();annee->setValidator(new QIntValidator(2016, 2050));annee->setMaxLength(4);annee->setMaximumWidth(100);layoutDate->addWidget(annee);
            QObject::connect(annee, SIGNAL(textChanged(const QString&)), this, SLOT(setAnnee(const QString&)));
            //*/
        QHBoxLayout* layoutBoutons = new QHBoxLayout;
        layoutVerticalPremiereOuverture->addLayout(layoutBoutons);
    
            QPushButton* boutonAnnuler =creationBoutonDansLayout("Annuler", this, layoutBoutons, SIGNAL(clicked()), this, SLOT(annulation()), true);
            //QPushButton* boutonAnnuler =creationBoutonDansLayout("Annuler", this, layoutBoutons, SIGNAL(clicked()), qApp, SLOT(quit()), true);
            QPushButton* boutonEnregistrerFerme=creationBoutonDansLayout("Enregistrer", this, layoutBoutons, SIGNAL(clicked()), this, SLOT(enregistrer()), true);// budget->text()->toDouble(), emprunts->text()->toDouble(), mois->currentIndex(), annee->text()->toInt())), true);

}

/*/FenetrePremiereOuverture::FenetrePremiereOuverture(const FenetrePremiereOuverture& orig) {
//}//*/

FenetrePremiereOuverture::~FenetrePremiereOuverture() {
    
}

QPushButton* FenetrePremiereOuverture::creationBoutonDansLayout(const QString &nom, QWidget* widgetParent, QLayout* layoutParent, const char* signal, QObject* receiver, const char* slot, bool enabled)
{
    QPushButton* bouton = new QPushButton(nom, widgetParent);
    bouton->setEnabled(enabled);
    layoutParent->addWidget(bouton);
    QObject::connect(bouton, signal, receiver, slot);
    
    return bouton;
}

double FenetrePremiereOuverture::getBudget()
{
    return budget;
}

double FenetrePremiereOuverture::getEmprunts()
{
    return emprunts;
}

void FenetrePremiereOuverture::setBudget(const QString &text)
{
    budget=text.toDouble();
}

void FenetrePremiereOuverture::setEmprunts(const QString &text)
{
    emprunts=text.toDouble();
    
}

void FenetrePremiereOuverture::setMois(int ms)
{
    mois=ms;
    
}

void FenetrePremiereOuverture::setAnnee(const QString &text)
{
    annee=text.toInt();
    
}


void FenetrePremiereOuverture::annulation()
{
    int reponse = QMessageBox::question(NULL, QObject::tr("Erreur"), QObject::tr("Impossible de lancer le gestionnaire d'élevage sans ces données.\n Quitter le logiciel ?"), QMessageBox:: Yes | QMessageBox:: No, QMessageBox::Yes);
    if (reponse==QMessageBox::Yes)
    {
        qApp->quit();
    }
}
//*/

void FenetrePremiereOuverture::enregistrer()///*DbManager* dbC,*/ double budg, double empr, int ms, int an)
{//std::cout<< "test : date : " << temps->getMois()+1 << "/"<<temps->getAnnee() <<" | ferme : Budget: "<< ferme->getBudget() <<" € | Emprunts:"<< ferme->getEmprunt()<<" €\n\n"<<std::endl;
    //this->budget=budg;
    //this->emprunts=empr;
//    this->enregistrerActif=true;
    if (budget>=0 && emprunts>=0)
    {
        //dbC->gererValeurs(this);//budget, emprunts);
        std::shared_ptr<moteur::CommandeAfficherFenetre> afficheFenetre = std::make_shared<moteur::CommandeAfficherFenetre>(ferme, temps, fenetrePrincipale);
        moteu->ajouterCommande(afficheFenetre);
        
        std::shared_ptr<moteur::CommandeInitialiserFermeTemps> initFrmTps = std::make_shared<moteur::CommandeInitialiserFermeTemps>(ferme, temps, budget, emprunts, mois, annee);
        moteu->ajouterCommande(initFrmTps);
        //moteu->execCommande(ferme, temps, fenetrePrincipale);
        //std::cout<< "date : " << temps->getMois()+1 << "/"<<temps->getAnnee() <<" | ferme : Budget: "<< ferme->getBudget() <<" € | Emprunts:"<< ferme->getEmprunt()<<" €\n\n"<<std::endl;
        //std::cout<<temps->getNomMois()[temps->getMois()]<<std::endl;
        this->close();
        
        //moteu->execCommande();
    }//*/
}




}