#-------------------------------------------------
#
# Project created by QtCreator 2013-02-06T00:55:37
#
#-------------------------------------------------

QT     += testlib
QT     -= gui

TARGET  = testsuit
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH = ./../../../library \
              ./../../shared

SOURCES += \
    tst_testsuit.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

DESTDIR = ./../../../output/tst/auto/

LIBS += -L./../../../output/lib -ltester
