#include "viewmodel.h"
#include <QStandardItem>
#include <QColor>

#include "plan.h"
#include "suit.h"
#include <QDebug>

namespace Tester{
namespace Gui{

ViewModel::ViewModel(QObject *parent)
    : QStandardItemModel(parent)
    , Plan(NULL)
{
}


void ViewModel::setPlan(Tester::Kernel::Plan* value){
    if(Plan != value){
        if(Plan){
            Plan->disconnect(this);
            clear();
            ItemContainer.clear();
        }

        Plan = value;

        if(Plan){
            connect(Plan, &Tester::Kernel::Plan::finished, this, &ViewModel::updateState);
        }

        updateItems();
        updateState();
    }
}

void ViewModel::updateItems(){

    clear();
    ItemContainer.clear();
    if(Plan){
        Tester::Kernel::SuitCollection suits = Plan->suits();
        for(Tester::Kernel::SuitCollection::iterator suit = suits.begin(); suit != suits.end(); ++suit){
            QStandardItem* item = new QStandardItem((*suit)->name());
            item->setTextAlignment(Qt::AlignCenter);
            ItemContainer.insert(*suit, item);
            appendRow(item);
        }
    }
}

void ViewModel::updateState(){
    for(ItemCollection::iterator v = ItemContainer.begin(); v != ItemContainer.end(); ++v){
        Tester::Kernel::Suit* suit = v.key();
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
}
}
