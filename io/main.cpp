#include <QtCore/QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    qDebug() << "test output";

//    return a.exec();
    return 0;
}
