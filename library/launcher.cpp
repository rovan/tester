#include "launcher.h"
#include <QProcess>
#include <QFileInfo>

#include <QDebug>
namespace Tester{
namespace Kernel{

Launcher::Launcher(QObject *parent) :
    QObject(parent)
{
}

void Launcher::setExecutable(const QString& value){
    if(executable() != value){
        QFileInfo info(value);
        Directory = info.absolutePath();
        FileName = info.fileName();
    }
}

QString Launcher::executable() const{
    return Directory + "/" + FileName;
}

QStringList Launcher::arguments() const{
    return Arguments;
}

void Launcher::clearArguments(){
    Arguments.clear();
}

void Launcher::addArgument(const QString& argument){
    Arguments.append(argument);
}

void Launcher::run(){
    emit started();

    QProcess process;
    process.setWorkingDirectory(Directory);
    QProcessEnvironment environment = QProcessEnvironment::systemEnvironment();
    if(!Library.isEmpty()){
        QString path = environment.value("PATH");
        path.append(";"+ Library);
        environment.insert("PATH", path);
    }
    process.setProcessEnvironment(environment);
    process.start(executable(), Arguments);
    process.waitForFinished(-1);
    process.waitForReadyRead();

    const QString log = process.readAllStandardOutput();
    emit finished(log);
}

QString Launcher::fileName() const{
    return FileName;
}

QString Launcher::directory() const{
    return Directory;
}


QString Launcher::library() const{
    return Library;
}

void Launcher::setLibrary(const QString& value){
    Library = value;
}

}
}
