#include <QString>
#include <QtTest>

class TTestPlanTest : public QObject
{
    Q_OBJECT
    
public:
    TTestPlanTest();
    
private Q_SLOTS:
    void testCase1();
};

TTestPlanTest::TTestPlanTest()
{
}

void TTestPlanTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TTestPlanTest)

#include "tst_testplan.moc"
