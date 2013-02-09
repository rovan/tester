#include "testsuit.h"
#include <QProcess>
#include <QProcessEnvironment>
#include <QDomDocument>
#include <QByteArray>
#include <QStringList>
#include <QDebug>

TTestSuit::TTestSuit(const QString& executable)
    : Executable(executable)
    , State(TTestSuit::Waiting)
{}

void TTestSuit::start(){
    Result.clear();
    State = TTestSuit::Running;
    emit started();

    QProcess process;
    process.setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    process.start(Executable, QStringList() << "-xunitxml");

    if (!process.waitForFinished(-1)){
        qDebug() << "Error executing" << Executable;
    }

    process.waitForReadyRead();
    ExecutionLog = process.readAllStandardOutput();

    TXmlError error;
    QDomDocument document;
    document.setContent(ExecutionLog, &error.Message, &error.Line, &error.Column);

    if(error.Message.isEmpty()){
        QDomElement root = document.firstChildElement("testsuit");
        for(QDomElement element = root.firstChildElement("testcase"); !element.isNull(); element = element.nextSiblingElement("testcase")){
            Result.append(TTestCase(element));

        }
    }else qDebug() << "Error reading xml report"
                   << error.Message
                   << error.Line
                   << error.Column;

    State = TTestSuit::Finished;
    emit finished();
}

TTestResult TTestSuit::result() const{
    return Result;
}

bool TTestSuit::isRunning() const{
    return State == TTestSuit::Running;
}

bool TTestSuit::isFinished() const{
    return State == TTestSuit::Finished;
}
