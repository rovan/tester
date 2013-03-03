#ifndef TESTSUIT_H
#define TESTSUIT_H

#include <QObject>
#include <QString>

#include "library_global.h"
#include "type.h"


namespace Tester{
namespace Kernel{

class TESTER_EXPORT Suit: public QObject
{
    Q_OBJECT

public:
    Suit(QObject* parent);
    ~Suit();
    QString executable() const;
    void setExecutable(const QString& value);

    QString name() const;
    void setName(const QString& value);

    void setLibrary(const QString& value);

    void start();

    bool isPassed()   const;
    bool isFailed()   const;
    bool isErroneus() const;

    QString log() const;

signals:
    void started();
    void finished();
private:
    Tester::Kernel::LogProcessor* LogProcessor;
    Tester::Kernel::Launcher*     Launcher;
    QString                     Name;
};

}
}
#endif // TESTSUIT_H
