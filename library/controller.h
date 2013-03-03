#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QPointer>

#include "library_global.h"
#include "type.h"

class QAction;

class QAbstractItemModel;

namespace Tester{
namespace Kernel{
    class Plan;
}
namespace Gui{

class ViewModel;

class TESTER_EXPORT Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);

    QAction* startAction() const;

    QString libraryPath() const;
    QString testPath() const;

    QAbstractItemModel* viewModel() const;

    QString suitLog(const QString& test_name) const;
signals:

public slots:
    void setLibraryPath(const QString& value);
    void setTestPath(const QString& value);
private:
    QPointer<Tester::Kernel::Plan> Model;
    QPointer<Tester::Gui::ViewModel> ViewModel;
    QPointer<QAction> StartAction;
};

}
}


#endif // MODEL_H
