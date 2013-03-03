#include <QtTest>
#include <QString>
#include <QStringList>

#include <plan.h>
#include <suit.h>
#include <shared.h>

class TTestPlanTest : public QObject
{
    Q_OBJECT
    
public:
    TTestPlanTest();
    
private Q_SLOTS:
    void general();
    void general_data();
};

TTestPlanTest::TTestPlanTest()
{
}

void TTestPlanTest::general(){
    QFETCH(QString, test_path);
    QFETCH(QStringList, expected_executables);
    QFETCH(QString, suit_name);
    QFETCH(bool, expected_suit_state);

    Tester::Kernel::Plan plan(this);
    plan.setTestPath(test_path);
    plan.scanPath();

    QCOMPARE(plan.suit(suit_name) != NULL, expected_suit_state);

    QCOMPARE(plan.executables(), expected_executables);
}

void TTestPlanTest::general_data(){
    QTest::addColumn<QString>("test_path");
    QTest::addColumn<QStringList>("expected_executables");
    QTest::addColumn<QString>("suit_name");
    QTest::addColumn<bool>("expected_suit_state");

    QStringList list;
    list << "external.exe" << "failing.exe" << "passing.exe";
    QTest::newRow("empty path")  << Shared::noTestPath()      << QStringList() << "passing.exe" << false;
    QTest::newRow("filled path") << Shared::existedTestPath() << list          << "passing.exe" << true;
}

QTEST_APPLESS_MAIN(TTestPlanTest)

#include "tst_testplan.moc"
