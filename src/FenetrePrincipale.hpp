/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FenetrePrincipale.hpp
 * Author: ruben
 *
 * Created on 20 octobre 2016, 01:27
 */
#include "./src/librairiesQt.hpp"

#ifndef FENETREPRINCIPALE_HPP
#define FENETREPRINCIPALE_HPP

class FenetrePrincipale : public QMainWindow {
public:
    FenetrePrincipale();
    //FenetrePrincipale(const FenetrePrincipale& orig);
    //virtual ~FenetrePrincipale();

private:
    void creationMenuBar();
    void creationStatusBar();
    QMenu* creationMenu(QMenu *menuPere, const QString &nomMenuFils);
    //void creationMenu(QMenu *menuPere, QMenu *menuFils, const QString &nomMenuFils);
    QAction* creationActionDansMenu(QMenu *menuPere, const QString &nomAction, QObject* parent, const QKeySequence &shortcut, const char *signal, const QObject* receiver, const char* method);
    QAction* creationActionDansMenu(QMenu *menuPere, const QString &nomAction, QObject* parent, const char *signal, const QObject* receiver, const char* method);
    void creationZoneCentrale();
    //QListWidgetItem* creationListWidgetItem(QListWidget* listeParent, const QString &nomItem);
    void creationElevage(const QString &nom,QListWidget* listeParent , QStackedLayout* stackedLayout);
    
};

#endif /* FENETREPRINCIPALE_HPP */

