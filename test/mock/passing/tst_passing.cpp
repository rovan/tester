#include <QString>
#include <QtTest>

class TPassingTest : public QObject
{
    Q_OBJECT
    
public:
    TPassingTest();
    
private Q_SLOTS:
    void passingCase();
};

TPassingTest::TPassingTest()
{
}

void TPassingTest::passingCase()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TPassingTest)

#include "tst_passing.moc"
