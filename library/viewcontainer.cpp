#include "viewcontainer.h"
#include <QGraphicsGridLayout>
#include <QGraphicsScene>
#include <testview.h>

TViewContainer::TViewContainer()
    : QGraphicsWidget()
    , Layout(new QGraphicsGridLayout())
{
    Layout->setHorizontalSpacing(TViewSettings::Width + 15);
    Layout->setVerticalSpacing(TViewSettings::Height + 15);
    Layout->setContentsMargins(20, 20, 20, 20);
    setLayout(Layout);
}

TViewContainer::~TViewContainer(){

}

void TViewContainer::addItem(TTestView* item){
    if(item){
        Layout->addItem(item, 0, childItems().size());
        scene()->addItem(item);
    }
}

void TViewContainer::clear(){
    QList<QGraphicsItem*> items = childItems();

    for(QList<QGraphicsItem*>::iterator item = items.begin(); item != items.end();++item){
        delete *item;
    }

}
