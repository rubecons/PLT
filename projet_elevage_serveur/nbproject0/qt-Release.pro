# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux
TARGET = projet_elevage
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += src/Animal.cpp src/DbManager.cpp src/Elevage.cpp src/FenetreNouvelElevage.cpp src/FenetreNouvelleRace.cpp src/FenetrePremiereOuverture.cpp src/FenetrePrincipale.cpp src/Race.cpp src/Temps.cpp src/main.cpp
HEADERS += src/Animal.hpp src/AnimalFemelle.hpp src/AnimalMale.hpp src/DbManager.hpp src/Elevage.hpp src/FenetreNouvelElevage.hpp src/FenetreNouvelleBete.hpp src/FenetreNouvelleRace.hpp src/FenetrePremiereOuverture.hpp src/FenetrePrincipale.hpp src/Ferme.hpp src/Race.hpp src/Temps.hpp src/librairiesQt.hpp
FORMS +=
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
