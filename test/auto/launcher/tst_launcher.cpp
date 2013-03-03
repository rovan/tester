#include <QtTest>
#include <QString>
#include <QVariant>
#include <QSignalSpy>
#include <QDir>

#include <launcher.h>

#include <shared.h>

class TLauncherTest : public QObject
{
    Q_OBJECT
    
public:
    TLauncherTest();
    
private Q_SLOTS:
    void general_data();
    void general();
};

TLauncherTest::TLauncherTest()
{
}

void TLauncherTest::general_data()
{
    QTest::addColumn<QString>("executable");
    QTest::addColumn<QString>("argument");
    QTest::addColumn<QString>("library");
    QTest::addColumn<QString>("expected_report");

    QTest::newRow("erroneous")     << Shared::errorExecutable()   << "-xunitxml" << QString() << Shared::errorLog();
    QTest::newRow("failing")       << Shared::failingExecutable() << "-xunitxml" << QString() << Shared::failedLog();
    QTest::newRow("passing")       << Shared::passingExecutable() << "-xunitxml" << QString() << Shared::passedLog();
    QTest::newRow("wrong library") << Shared::libraryExecutable() << "-xunitxml" << QString() << QString();
    QDir path = QDir::current();
    path.setPath(Shared::libraryPath());
    QTest::newRow("right library") << Shared::libraryExecutable() << "-xunitxml" << path.canonicalPath() << Shared::libraryLog();
}

void TLauncherTest::general()
{
    QFETCH(QString, executable);
    QFETCH(QString, argument);
    QFETCH(QString, library);
    QFETCH(QString, expected_report);

    Tester::Kernel::Launcher launcher;
    launcher.setExecutable(executable);
    launcher.addArgument(argument);
    launcher.setLibrary(library);
    QSignalSpy started(&launcher , SIGNAL(started()));
    QSignalSpy finished(&launcher, SIGNAL(finished(const QString&)));
    launcher.run();
    QCOMPARE(started.count(), 1);

    QCOMPARE(finished.count(), 1);
    const QString actual_report = finished.takeFirst().at(0).toString();
    QCOMPARE(actual_report, expected_report);
}

QTEST_MAIN(TLauncherTest)

#include "tst_launcher.moc"
