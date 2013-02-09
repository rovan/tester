#ifndef TEST_H
#define TEST_H

#include "library_global.h"
#include "testcase.h"
#include <QString>
#include <QObject>

class TXmlError{
public:
    int Line;
    int Column;
    QString Message;
};

class TESTER_EXPORT TTestSuit: public QObject
{
    Q_OBJECT

    enum SuitState
       { Waiting
       , Running
       , Finished
       };

public:
    TTestSuit(const QString& executable);

    void start();

    TTestResult result() const;

    bool isRunning() const;
    bool isFinished() const;
signals:
    void started();
    void finished();
private:
    QString Executable;
    TTestResult Result;
    QString ExecutionLog;
    SuitState State;
};

#endif // TEST_H
