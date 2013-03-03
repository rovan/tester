#ifndef TESTERMODE_H
#define TESTERMODE_H

#include <coreplugin/imode.h>

#include <QPointer>

namespace Tester{
namespace Gui{
    class PlanWidget;
    class Controller;
}
namespace Internal{

class Mode : public Core::IMode
{
    Q_OBJECT
public:
    explicit Mode(QObject *parent = 0);

signals:

public slots:
    void setController(Tester::Gui::Controller* value);
private:
    QPointer<Tester::Gui::PlanWidget> Widget;
};

}
}


#endif // TESTERMODE_H
