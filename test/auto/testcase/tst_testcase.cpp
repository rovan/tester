#include <QString>
#include <QtTest>

#include <testcase.h>
#include <QDomElement>

class TTestCaseTest : public QObject
{
    Q_OBJECT
    
public:
    TTestCaseTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void constructor();
    void copyConstructor();
    void xmlConstructor();
    void xmlConstructor_data();
};

TTestCaseTest::TTestCaseTest()
{
}

void TTestCaseTest::initTestCase()
{
}

void TTestCaseTest::cleanupTestCase()
{
}

void TTestCaseTest::constructor()
{
    QString name("name");
    TTestCase tc(name, TTestCase::Fail);
    QCOMPARE(tc.caseName(), name);
    QCOMPARE(tc.caseState(), TTestCase::Fail);
}

void TTestCaseTest::copyConstructor()
{
    QString name("name");
    TTestCase tc(name, TTestCase::Fail);
    TTestCase copy(tc);
    QCOMPARE(copy.caseName(), tc.caseName());
    QCOMPARE(copy.caseState(), tc.caseState());
}

void TTestCaseTest::xmlConstructor(){

}

void TTestCaseTest::xmlConstructor_data(){
    QTest::addColumn<QDomElement>("element");
    QTest::addColumn<QString>("expected_name");
    QTest::addColumn<int>("expexted_state");
    QTest::addColumn<int>("expected_failures");

    QString name;
    int expected_state(TTestCase::Undefined);
    int expected_failures(0);
    QTest::newRow("empty") << QDomElement() << name << expected_state << expected_failures;

    QDomElement pass;
    pass.setTagName("testcase");
    pass.setAttribute("name", "test");
    name = "test";
    expected_state = int(TTestCase::Pass);

    QTest::newRow("empty") << pass << name << expected_state << expected_failures;
}

QTEST_APPLESS_MAIN(TTestCaseTest)

#include "tst_testcase.moc"
