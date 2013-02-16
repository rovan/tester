#include "testplanform.h"

#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsGridLayout>

#include "viewcontainer.h"
#include "testplan.h"
#include "testview.h"
#include "testsuit.h"

#include "ui_tester.h"

TTestPlanForm::TTestPlanForm(QWidget* parent)
    : QWidget(parent)
    , Plan(new TTestPlan)
    , UI(new Ui::TTestPlan)
{
    UI->setupUi(this);
    UI->pathSelector->setDefaultAction(UI->selectPathAction);
    UI->startTrigger->setDefaultAction(UI->startAction);
    UI->testView->setScene(new QGraphicsScene(this));

    ItemContainer = new TViewContainer();
    UI->testView->scene()->addItem(ItemContainer);
    ItemContainer->setPos(0,0);

    connect(UI->startAction     , &QAction::triggered, Plan.data(), &TTestPlan::startSuits);
    connect(UI->selectPathAction, &QAction::triggered, this, &TTestPlanForm::selectTestPath);
    connect(UI->pathEditor      , &QLineEdit::textChanged, Plan.data(), &TTestPlan::setPath);
}

void TTestPlanForm::selectTestPath(){
    QFileDialog dialog(this, tr("Choose test directory"));

    dialog.setFileMode(QFileDialog::Directory);
    if(dialog.exec() == QDialog::Accepted){
        UI->pathEditor->setText(dialog.selectedFiles().takeFirst());

        ItemContainer->clear();

        TTestSuitCollection suits = Plan->suits();

        for(TTestSuitCollection::iterator suit = suits.begin(); suit != suits.end(); ++suit){
            TTestView* view = new TTestView(suit->data(), ItemContainer);
            ItemContainer->addItem(view);
            view->setVisible(true);
        }
    }
}

TTestPlanForm::~TTestPlanForm(){

}
