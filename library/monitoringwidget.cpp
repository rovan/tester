#include "monitoringwidget.h"
#include <QItemSelectionModel>
#include "controller.h"

#include "ui_MonitoringWidget.h"

namespace Tester{
namespace Gui{

MonitoringWidget::MonitoringWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MonitoringWidget)
{
    ui->setupUi(this);
    connect(ui->testView, &QListView::activated, this, &Tester::Gui::MonitoringWidget::processActivation);
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


void MonitoringWidget::processActivation(const QModelIndex& index){
    const QString current_test = ui->testView->model()->data(index).toString();
    emit currentTest(current_test);
}

}
}
