#-------------------------------------------------
#
# Project created by QtCreator 2013-01-30T21:10:23
#
#-------------------------------------------------

QT       += core widgets

TARGET  = demo

TEMPLATE = app

INCLUDEPATH = ./../library/

SOURCES += main.cpp

DESTDIR = ./../output/bin/
LIBS += -L./../output/lib -ltester
