#include "planwidget.h"

#include <QStandardItemModel>

#include "viewmodel.h"
#include "controller.h"

#include "ui_planwidget.h"

namespace Tester{
namespace Gui{

PlanWidget::PlanWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::PlanWidget)
    , Controller(NULL)
{
    ui->setupUi(this);
}

void PlanWidget::setController(Tester::Gui::Controller* value){
    if(Controller != value){
        Controller = value;
        if(Controller){
            connect(ui->LibraryPathSelector, &Tester::Gui::PathSelectorWidget::pathChanged, Controller.data(), &Tester::Gui::Controller::setLibraryPath);
            connect(ui->TestPathSelector   , &Tester::Gui::PathSelectorWidget::pathChanged, Controller.data(), &Tester::Gui::Controller::setTestPath);

            ui->MonitoringView->setController(Controller);
        }
    }
}

}
}
