/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FenetreNouvelElevage.hpp"


FenetreNouvelElevage::FenetreNouvelElevage()
{
    this->setWindowTitle(QString("Nouvel Élevage"));
    
    this->setWindowIcon(QIcon("./rapport/taureau.png"));
    this->setWindowModality(Qt::WindowModal);
    
    QVBoxLayout* layoutVerticalNvlElevage=new QVBoxLayout(this);
    setLayout(layoutVerticalNvlElevage);
    
        QFormLayout* formulaireNouvelElevage= new QFormLayout;
        layoutVerticalNvlElevage->addLayout(formulaireNouvelElevage);
    
            QLineEdit* nomElevage= new QLineEdit;//("Nom de la race");
            formulaireNouvelElevage->addRow("Nom du nouvel élevage :", nomElevage);
            
            QComboBox* selectionRace = new QComboBox(this);
            selectionRace->addItem("Choisir une race...");
            selectionRace->addItem("Nouvelle race");
            selectionRace->addItem("elevage3");
            formulaireNouvelElevage->addRow("Race élevée :", selectionRace);
            
        QHBoxLayout* layoutBoutons = new QHBoxLayout;
        layoutVerticalNvlElevage->addLayout(layoutBoutons);
    
            QPushButton* boutonAnnuler =creationBoutonDansLayout("Annuler", this, layoutBoutons, SIGNAL(clicked()), this, SLOT(), true);
            QPushButton* boutonEnregistrerNouvelleRace=creationBoutonDansLayout("Créer un nouvel élevage", this, layoutBoutons, SIGNAL(clicked()), this, SLOT(), true);
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