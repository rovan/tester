#include "testmodel.h"
#include <QStandardItem>
#include <QColor>

#include "testplan.h"
#include "testsuit.h"
#include <QDebug>

TTestModel::TTestModel(QObject *parent)
    : QStandardItemModel(parent)
    , Plan(NULL)
{
}


void TTestModel::setPlan(TTestPlan *value){
    if(Plan != value){
        if(Plan){
            Plan->disconnect(this);
            clear();
            ItemContainer.clear();
        }

        Plan = value;

        if(Plan){
            connect(Plan, &TTestPlan::finished, this, &TTestModel::updateState);
        }

        updateItems();
        updateState();
    }
}

void TTestModel::updateItems(){

    clear();
    ItemContainer.clear();
    if(Plan){
        TTestSuitCollection suits = Plan->suits();
        for(TTestSuitCollection::iterator suit = suits.begin(); suit != suits.end(); ++suit){
            QStandardItem* item = new QStandardItem((*suit)->name());
            item->setTextAlignment(Qt::AlignCenter);
            ItemContainer.insert(*suit, item);
            appendRow(item);
        }
    }
}

void TTestModel::updateState(){
    for(ItemCollection::iterator v = ItemContainer.begin(); v != ItemContainer.end(); ++v){
        TTestSuit* suit = v.key();
        QStandardItem* item = v.value();
        qDebug() << suit->log();
        if(suit->isErroneus()){
            item->setData(QColor("yellow"), Qt::BackgroundColorRole);
        }else if(suit->isFailed()){
            item->setData(QColor("tomato"), Qt::BackgroundColorRole);
        }else if(suit->isPassed()){
            item->setData(QColor("yellowgreen"), Qt::BackgroundColorRole);
        }
    }
}
