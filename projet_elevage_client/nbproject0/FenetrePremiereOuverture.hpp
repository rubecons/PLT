/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FenetrePremiereOuverture.hpp
 * Author: ruben
 *
 * Created on 6 novembre 2016, 05:02
 */
#include "librairiesQt.hpp"

#ifndef FENETREPREMIEREOUVERTURE_HPP
#define FENETREPREMIEREOUVERTURE_HPP
#include "DbManager.hpp"
class FenetrePremiereOuverture : public QWidget{

    Q_OBJECT
public:
    FenetrePremiereOuverture();//DbManager* dbConn);
    //FenetrePremiereOuverture(const FenetrePremiereOuverture& orig);
    //virtual ~FenetrePremiereOuverture();
    QPushButton* creationBoutonDansLayout (const QString &nom, QWidget* widgetParent, QLayout* layoutParent, const char* signal, QObject* receiver, const char* slot, bool enabled);
    double getBudget();
    double getEmprunts();
public slots:
    void annulation();
    void enregistrer(DbManager* dbC, double budg, double empr);

private:
    QDoubleValidator* validateur=new QDoubleValidator(0, 1000000000, 2, this);
    double budget=-1;
    double emprunts=-1;
//    public:    bool enregistrerActif=false;
};

#endif /* FENETREPREMIEREOUVERTURE_HPP */

