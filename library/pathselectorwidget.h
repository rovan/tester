#ifndef PATHSELECTORWIDGET_H
#define PATHSELECTORWIDGET_H

#include <QWidget>

namespace Ui{
    class PathSelectorWidget;
}

namespace Tester{
namespace Gui{

class PathSelectorWidget : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged USER true)
public:
    explicit PathSelectorWidget(QWidget *parent = 0);
    ~PathSelectorWidget();

    QString path() const;

    QString dialogTitle() const {return DialogTitle;}

    void selectPath();
signals:
    void pathChanged(const QString& value);
public slots:
    void setPath(const QString& value);
    void setDialogTitle(const QString& value) {DialogTitle = value;}
private:
    Ui::PathSelectorWidget* ui;
    QString DialogTitle;
};

}
}

#endif // PATHSELECTORWIDGET_H
