#ifndef TESTPLAN_H
#define TESTPLAN_H

#include <QObject>
#include <QString>
#include <QList>

#include "library_global.h"
#include "type.h"

namespace Tester{
namespace Kernel{

class TESTER_EXPORT Plan: public QObject
{
    Q_OBJECT
public:
    Plan(QObject* parent = 0);

    QString testPath() const;
    QString libraryPath() const;
    QString name() const;

    Tester::Kernel::SuitCollection suits() const;
    QStringList executables() const;
    void scanPath();

    Tester::Kernel::Suit* suit(const QString& name);
    const Tester::Kernel::Suit* suit(const QString& name) const;

signals:
    void finished();
public slots:
    void startSuits();
    void setTestPath(const QString& value);
    void setLibraryPath(const QString& value);
private:
    QString Name;
    QString TestPath;
    QString LibraryPath;
    Tester::Kernel::SuitCollection Suits;
};
}
}

#endif // TESTPLAN_H
