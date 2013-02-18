#-------------------------------------------------
#
# Project created by QtCreator 2013-02-09T22:17:12
#
#-------------------------------------------------

QT     += testlib
QT     -= gui

TARGET  = launcher
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH = ./../../../library \
              ./../../shared

HEADERS += ../../shared/shared.h

SOURCES += tst_launcher.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

DESTDIR  = ./../../../output/tst/auto/
   LIBS += -L./../../../output/lib -ltester
