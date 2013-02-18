#-------------------------------------------------
#
# Project created by QtCreator 2013-01-30T00:05:11
#
#-------------------------------------------------

QT       += xml widgets

TARGET = tester
TEMPLATE = lib

DEFINES += TESTER_LIBRARY

CONFIG += debug

SOURCES += \
    library.cpp \
    launcher.cpp \
    testplan.cpp \
    testsuit.cpp \
    logprocessor.cpp \
    testplanform.cpp \
    testmodel.cpp

HEADERS += \
    library.h\
    library_global.h \
    launcher.h \
    type.h \
    testsuit.h \
    testplan.h \
    logprocessor.h \
    testplanform.h \
    testmodel.h

DESTDIR = ./../output/lib/

FORMS += \
    tester.ui
