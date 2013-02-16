#ifndef TESTSUIT_H
#define TESTSUIT_H

#include <QObject>
#include <QString>

#include "library_global.h"
#include "type.h"

class TESTER_EXPORT TTestSuit: public QObject
{
    Q_OBJECT

public:
    TTestSuit(QObject* parent);

    void setExecutable(const QString& value);
    QString name() const;
    void setName(const QString& value);
    void start();

    bool isPassed()   const;
    bool isFailed()   const;
    bool isErroneus() const;

    QString log() const;

signals:
    void started();
    void finished();
private:
    PLogProcessor LogProcessor;
    PLauncher Launcher;
    QString Name;
};

#endif // TESTSUIT_H
