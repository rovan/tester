#include <QApplication>
#include <QDebug>

#include <planwidget.h>
#include <controller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Tester::Gui::Controller c;
    Tester::Gui::PlanWidget v;
    v.setController(&c);
    v.show();

    return a.exec();

}
