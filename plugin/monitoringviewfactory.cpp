#include "monitoringviewfactory.h"

#include "./../library/monitoringwidget.h"
#include "./../library/controller.h"

namespace Tester{
namespace Internal{

MonitoringViewFactory::MonitoringViewFactory()
{
}

MonitoringViewFactory::~MonitoringViewFactory(){

}

Core::NavigationView MonitoringViewFactory::createWidget(){
    Core::NavigationView view;
    Tester::Gui::MonitoringWidget* widget = new Tester::Gui::MonitoringWidget;
    widget->setController(Controller);
    view.widget = widget;
    return view;
}

QString MonitoringViewFactory::displayName() const{
    return QString(tr("Test monitor"));
}

int MonitoringViewFactory::priority() const{
    return 0;
}

Core::Id MonitoringViewFactory::id() const{
    return "Test monitor";
}

void MonitoringViewFactory::setController(Tester::Gui::Controller* value)
{
    Controller = value;
}

}
}

