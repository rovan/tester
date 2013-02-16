#include "launcher.h"
#include <QProcess>
#include <QFileInfo>

TLauncher::TLauncher(QObject *parent) :
    QObject(parent)
{
}

void TLauncher::setExecutable(const QString& value){
    if(executable() != value){
        QFileInfo info(value);
        Directory = info.absolutePath();
        FileName = info.fileName();
    }
}

QString TLauncher::executable() const{
    return Directory + "/" + FileName;
}

QStringList TLauncher::arguments() const{
    return Arguments;
}

void TLauncher::clearArguments(){
    Arguments.clear();
}

void TLauncher::addArgument(const QString& argument){
    Arguments.append(argument);
}

void TLauncher::run(){
    emit started();

    QProcess process;
    process.setProcessEnvironment(QProcessEnvironment::systemEnvironment());
    process.start(executable(), Arguments);
    process.waitForFinished(-1);
    process.waitForReadyRead();

    const QString log = process.readAllStandardOutput();
    emit finished(log);
}

QString TLauncher::fileName() const{
    return FileName;
}

QString TLauncher::directory() const{
    return Directory;
}
