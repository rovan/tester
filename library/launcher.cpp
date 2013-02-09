#include "launcher.h"
namespace test{

TLauncher::TLauncher(QObject *parent) :
    QObject(parent)
{
}

void TLauncher::setExecutable(const QString& executable){

}

QString TLauncher::executable() const{

}

QStringList TLauncher::arguments() const{

}
void TLauncher::clearArguments(){

}

void TLauncher::addArgument(const QString& argument){

}

QString TLauncher::lastReport() const{

}

}
