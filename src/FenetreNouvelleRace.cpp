/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FenetreNouvelleRace.hpp"
#define DISTINCTIONMALEFEMELLE
FenetreNouvelleRace::FenetreNouvelleRace()
{
    //QWidget* fenetreNouvRace = new QWidget;
    this->setWindowTitle(QString("Nouvelle Race"));
    //setGeometry(0, 25, 800, 450);
    this->setWindowIcon(QIcon("./rapport/taureau.png"));
    this->setWindowModality(Qt::WindowModal);
    
    QVBoxLayout* layoutVertical= new QVBoxLayout(this);
    
    //*
        QFormLayout* formulaireNouvelleRace= new QFormLayout;
        layoutVertical->addLayout(formulaireNouvelleRace);
    
            QLineEdit* nomRace= new QLineEdit;//("Nom de la race");
            formulaireNouvelleRace->addRow("Nom de la race", nomRace);
        
#ifndef DISTINCTIONMALEFEMELLE
            QSpinBox* esperanceVie= new QSpinBox;//("Nom de la race");
            formulaireNouvelleRace->addRow("Espérance de vie", esperanceVie);
            esperanceVie->setMaximum(840);
            esperanceVie->setSuffix(" mois");
        
            QSpinBox* poidsMoyenAdulte= new QSpinBox;//("Nom de la race");
            formulaireNouvelleRace->addRow("Poids Moyen d'un animal adulte", poidsMoyenAdulte);
            poidsMoyenAdulte->setMaximum(6000);
            poidsMoyenAdulte->setSuffix(" kg");
        
            QDoubleSpinBox* ageMoyenMaturite= new QDoubleSpinBox;//("Nom de la race");
            formulaireNouvelleRace->addRow("Âge moyen de la maturité", ageMoyenMaturite);
            ageMoyenMaturite->setMaximum(180);
            ageMoyenMaturite->setSingleStep(0.5);
            ageMoyenMaturite->setSuffix(" mois");
        
            QSpinBox* prixNourritureVeterinaire= new QSpinBox;//("Nom de la race");
            formulaireNouvelleRace->addRow("Prix mensuel alimentation+vétérinaire", prixNourritureVeterinaire);
            prixNourritureVeterinaire->setMaximum(6000);
            prixNourritureVeterinaire->setSuffix(" €/mois");
        
#else       
            QHBoxLayout* layoutHorizontalMaleFemelle=new QHBoxLayout;
            formulaireNouvelleRace->addRow(layoutHorizontalMaleFemelle);
            
                QVBoxLayout* layoutNomFormulaire = new QVBoxLayout;
                layoutHorizontalMaleFemelle->addLayout(layoutNomFormulaire);
                    QLabel* esperance=new QLabel("Espérance de vie :");
                    layoutNomFormulaire->addWidget(esperance);
                    QLabel*poids =new QLabel("Poids Moyen d'un animal adulte :");
                    layoutNomFormulaire->addWidget(poids);
                    QLabel* age=new QLabel("Âge moyen de la maturité :");
                    layoutNomFormulaire->addWidget(age);
                    QLabel* prix=new QLabel("Prix mensuel alimentation+vétérinaire :");
                    layoutNomFormulaire->addWidget(prix);
            
                QFormLayout* formulaireMale = new QFormLayout;
                layoutHorizontalMaleFemelle->addLayout(formulaireMale);
                
                    QSpinBox* esperanceVieMale= new QSpinBox;//("Nom de la race");
                    formulaireMale->addRow("Mâle", esperanceVieMale);
                    esperanceVieMale->setMaximum(840);
                    esperanceVieMale->setSuffix(" mois");
        
                    QSpinBox* poidsMoyenAdulteMale= new QSpinBox;//("Nom de la race");
                    formulaireMale->addRow("Mâle", poidsMoyenAdulteMale);
                    poidsMoyenAdulteMale->setMaximum(6000);
                    poidsMoyenAdulteMale->setSuffix(" kg");
        
                    QDoubleSpinBox* ageMoyenMaturiteMale= new QDoubleSpinBox;//("Nom de la race");
                    formulaireMale->addRow("Mâle", ageMoyenMaturiteMale);
                    ageMoyenMaturiteMale->setMaximum(180);
                    ageMoyenMaturiteMale->setSingleStep(0.5);
                    ageMoyenMaturiteMale->setSuffix(" mois");
        
                    QSpinBox* prixNourritureVeterinaireMale= new QSpinBox;//("Nom de la race");
                    formulaireMale->addRow("Mâle", prixNourritureVeterinaireMale);
                    prixNourritureVeterinaireMale->setMaximum(6000);
                    prixNourritureVeterinaireMale->setSuffix(" €/mois");
                
                QFormLayout* formulaireFemelle = new QFormLayout;
                layoutHorizontalMaleFemelle->addLayout(formulaireFemelle);
                
                    QSpinBox* esperanceVieFemelle= new QSpinBox;//("Nom de la race");
                    formulaireFemelle->addRow("Femelle", esperanceVieFemelle);
                    esperanceVieFemelle->setMaximum(840);
                    esperanceVieFemelle->setSuffix(" mois");
        
                    QSpinBox* poidsMoyenAdulteFemelle= new QSpinBox;//("Nom de la race");
                    formulaireFemelle->addRow("Femelle", poidsMoyenAdulteFemelle);
                    poidsMoyenAdulteFemelle->setMaximum(6000);
                    poidsMoyenAdulteFemelle->setSuffix(" kg");
        
                    QDoubleSpinBox* ageMoyenMaturiteFemelle= new QDoubleSpinBox;//("Nom de la race");
                    formulaireFemelle->addRow("Femelle", ageMoyenMaturiteFemelle);
                    ageMoyenMaturiteFemelle->setMaximum(180);
                    ageMoyenMaturiteFemelle->setSingleStep(0.5);
                    ageMoyenMaturiteFemelle->setSuffix(" mois");
        
                    QSpinBox* prixNourritureVeterinaireFemelle= new QSpinBox;//("Nom de la race");
                    formulaireFemelle->addRow("Femelle", prixNourritureVeterinaireFemelle);
                    prixNourritureVeterinaireFemelle->setMaximum(6000);
                    prixNourritureVeterinaireFemelle->setSuffix(" €/mois");
        
#endif    
        
            QSpinBox* dureeGestation= new QSpinBox;//("Nom de la race");
            formulaireNouvelleRace->addRow("Durée de la gestation", dureeGestation);
            dureeGestation->setMaximum(22);
            dureeGestation->setSuffix(" mois");
            
            QSpinBox* dureeEntre2Grossesses= new QSpinBox;//("Nom de la race");
            formulaireNouvelleRace->addRow("Durée minimale entre deux grossesses", dureeEntre2Grossesses);
            dureeEntre2Grossesses->setMaximum(36);
            dureeEntre2Grossesses->setSuffix(" mois");
        
            QSpinBox* nombreEnfantsPortee= new QSpinBox;//("Nom de la race");
            formulaireNouvelleRace->addRow("Nombre d'enfants par portée", nombreEnfantsPortee);
            nombreEnfantsPortee->setMaximum(15);
            nombreEnfantsPortee->setSuffix(" / portée");
        
            QDoubleSpinBox* prixVenteKilo= new QDoubleSpinBox;//("Nom de la race");
            formulaireNouvelleRace->addRow("Prix vente au Kg", prixVenteKilo);
            prixVenteKilo->setMaximum(30);
            prixVenteKilo->setSingleStep(0.01);
            prixVenteKilo->setSuffix(" €/kg");
            
            QSpinBox* nbGenerations= new QSpinBox;//("Nom de la race");
            formulaireNouvelleRace->addRow("Nombre de générations", nbGenerations);
            nbGenerations->setMaximum(6);
            nbGenerations->setToolTip("Nombre minimal de générations à partir duquel la présence d'un ancêtre commun entre deux individus peut crééer des maladies génétiques");
            nbGenerations->setSuffix(" générations");
        
        QHBoxLayout* layoutBoutons = new QHBoxLayout;
        layoutVertical->addLayout(layoutBoutons);
    
            QPushButton* boutonAnnuler =creationBoutonDansLayout("Annuler", this, layoutBoutons, SIGNAL(clicked()), this, SLOT(), true);
            QPushButton* boutonEnregistrerNouvelleRace=creationBoutonDansLayout("Enregistrer nouvelle race", this, layoutBoutons, SIGNAL(clicked()), this, SLOT(), true);
    setLayout(layoutVertical);
}

QPushButton* FenetreNouvelleRace::creationBoutonDansLayout(const QString &nom, QWidget* widgetParent, QLayout* layoutParent, const char* signal, QObject* receiver, const char* slot, bool enabled)
{
    QPushButton* bouton = new QPushButton(nom, widgetParent);
    bouton->setEnabled(enabled);
    layoutParent->addWidget(bouton);
    connect(bouton, signal, receiver, slot);
    
    return bouton;
}             
        
/*        
FenetreNouvelleRace::
FenetreNouvelleRace::
FenetreNouvelleRace::
FenetreNouvelleRace::
FenetreNouvelleRace::
FenetreNouvelleRace::
//*/