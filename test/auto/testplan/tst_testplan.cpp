#include <QtTest>
#include <QString>
#include <QStringList>

#include <testplan.h>
#include <testsuit.h>
#include <shared.h>
/*
bool operator==(const QStringList& left, const QStringList& right){
    bool result = left.size() == right.size();

    if(result){
        for(int i = 0; i < left.size(); ++i){
            result = result && right.contains(left.at(i));
        }
        for(int i = 0; i < right.size(); ++i){
            result = result && left.contains(left.at(i));
        }
    }

    return result;
}
*/
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

    TTestPlan plan(this);
    plan.setPath(test_path);

    QCOMPARE(plan.executables(), expected_executables);
}

void TTestPlanTest::general_data(){
    QTest::addColumn<QString>("test_path");
    QTest::addColumn<QStringList>("expected_executables");

    QStringList list;
    list << "external.exe" << "failing.exe" << "passing.exe";
    QTest::newRow("empty path")  << Shared::noTestPath()      << QStringList();
    QTest::newRow("filled path") << Shared::existedTestPath() << list;
}

QTEST_APPLESS_MAIN(TTestPlanTest)

#include "tst_testplan.moc"
