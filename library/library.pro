#-------------------------------------------------
#
# Project created by QtCreator 2013-01-30T00:05:11
#
#-------------------------------------------------

QT       += xml

TARGET = tester
TEMPLATE = lib

DEFINES += TESTER_LIBRARY

CONFIG += debug

SOURCES += library.cpp \
    parser.cpp \
    testsuit.cpp \
    testcase.cpp \
    testplan.cpp \
    launcher.cpp

HEADERS += library.h\
        library_global.h \
    parser.h \
    testsuit.h \
    testcase.h \
    testplan.h \
    launcher.h

DESTDIR = ./../output/lib/
