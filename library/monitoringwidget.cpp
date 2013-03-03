#include "monitoringwidget.h"
#include "controller.h"

#include "ui_MonitoringWidget.h"

namespace Tester{
namespace Gui{

MonitoringWidget::MonitoringWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MonitoringWidget)
{
    ui->setupUi(this);
}

MonitoringWidget::~MonitoringWidget(){
    delete ui;
}

void MonitoringWidget::setController(const Tester::Gui::Controller* value){
    if(value){
        ui->testView->setModel(value->viewModel());
        ui->startButton->setDefaultAction(value->startAction());
    }
}

}
}
