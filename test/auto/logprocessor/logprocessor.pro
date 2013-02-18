#-------------------------------------------------
#
# Project created by QtCreator 2013-02-10T19:30:12
#
#-------------------------------------------------

QT     += testlib xml
QT     -= gui

TARGET  = logprocessor
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH = ./../../../library/ \
              ./../../shared/

HEADERS += ./../../shared/shared.h

SOURCES += tst_logprocessor.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

DESTDIR  =   ./../../../output/tst/auto/
   LIBS += -L./../../../output/lib -ltester
