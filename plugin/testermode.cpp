#include "testermode.h"
#include <coreplugin/coreconstants.h>
#include "testerpluginconstants.h"

#include "./../library/planwidget.h"
namespace Tester{
namespace Internal{

Mode::Mode(QObject* parent)
    : Core::IMode(parent)
{
    setDisplayName(tr("Tester"));
    setIcon(QIcon(QLatin1String(Core::Constants::ICON_QTLOGO_32)));
    setPriority(Tester::Constants::P_MODE_PRIORITY);
    setId(Tester::Constants::ID);
    setType(Tester::Constants::TYPE);
    setContextHelpId(QLatin1String("Tester"));
    setContext(Core::Context(Tester::Constants::CONTEXT));

    Widget = new Tester::Gui::PlanWidget;
    setWidget(Widget);
}


void Mode::setController(Tester::Gui::Controller* value){
    Widget->setController(value);
}

}
}
