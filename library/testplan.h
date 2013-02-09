#ifndef TESTPLAN_H
#define TESTPLAN_H

#include "library_global.h"
#include <QList>
#include <QString>

class TTestSuit;
typedef QList<TTestSuit*> TTestSuitCollection;

class TESTER_EXPORT TTestPlan
{
public:
    TTestPlan(const QString& path);
    ~TTestPlan();
    QString path() const;
    QString name() const;
    TTestSuitCollection suits() const;
    void startSuits();
private:
    QString Path;
    QString Name;
    TTestSuitCollection Suits;
};

#endif // TESTPLAN_H
