#ifndef TESTPLANFORM_H
#define TESTPLANFORM_H

#include <QWidget>
#include "library_global.h"
#include "type.h"

namespace Ui{
    class PlanWidget;
}

namespace Tester{
namespace Gui{

class Controller;

class ViewModel;

class TESTER_EXPORT PlanWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlanWidget(QWidget* parent = 0);

    void setController(Tester::Gui::Controller* value);
signals:
protected slots:
    void showTestLog(const QString& test_name);
private:
    Ui::PlanWidget*          ui;
    QPointer<Tester::Gui::Controller> Controller;
};

}
}

#endif // TESTPLANFORM_H
