#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QObject>
#include <QString>
#include <QStringList>

#include "library_global.h"

class TESTER_EXPORT TLauncher : public QObject
{
    Q_OBJECT
public:
    explicit TLauncher(QObject *parent = 0);
    
    void setExecutable(const QString& value);

    QString library() const;
    void setLibrary(const QString& value);

    QString executable() const;
    QString directory() const;
    QString fileName() const;

    QStringList arguments() const;
    void addArgument(const QString& argument);
    void clearArguments();

    void run();

signals:
    void started();
    void finished(const QString& log);
private:
    QString Directory;
    QString FileName;
    QStringList Arguments;
    QString Library;
};

#endif // LAUNCHER_H
