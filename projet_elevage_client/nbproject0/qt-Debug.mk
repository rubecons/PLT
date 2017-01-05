#############################################################################
# Makefile for building: dist/Debug/GNU-Linux/projet_elevage
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /usr/lib/i386-linux-gnu/qt5/bin/qmake VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

MAKEFILE      = qttmp-Debug.mk

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_SQL_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -g -std=c++0x -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -Inbproject -I. -isystem /usr/include/i386-linux-gnu/qt5 -isystem /usr/include/i386-linux-gnu/qt5/QtWidgets -isystem /usr/include/i386-linux-gnu/qt5/QtGui -isystem /usr/include/i386-linux-gnu/qt5/QtSql -isystem /usr/include/i386-linux-gnu/qt5/QtCore -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/i386-linux-gnu/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = projet_elevage1.0.0
DISTDIR = /home/ruben/Documents/Ensea/3A/PLT/projet_elevage/build/Debug/GNU-Linux/projet_elevage1.0.0
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS) -lQt5Widgets -lQt5Gui -lQt5Sql -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = build/Debug/GNU-Linux/

####### Files

SOURCES       = src/Animal.cpp \
		src/DbManager.cpp \
		src/Elevage.cpp \
		src/FenetreNouvelElevage.cpp \
		src/FenetreNouvelleRace.cpp \
		src/FenetrePremiereOuverture.cpp \
		src/FenetrePrincipale.cpp \
		src/Race.cpp \
		src/Temps.cpp \
		src/main.cpp moc_FenetrePremiereOuverture.cpp
OBJECTS       = build/Debug/GNU-Linux/Animal.o \
		build/Debug/GNU-Linux/DbManager.o \
		build/Debug/GNU-Linux/Elevage.o \
		build/Debug/GNU-Linux/FenetreNouvelElevage.o \
		build/Debug/GNU-Linux/FenetreNouvelleRace.o \
		build/Debug/GNU-Linux/FenetrePremiereOuverture.o \
		build/Debug/GNU-Linux/FenetrePrincipale.o \
		build/Debug/GNU-Linux/Race.o \
		build/Debug/GNU-Linux/Temps.o \
		build/Debug/GNU-Linux/main.o \
		build/Debug/GNU-Linux/moc_FenetrePremiereOuverture.o
DIST          = /usr/lib/i386-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/c++11.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/lex.prf \
		nbproject/nbproject/qt-Debug.pro src/Animal.hpp \
		src/AnimalFemelle.hpp \
		src/AnimalMale.hpp \
		src/DbManager.hpp \
		src/Elevage.hpp \
		src/FenetreNouvelElevage.hpp \
		src/FenetreNouvelleBete.hpp \
		src/FenetreNouvelleRace.hpp \
		src/FenetrePremiereOuverture.hpp \
		src/FenetrePrincipale.hpp \
		src/Ferme.hpp \
		src/Race.hpp \
		src/Temps.hpp \
		src/librairiesQt.hpp src/Animal.cpp \
		src/DbManager.cpp \
		src/Elevage.cpp \
		src/FenetreNouvelElevage.cpp \
		src/FenetreNouvelleRace.cpp \
		src/FenetrePremiereOuverture.cpp \
		src/FenetrePrincipale.cpp \
		src/Race.cpp \
		src/Temps.cpp \
		src/main.cpp
QMAKE_TARGET  = projet_elevage
DESTDIR       = dist/Debug/GNU-Linux/#avoid trailing-slash linebreak
TARGET        = dist/Debug/GNU-Linux/projet_elevage


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET):  $(OBJECTS)  
	@test -d dist/Debug/GNU-Linux/ || mkdir -p dist/Debug/GNU-Linux/
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

qttmp-Debug.mk: nbproject/qt-Debug.pro /usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/i386-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/c++11.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/i386-linux-gnu/qt5/mkspecs/features/lex.prf \
		nbproject/qt-Debug.pro \
		/usr/lib/i386-linux-gnu/libQt5Widgets.prl \
		/usr/lib/i386-linux-gnu/libQt5Gui.prl \
		/usr/lib/i386-linux-gnu/libQt5Sql.prl \
		/usr/lib/i386-linux-gnu/libQt5Core.prl
	$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/spec_post.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/c++11.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/i386-linux-gnu/qt5/mkspecs/features/lex.prf:
nbproject/qt-Debug.pro:
/usr/lib/i386-linux-gnu/libQt5Widgets.prl:
/usr/lib/i386-linux-gnu/libQt5Gui.prl:
/usr/lib/i386-linux-gnu/libQt5Sql.prl:
/usr/lib/i386-linux-gnu/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

qmake_all: FORCE


