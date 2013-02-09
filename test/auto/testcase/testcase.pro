#-------------------------------------------------
#
# Project created by QtCreator 2013-02-06T00:48:50
#
#-------------------------------------------------

QT       += testlib xml

QT       -= gui

TARGET = tst_ttestcasetest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH = ./../../../library/

SOURCES += \
    tst_testcase.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

DESTDIR = ./../../../output/tst/auto/testcase
