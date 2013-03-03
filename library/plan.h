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

    QString path() const;
    QString library() const;
    QString name() const;

    Tester::Kernel::SuitCollection suits() const;
    QStringList executables() const;
    void scanPath();
signals:
    void finished();
public slots:
    void startSuits();
    void setPath(const QString& value);
    void setLibraryPath(const QString& value);
private:
    QString Path;
    QString Name;
    QString Library;
    Tester::Kernel::SuitCollection Suits;
};
}
}

#endif // TESTPLAN_H
