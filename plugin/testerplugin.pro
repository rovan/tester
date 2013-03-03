TARGET = TesterPlugin
TEMPLATE = lib

QT       += xml widgets

DEFINES += TESTERPLUGIN_LIBRARY

# TesterPlugin files

SOURCES += \
    testerplugin.cpp \
    monitoringviewfactory.cpp \
    testermode.cpp

HEADERS +=\
        testerplugin_global.h\
        testerpluginconstants.h \
        testerplugin.h \
    monitoringviewfactory.h \
    testermode.h

# Qt Creator linking

## set the QTC_SOURCE environment variable to override the setting here
QTCREATOR_SOURCES = $$(QTC_SOURCE)
isEmpty(QTCREATOR_SOURCES):QTCREATOR_SOURCES=D:/project/qt-creator

## set the QTC_BUILD environment variable to override the setting here
IDE_BUILD_TREE = $$(QTC_BUILD)
isEmpty(IDE_BUILD_TREE):CONFIG(debug, debug|release):IDE_BUILD_TREE=D:/project/build/qtcreator-build-Desktop_Qt_5_0_1_MinGW_32bit-Debug
isEmpty(IDE_BUILD_TREE):CONFIG(release, debug|release):IDE_BUILD_TREE=D:/project/build/qtcreator-build-Desktop_Qt_5_0_1_MinGW_32bit-Release

## uncomment to build plugin into user config directory
## <localappdata>/plugins/<ideversion>
##    where <localappdata> is e.g.
##    "%LOCALAPPDATA%\QtProject\qtcreator" on Windows Vista and later
##    "$XDG_DATA_HOME/data/QtProject/qtcreator" or "~/.local/share/data/QtProject/qtcreator" on Linux
##    "~/Library/Application Support/QtProject/Qt Creator" on Mac
# USE_USER_DESTDIR = yes

PROVIDER = drake

include($$QTCREATOR_SOURCES/src/qtcreatorplugin.pri)
include($$QTCREATOR_SOURCES/src/plugins/coreplugin/coreplugin.pri)

LIBS += -L$$IDE_PLUGIN_PATH/QtProject
LIBS += -L./../output/lib -ltester