all: qttmp-Debug.mk $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents src/Animal.hpp src/AnimalFemelle.hpp src/AnimalMale.hpp src/DbManager.hpp src/Elevage.hpp src/FenetreNouvelElevage.hpp src/FenetreNouvelleBete.hpp src/FenetreNouvelleRace.hpp src/FenetrePremiereOuverture.hpp src/FenetrePrincipale.hpp src/Ferme.hpp src/Race.hpp src/Temps.hpp src/librairiesQt.hpp $(DISTDIR)/
	$(COPY_FILE) --parents src/Animal.cpp src/DbManager.cpp src/Elevage.cpp src/FenetreNouvelElevage.cpp src/FenetreNouvelleRace.cpp src/FenetrePremiereOuverture.cpp src/FenetrePrincipale.cpp src/Race.cpp src/Temps.cpp src/main.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Debug.mk


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: moc_FenetrePremiereOuverture.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_FenetrePremiereOuverture.cpp
moc_FenetrePremiereOuverture.cpp: src/librairiesQt.hpp \
		src/FenetrePrincipale.hpp \
		src/FenetreNouvelleRace.hpp \
		src/FenetreNouvelElevage.hpp \
		src/FenetreNouvelleBete.hpp \
		src/DbManager.hpp \
		src/FenetrePremiereOuverture.hpp \
		src/FenetrePremiereOuverture.hpp
	/usr/lib/i386-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -I/home/ruben/Documents/Ensea/3A/PLT/projet_elevage/nbproject -I/usr/include/i386-linux-gnu/qt5 -I/usr/include/i386-linux-gnu/qt5/QtWidgets -I/usr/include/i386-linux-gnu/qt5/QtGui -I/usr/include/i386-linux-gnu/qt5/QtSql -I/usr/include/i386-linux-gnu/qt5/QtCore -I. -I/usr/include/c++/5 -I/usr/include/i386-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/i686-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/i686-linux-gnu/5/include-fixed -I/usr/include/i386-linux-gnu -I/usr/include src/FenetrePremiereOuverture.hpp -o moc_FenetrePremiereOuverture.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

build/Debug/GNU-Linux/Animal.o: src/Animal.cpp src/Animal.hpp \
		src/librairiesQt.hpp \
		src/FenetrePrincipale.hpp \
		src/FenetreNouvelleRace.hpp \
		src/FenetreNouvelElevage.hpp \
		src/FenetreNouvelleBete.hpp \
		src/Elevage.hpp \
		src/Race.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/Animal.o src/Animal.cpp

build/Debug/GNU-Linux/DbManager.o: src/DbManager.cpp src/DbManager.hpp \
		src/librairiesQt.hpp \
		src/FenetrePrincipale.hpp \
		src/FenetreNouvelleRace.hpp \
		src/FenetreNouvelElevage.hpp \
		src/FenetreNouvelleBete.hpp \
		src/FenetrePremiereOuverture.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/DbManager.o src/DbManager.cpp

build/Debug/GNU-Linux/Elevage.o: src/Elevage.cpp src/Elevage.hpp \
		src/librairiesQt.hpp \
		src/FenetrePrincipale.hpp \
		src/FenetreNouvelleRace.hpp \
		src/FenetreNouvelElevage.hpp \
		src/FenetreNouvelleBete.hpp \
		src/Race.hpp \
		src/Animal.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/Elevage.o src/Elevage.cpp

build/Debug/GNU-Linux/FenetreNouvelElevage.o: src/FenetreNouvelElevage.cpp src/FenetreNouvelElevage.hpp \
		src/librairiesQt.hpp \
		src/FenetrePrincipale.hpp \
		src/FenetreNouvelleRace.hpp \
		src/FenetreNouvelleBete.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/FenetreNouvelElevage.o src/FenetreNouvelElevage.cpp

build/Debug/GNU-Linux/FenetreNouvelleRace.o: src/FenetreNouvelleRace.cpp src/FenetreNouvelleRace.hpp \
		src/librairiesQt.hpp \
		src/FenetrePrincipale.hpp \
		src/FenetreNouvelElevage.hpp \
		src/FenetreNouvelleBete.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/FenetreNouvelleRace.o src/FenetreNouvelleRace.cpp

build/Debug/GNU-Linux/FenetrePremiereOuverture.o: src/FenetrePremiereOuverture.cpp src/librairiesQt.hpp \
		src/FenetrePrincipale.hpp \
		src/FenetreNouvelleRace.hpp \
		src/FenetreNouvelElevage.hpp \
		src/FenetreNouvelleBete.hpp \
		src/FenetrePremiereOuverture.hpp \
		src/DbManager.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/FenetrePremiereOuverture.o src/FenetrePremiereOuverture.cpp

build/Debug/GNU-Linux/FenetrePrincipale.o: src/FenetrePrincipale.cpp src/FenetrePrincipale.hpp \
		src/librairiesQt.hpp \
		src/FenetreNouvelleRace.hpp \
		src/FenetreNouvelElevage.hpp \
		src/FenetreNouvelleBete.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/FenetrePrincipale.o src/FenetrePrincipale.cpp

build/Debug/GNU-Linux/Race.o: src/Race.cpp src/Race.hpp \
		src/librairiesQt.hpp \
		src/FenetrePrincipale.hpp \
		src/FenetreNouvelleRace.hpp \
		src/FenetreNouvelElevage.hpp \
		src/FenetreNouvelleBete.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/Race.o src/Race.cpp

build/Debug/GNU-Linux/Temps.o: src/Temps.cpp src/Temps.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/Temps.o src/Temps.cpp

build/Debug/GNU-Linux/main.o: src/main.cpp src/librairiesQt.hpp \
		src/FenetrePrincipale.hpp \
		src/FenetreNouvelleRace.hpp \
		src/FenetreNouvelElevage.hpp \
		src/FenetreNouvelleBete.hpp \
		src/DbManager.hpp \
		src/FenetrePremiereOuverture.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/main.o src/main.cpp

build/Debug/GNU-Linux/moc_FenetrePremiereOuverture.o: moc_FenetrePremiereOuverture.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux/moc_FenetrePremiereOuverture.o moc_FenetrePremiereOuverture.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

