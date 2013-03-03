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
    logprocessor.cpp \
    monitoringwidget.cpp \
    plan.cpp \
    suit.cpp \
    viewmodel.cpp \
    pathselectorwidget.cpp \
    controller.cpp \
    planwidget.cpp

HEADERS += \
    library.h\
    library_global.h \
    launcher.h \
    type.h \
    logprocessor.h \
    monitoringwidget.h \
    suit.h \
    plan.h \
    viewmodel.h \
    pathselectorwidget.h \
    controller.h \
    planwidget.h

DESTDIR = ./../output/lib/

FORMS += \
    MonitoringWidget.ui \
    PathSelectorWidget.ui \
    PlanWidget.ui
