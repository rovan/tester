#include "testsuit.h"

#include "logprocessor.h"
#include "launcher.h"

TTestSuit::TTestSuit(QObject *parent)
    : QObject(parent)
    , LogProcessor(new TLogProcessor(this))
    , Launcher(new TLauncher(this))
{
    connect(Launcher, &TLauncher::finished, LogProcessor, &TLogProcessor::process);
    Launcher->addArgument("-xunitxml");
}

TTestSuit::~TTestSuit(){
    delete LogProcessor;
    LogProcessor = NULL;
    delete Launcher;
    Launcher = NULL;
}

void TTestSuit::start(){
    emit started();

    Launcher->run();

    emit finished();
}

bool TTestSuit::isPassed() const{
    return LogProcessor->state() == TLogProcessor::Passed;
}

bool TTestSuit::isFailed() const{
    return LogProcessor->state() == TLogProcessor::Failed;
}

bool TTestSuit::isErroneus() const{
    return LogProcessor->state() == TLogProcessor::Erroneous;
}


QString TTestSuit::log() const{
    return LogProcessor->log();
}

void TTestSuit::setExecutable(const QString& value){
    Launcher->setExecutable(value);
}

QString TTestSuit::name() const{
    if (Name.isNull())
      return Launcher->fileName();
    else
      return Name;
}

void TTestSuit::setName(const QString& value){
    Name = value;
}

void TTestSuit::setLibrary(const QString& value){
    Launcher->setLibrary(value);
}
