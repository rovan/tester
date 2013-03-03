#ifndef TESTERPLUGIN_H
#define TESTERPLUGIN_H

#include "testerplugin_global.h"

#include <extensionsystem/iplugin.h>

#include <QPointer>

namespace Tester {
namespace Gui{
    class Controller;
}
namespace Internal {

class Mode;
class MonitoringViewFactory;

class Plugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin")
    
public:
    Plugin();
    ~Plugin();
    
    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();
    
private slots:
    void triggerAction();
private:
    QPointer<Tester::Gui::Controller> Controller;
    QPointer<Tester::Internal::Mode> Mode;
    QPointer<Tester::Internal::MonitoringViewFactory> MonitoringViewFactory;
};

} // namespace Internal
} // namespace TesterPlugin

#endif // TESTERPLUGIN_H
