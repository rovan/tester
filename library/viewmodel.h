#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QStandardItemModel>
#include <QHash>

#include "type.h"

#include "library_global.h"

class QStandardItemModel;

namespace Tester{
namespace Gui{

class TESTER_EXPORT ViewModel : public QStandardItemModel
{
    Q_OBJECT

    typedef QHash<Tester::Kernel::Suit*, QStandardItem*> ItemCollection;
public:
    explicit ViewModel(QObject *parent = 0);

    void setPlan(Tester::Kernel::Plan* value);
signals:

public slots:
    void updateItems();
    void updateState();
private:
    ItemCollection        ItemContainer;
    Tester::Kernel::Plan* Plan;
};

}
}

#endif // TESTMODEL_H
