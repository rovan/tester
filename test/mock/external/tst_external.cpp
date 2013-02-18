#include <QString>
#include <QtTest>

#include <shared.h>

class TExternalTest : public QObject
{
    Q_OBJECT
    
public:
    TExternalTest();
    
private Q_SLOTS:
    void testCase1();
};

TExternalTest::TExternalTest()
{
}

void TExternalTest::testCase1()
{
    QVERIFY(External::trueValue());
}

QTEST_APPLESS_MAIN(TExternalTest)

#include "tst_external.moc"
