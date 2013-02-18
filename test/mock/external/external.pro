#-------------------------------------------------
#
# Project created by QtCreator 2013-02-18T23:06:18
#
#-------------------------------------------------

QT       += testlib
QT       -= gui

TARGET   = external
CONFIG  += console
CONFIG  -= app_bundle

TEMPLATE = app

INCLUDEPATH = ./../../shared

SOURCES += tst_external.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

DESTDIR = ./../../../output/tst/mock
   LIBS += -L./../../../output/tst -lshared
