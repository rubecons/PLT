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

namespace Rendu{

FenetrePremiereOuverture::FenetrePremiereOuverture(){//QSqlDatabase* dbConn) {
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
    
            QLineEdit* budget= new QLineEdit("0");//("Nom de la race");
            budget->setValidator(validateur);
            //budget->setSingleStep(0.01);
            //budget->setSuffix(" €");
            formulaireCreationFerme->addRow("Budget actuel de l'exploitation (€):", budget);
            
            /*QComboBox* selectionEmprunts = new QComboBox(this);
            selectionEmprunts->addItem("Choisir");
            selectionEmprunts->addItem("Oui");
            selectionEmprunts->addItem("Non");
            f./Rendu/ormulaireCreationFerme->addRow("Avez-vous emprunté de l'argent ?", selectionEmprunts);
            //*/
            
            QLineEdit* emprunts= new QLineEdit("0");//("Nom de la race");
            emprunts->setValidator(validateur);
            //emprunts->setSingleStep(0.01);
            //emprunts->value(0.00);
            //emprunts->setSuffix(" €");
            formulaireCreationFerme->addRow("Argent déjà emprunté restant à rembourser (€):", emprunts);
            
            
        /*QHBoxLayout* layoutDate = new QHBoxLayout;
        layoutVerticalPremiereOuverture->addLayout(layoutDate);
            
            layoutDate->addWidget(new QLabel(tr("Date :")));
            QComboBox* mois = new QComboBox(this);mois->addItem("janvier");mois->addItem("fevrier");mois->addItem("mars");mois->addItem("avril");mois->addItem("mai");mois->addItem("juin");mois->addItem("juillet");mois->addItem("août");mois->addItem("septembre");mois->addItem("octobre");mois->addItem("novembre");mois->addItem("décembre");layoutDate->addWidget(mois);
            QLineEdit* annee = new QLineEdit();annee->setValidator(new QIntValidator(2016, 2050));layoutDate->addWidget(annee);
        //*/
        QHBoxLayout* layoutBoutons = new QHBoxLayout;
        layoutVerticalPremiereOuverture->addLayout(layoutBoutons);
    
            QPushButton* boutonAnnuler =creationBoutonDansLayout("Annuler", this, layoutBoutons, SIGNAL(clicked()), this, SLOT(annulation()), true);
            QPushButton* boutonEnregistrerFerme=creationBoutonDansLayout("Enregistrer", this, layoutBoutons, SIGNAL(clicked()), this, SLOT(enregistrer( budget->text()->toDouble, emprunts->text()->toDouble)), true);

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
    connect(bouton, signal, receiver, slot);
    
    return bouton;
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

void FenetrePremiereOuverture::enregistrer(/*DbManager* dbC,*/ double budg, double empr)
{
    this->budget=budg;
    this->emprunts=empr;
//    this->enregistrerActif=true;
    if (budget>=0 && emprunts>=0)
    {
        //dbC->gererValeurs(this);//budget, emprunts);
        this->close();
    }
}

double FenetrePremiereOuverture::getBudget()
{
    return budget;
}

double FenetrePremiereOuverture::getEmprunts()
{
    return emprunts;
}
/*double FenetrePremiereOuverture::recupValeurs()
{

    return ;
}*/
}