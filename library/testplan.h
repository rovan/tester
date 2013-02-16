#ifndef TESTPLAN_H
#define TESTPLAN_H

#include <QObject>
#include <QString>
#include <QList>

#include "library_global.h"
#include "type.h"

class TESTER_EXPORT TTestPlan: public QObject
{
    Q_OBJECT
public:
    TTestPlan(QObject* parent = 0);

    QString path() const;
    QString name() const;

    TTestSuitCollection suits() const;
    QStringList executables() const;
public slots:
    void startSuits();
    void setPath(const QString& value);
private:
    QString Path;
    QString Name;
    TTestSuitCollection Suits;
};

#endif // TESTPLAN_H
