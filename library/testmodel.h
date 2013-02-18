#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QStandardItemModel>
#include <QHash>

#include "type.h"

class QStandardItemModel;

class TTestModel : public QStandardItemModel
{
    Q_OBJECT

    typedef QHash<TTestSuit*, QStandardItem*> ItemCollection;
public:
    explicit TTestModel(QObject *parent = 0);
    
    void setPlan(TTestPlan* value);
signals:
    
public slots:
    void updateItems();
    void updateState();
private:
    ItemCollection ItemContainer;
    TTestPlan*     Plan;
};

#endif // TESTMODEL_H
