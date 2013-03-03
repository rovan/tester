#include "controller.h"
#include <QAction>
#include "plan.h"
#include "viewmodel.h"

namespace Tester{
namespace Gui{

Controller::Controller(QObject* parent)
    : QObject(parent)
    , Model(new Tester::Kernel::Plan(this))
    , ViewModel(new Tester::Gui::ViewModel(this))
    , StartAction(new QAction(this))

{
    ViewModel->setPlan(Model);
    StartAction->setText(tr("Start"));
    connect(StartAction.data(), SIGNAL(triggered()), Model.data(), SLOT(startSuits()));
}

QString Controller::libraryPath() const{
    return Model->library();
}

QString Controller::testPath() const{
    return Model->path();
}

void Controller::setLibraryPath(const QString& value){
    Model->setLibraryPath(value);
}

void Controller::setTestPath(const QString& value){
    Model->setPath(value);
    Model->scanPath();
    ViewModel->updateItems();
}

QAction* Controller::startAction() const{
    return StartAction;
}

QAbstractItemModel *Controller::viewModel() const{
    return ViewModel;
}
}
}
