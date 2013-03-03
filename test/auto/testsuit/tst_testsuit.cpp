#include <QtTest>
#include <QString>
#include <QSignalSpy>

#include <suit.h>

#include <shared.h>

class TTestSuitTest : public QObject
{
    Q_OBJECT
    
public:
    TTestSuitTest();
    
private Q_SLOTS:
    void general();
    void general_data();
};

TTestSuitTest::TTestSuitTest()
{
}

void TTestSuitTest::general_data(){
    QTest::addColumn<QString>("executable");
    QTest::addColumn<bool>("expected_passed");
    QTest::addColumn<bool>("expected_failed");
    QTest::addColumn<bool>("expected_erroneous");

    QTest::newRow("erroneous") << Shared::errorExecutable()   << false << false << true;
    QTest::newRow("failing")   << Shared::failingExecutable() << false << true  << false;
    QTest::newRow("passing")   << Shared::passingExecutable() << true  << false << false;
}

void TTestSuitTest::general()
{
    QFETCH(QString, executable);
    QFETCH(bool, expected_passed);
    QFETCH(bool, expected_failed);
    QFETCH(bool, expected_erroneous);

    Tester::Kernel::Suit suit(this);
    suit.setExecutable(executable);
    QSignalSpy started_spy(&suit, SIGNAL(started()));
    QSignalSpy finished_spy(&suit, SIGNAL(finished()));
    suit.start();

    QCOMPARE(started_spy.count(), 1);
    QCOMPARE(finished_spy.count(), 1);

    QCOMPARE(suit.isPassed(), expected_passed);
    QCOMPARE(suit.isFailed(), expected_failed);
    QCOMPARE(suit.isErroneus(), expected_erroneous);

}

QTEST_MAIN(TTestSuitTest)

#include "tst_testsuit.moc"
