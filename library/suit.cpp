#include "suit.h"

#include "logprocessor.h"
#include "launcher.h"

namespace Tester{
namespace Kernel{

Suit::Suit(QObject *parent)
    : QObject(parent)
    , LogProcessor(new Tester::Kernel::LogProcessor(this))
    , Launcher(new Tester::Kernel::Launcher(this))
{
    connect(Launcher, &Tester::Kernel::Launcher::finished, LogProcessor, &Tester::Kernel::LogProcessor::process);
    Launcher->addArgument("-xunitxml");
}

Suit::~Suit(){
    delete LogProcessor;
    LogProcessor = NULL;
    delete Launcher;
    Launcher = NULL;
}

void Suit::start(){
    emit started();

    Launcher->run();

    emit finished();
}

bool Suit::isPassed() const{
    return LogProcessor->state() == Tester::Kernel::LogProcessor::Passed;
}

bool Suit::isFailed() const{
    return LogProcessor->state() == Tester::Kernel::LogProcessor::Failed;
}

bool Suit::isErroneus() const{
    return LogProcessor->state() == Tester::Kernel::LogProcessor::Erroneous;
}


QString Suit::log() const{
    return LogProcessor->log();
}

void Suit::setExecutable(const QString& value){
    Launcher->setExecutable(value);
}

QString Suit::name() const{
    if (Name.isNull())
      return Launcher->fileName();
    else
      return Name;
}

void Suit::setName(const QString& value){
    Name = value;
}

void Suit::setLibrary(const QString& value){
    Launcher->setLibrary(value);
}
}
}
