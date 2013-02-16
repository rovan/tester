#ifndef LOGPROCESSOR_H
#define LOGPROCESSOR_H

#include <QObject>
#include <QDomDocument>

#include "library_global.h"

class QDataStream;

class TESTER_EXPORT TLogProcessor : public QObject
{
    Q_OBJECT
    Q_ENUMS(TestState)
public:
    enum TestState
       { Passed
       , Failed
       , Erroneous
       };
signals:
    void   logChanged(const QString& previous                 , const QString& current);
    void stateChanged(const TLogProcessor::TestState& previous, const TLogProcessor::TestState& current);

public:
    explicit TLogProcessor(QObject *parent = 0);

    QDomDocument document() const;
    QString      log()      const;

    TestState    state()    const;
public slots:
    void process(const QString& log);
private:
    TestState    State;
    QString      Log;
    QDomDocument Document;
};

QDataStream& operator<<(QDataStream& stream, const TLogProcessor::TestState& data);
QDataStream& operator>>(QDataStream& stream, TLogProcessor::TestState& data);

Q_DECLARE_METATYPE(TLogProcessor::TestState)

#endif // LOGPROCESSOR_H
