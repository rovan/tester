#ifndef MONITORINGVIEWFACTORY_H
#define MONITORINGVIEWFACTORY_H

#include <coreplugin/inavigationwidgetfactory.h>
#include <QPointer>

namespace Tester{
namespace Gui{
    class Controller;
}
namespace Internal{

class MonitoringViewFactory : public Core::INavigationWidgetFactory
{
public:
    MonitoringViewFactory();
    ~MonitoringViewFactory();
    Core::NavigationView createWidget();
    QString displayName() const;
    int priority() const;
    Core::Id id() const;

    void setController(Tester::Gui::Controller* value);
private:
    QPointer<Tester::Gui::Controller> Controller;
};

}
}

#endif // MONITORINGVIEWFACTORY_H
