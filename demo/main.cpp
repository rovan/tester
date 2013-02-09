#include <QtCore/QCoreApplication>
#include <QDebug>
#include <testplan.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "D:\\project\\dataset\\debug\\tst\\auto\\dataset.exe";
    TTestPlan plan(path);
    TTestPlan p(path);
    TTestPlan l(path);

    return 0;

}
