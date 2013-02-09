#include <QString>
#include <QtTest>

class TTestSuitTest : public QObject
{
    Q_OBJECT
    
public:
    TTestSuitTest();
    
private Q_SLOTS:
    void testCase1();
};

TTestSuitTest::TTestSuitTest()
{
}

void TTestSuitTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TTestSuitTest)

#include "tst_testsuit.moc"
