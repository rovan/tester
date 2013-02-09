#-------------------------------------------------
#
# Project created by QtCreator 2013-01-30T21:10:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET  = demo
CONFIG += debug
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH = ./../library/

SOURCES += main.cpp

DESTDIR = ./../output/bin/
LIBS += -L./../output/lib -ltester
