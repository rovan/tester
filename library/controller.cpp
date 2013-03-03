#include "controller.h"
#include <QAction>
#include "plan.h"
#include "suit.h"
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
    return Model->libraryPath();
}

QString Controller::testPath() const{
    return Model->testPath();
}

void Controller::setLibraryPath(const QString& value){
    Model->setLibraryPath(value);
}

void Controller::setTestPath(const QString& value){
    Model->setTestPath(value);
    Model->scanPath();
    ViewModel->updateItems();
}

QAction* Controller::startAction() const{
    return StartAction;
}

QAbstractItemModel* Controller::viewModel() const{
    return ViewModel;
}

QString Controller::suitLog(const QString& test_name) const{
    QString result;
    if(Tester::Kernel::Suit* suit = Model->suit(test_name)){
        result = suit->log();
    }
    return result;
}

}
}
