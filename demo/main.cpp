#include <QApplication>
#include <QDebug>

#include <testplanform.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TTestPlanForm form;
    form.show();

    return a.exec();

}
