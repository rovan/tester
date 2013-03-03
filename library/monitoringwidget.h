#ifndef MONITORINGWIDGET_H
#define MONITORINGWIDGET_H

#include <QWidget>

#include "library_global.h"

namespace Ui{
    class MonitoringWidget;
}

namespace Tester{
namespace Gui{

class Controller;

class TESTER_EXPORT MonitoringWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MonitoringWidget(QWidget* parent = 0);
    ~MonitoringWidget();

    void setController(const Tester::Gui::Controller* value);
signals:
    void currentTest(const QString& name);
protected slots:
    void processActivation(const QModelIndex& index);
private:
    Ui::MonitoringWidget* ui;
};

}
}


#endif // MONITORINGWIDGET_
