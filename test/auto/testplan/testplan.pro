#-------------------------------------------------
#
# Project created by QtCreator 2013-02-06T00:49:41
#
#-------------------------------------------------

QT     += testlib
QT     -= gui

TARGET  = testplan
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH = ./../../../library/ \
              ./../../shared/

SOURCES += tst_testplan.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

DESTDIR  = ./../../../output/tst/auto/
   LIBS += -L./../../../output/lib -ltester
