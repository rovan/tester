#include "testplanform.h"

#include <QFileDialog>
#include <QStandardItemModel>

#include "testplan.h"
#include "testsuit.h"
#include "testmodel.h"

#include "ui_tester.h"

TTestPlanForm::TTestPlanForm(QWidget* parent)
    : QWidget(parent)
    , Plan(new TTestPlan)
    , UI(new Ui::TTestPlan)
    , TestModel(new TTestModel(this))
{
    TestModel->setPlan(Plan);
    UI->setupUi(this);
    UI->testPathSelector->setDefaultAction(UI->selectTestAction);
    UI->libraryPathSelector->setDefaultAction(UI->selectLibraryAction);
    UI->startTrigger->setDefaultAction(UI->startAction);
    UI->testView->setModel(TestModel);
    UI->testView->verticalHeader()->hide();
    UI->testView->horizontalHeader()->hide();

    connect(UI->startAction        , &QAction::triggered    , Plan, &TTestPlan::startSuits);
    connect(UI->selectTestAction   , &QAction::triggered    , this, &TTestPlanForm::selectTestPath);
    connect(UI->selectLibraryAction, &QAction::triggered    , this, &TTestPlanForm::selectLibraryPath);
    connect(UI->testPathEditor     , &QLineEdit::textChanged, Plan, &TTestPlan::setPath);
    connect(UI->libraryPathEditor  , &QLineEdit::textChanged, Plan, &TTestPlan::setLibraryPath);
}

void TTestPlanForm::selectTestPath(){

    processSelection(tr("Choose test directory"), UI->testPathEditor);
    TestModel->updateItems();
}

void TTestPlanForm::selectLibraryPath(){
    processSelection(tr("Choose library directory"), UI->libraryPathEditor);
}

void TTestPlanForm::processSelection(const QString& title, QLineEdit* editor){
    QFileDialog dialog(this, title);

    dialog.setFileMode(QFileDialog::Directory);
    if(dialog.exec() == QDialog::Accepted){
        editor->setText(dialog.selectedFiles().takeFirst());
    }
}
