#include <QString>
#include <QtTest>

class TFailingTest : public QObject
{
    Q_OBJECT
    
public:
    TFailingTest();
    
private Q_SLOTS:
    void failingCase();
};

TFailingTest::TFailingTest()
{
}

void TFailingTest::failingCase()
{
    QVERIFY2(false, "Failure");
}

QTEST_APPLESS_MAIN(TFailingTest)

#include "tst_failing.moc"
