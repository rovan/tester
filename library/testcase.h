#ifndef TESTCASE_H
#define TESTCASE_H

#include <QList>
#include <QHash>
#include <QString>
#include "library_global.h"

class QDomElement;

class TESTER_EXPORT TTestCase{
public:
    enum State
       { Undefined
       , Pass
       , Fail
       };

public:
    TTestCase(const QString case_name, const State& case_state);

    TTestCase(const QDomElement& element);

    TTestCase(const TTestCase& original);

    QHash<QString, QString> failedTags() const;
private:
    void addFailedTag(const QString& name, const QString& message);
private:
    QString CaseName;
    State   CaseState;
    QHash<QString, QString> FailedTags;
};

typedef QList<TTestCase> TTestResult;

#endif // TESTCASE_H
