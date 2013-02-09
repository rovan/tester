#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QObject>

namespace test{

class TLauncher : public QObject
{
    Q_OBJECT
public:
    explicit TLauncher(QObject *parent = 0);
    
    void setExecutable(const QString& executable);
    QString executable() const;

    QStringList arguments() const;
    void clearArguments();
    void addArgument(const QString& argument);

    QString lastReport() const;

signals:
    void started();
    void finished(const QString& report);
public slots:
    void run();
private:
    QString Executable;
    QStringList Arguments;
    QString Report;
};

#endif // LAUNCHER_H
}
