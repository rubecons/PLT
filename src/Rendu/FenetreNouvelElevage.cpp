/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FenetreNouvelElevage.h"
#include "moteur/CommandeNouvelElevage.h"
#include "Etats/Race.h"
#include <QComboBox>//
#include <iostream>
#include <QFormLayout>//
#include <QHBoxLayout>//
#include <QString>
#include <QLineEdit>//

#include <QVBoxLayout>//

namespace Rendu{

FenetreNouvelElevage::FenetreNouvelElevage()
{
    
}

FenetreNouvelElevage::FenetreNouvelElevage(std::shared_ptr<Etats::Ferme> frm, std::shared_ptr<moteur::Moteur> mot, std::shared_ptr<Etats::EtatsObserver> observ)
{
    ferme=frm;
    //temps=tps;
    moteu=mot;
    observer=observ;
    //fenetrePrincipale=fenPrin;
    
    this->setWindowTitle(QString("Nouvel Élevage"));
    
    this->setWindowIcon(QIcon("./rapport/taureau.png"));
    this->setWindowModality(Qt::WindowModal);
    
    QVBoxLayout* layoutVerticalNvlElevage=new QVBoxLayout(this);
    setLayout(layoutVerticalNvlElevage);
    
        QFormLayout* formulaireNouvelElevage= new QFormLayout;
        layoutVerticalNvlElevage->addLayout(formulaireNouvelElevage);
    
            QLineEdit* nomElevage= new QLineEdit;//("Nom de la race");
            formulaireNouvelElevage->addRow("Nom du nouvel élevage :", nomElevage);
            QObject::connect(nomElevage, SIGNAL(textChanged(const QString&)), this, SLOT(setNomElevage(const QString&)));
            
            QComboBox* selectionRace = new QComboBox(this);
            selectionRace->addItem("Choisir une race...");
            selectionRace->addItem("Nouvelle race");
            for(auto r : ferme->getRaces())
            {
                //std::cout<< r->getNomRace()<<std::endl;
                selectionRace->addItem((r->getNomRace()).c_str());
            }
            formulaireNouvelElevage->addRow("Race élevée :", selectionRace);
            QObject::connect(selectionRace, SIGNAL(currentIndexChanged(int)), this, SLOT(setIndexRace(int)));
            
        QHBoxLayout* layoutBoutons = new QHBoxLayout;
        layoutVerticalNvlElevage->addLayout(layoutBoutons);
    
            QPushButton* boutonAnnuler =creationBoutonDansLayout("Annuler", this, layoutBoutons, SIGNAL(clicked()), this, SLOT(close()), true);
            QPushButton* boutonEnregistrerNouvelleRace=creationBoutonDansLayout("Créer un nouvel élevage", this, layoutBoutons, SIGNAL(clicked()), this, SLOT(enregistrerNouvelElevage ()), true);
    //setLayout(layoutVertical);
}

QPushButton* FenetreNouvelElevage::creationBoutonDansLayout(const QString &nom, QWidget* widgetParent, QLayout* layoutParent, const char* signal, QObject* receiver, const char* slot, bool enabled)
{
    QPushButton* bouton = new QPushButton(nom, widgetParent);
    bouton->setEnabled(enabled);
    layoutParent->addWidget(bouton);
    connect(bouton, signal, receiver, slot);
    
    return bouton;
}

FenetreNouvelElevage::~FenetreNouvelElevage()
{
    
}

void FenetreNouvelElevage::setFenetrePrincipale (FenetrePrincipale *fenPrin)
{
    fenetrePrincipale=fenPrin;
}

void FenetreNouvelElevage::enregistrerNouvelElevage ()
{
    std::cout<< "test : nomElevage : "<<nomElevage <<" RaceChoisie : "<< indexRace <<std::endl;
    /*switch(indexRace)
    {       
        case 0:
        {break;}
        case 1:
        {
            
            break;
        }
        default:
        {//*/
            std::shared_ptr<moteur::CommandeNouvelElevage> commandeNouvelElevage=std::make_shared<moteur::CommandeNouvelElevage>(nomElevage, ferme->getRaces()[indexRace-2],temps,ferme, observer, fenetrePrincipale);
            moteu->ajouterCommande(commandeNouvelElevage);
            
            moteu->execCommande();
            close();
            std::cout<< "fin slot "<<std::endl;
        /*
        }
    }//*/
}

void FenetreNouvelElevage::setNomElevage (const QString &nom)
{
    nomElevage=nom.toStdString();
}

void FenetreNouvelElevage::setIndexRace (int index)
{
    indexRace=index;
}

}