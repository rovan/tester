#ifndef LOGPROCESSOR_H
#define LOGPROCESSOR_H

#include <QObject>
#include <QDomDocument>

#include "library_global.h"

class QDataStream;

namespace Tester{
namespace Kernel{

class TESTER_EXPORT LogProcessor : public QObject
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
    void stateChanged(const Tester::Kernel::LogProcessor::TestState& previous, const Tester::Kernel::LogProcessor::TestState& current);

public:
    explicit LogProcessor(QObject *parent = 0);

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

}
}

QDataStream& operator<<(QDataStream& stream, const Tester::Kernel::LogProcessor::TestState& data);
QDataStream& operator>>(QDataStream& stream, Tester::Kernel::LogProcessor::TestState& data);

Q_DECLARE_METATYPE(Tester::Kernel::LogProcessor::TestState)

#endif // LOGPROCESSOR_H
