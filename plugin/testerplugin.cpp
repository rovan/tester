#include "testerplugin.h"
#include "testerpluginconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

#include <QtPlugin>

#include "testermode.h"

#include "monitoringviewfactory.h"

#include "./../library/controller.h"

Tester::Internal::Plugin::Plugin()
    : Controller(new Tester::Gui::Controller(this))
{
    // Create your members
}

Tester::Internal::Plugin::~Plugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool Tester::Internal::Plugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize method, a plugin can be sure that the plugins it
    // depends on have initialized their members.
    
    Q_UNUSED(arguments)
    Q_UNUSED(errorString)
    
    QAction *action = new QAction(tr("TesterPlugin action"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, SIGNAL(triggered()), this, SLOT(triggerAction()));
    
    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("TesterPlugin"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);
    
    MonitoringViewFactory = new Tester::Internal::MonitoringViewFactory;
    MonitoringViewFactory->setController(Controller);
    addAutoReleasedObject(MonitoringViewFactory);

    Mode = new Tester::Internal::Mode(this);
    Mode->setController(Controller);
    addAutoReleasedObject(Mode);

    return true;

}

void Tester::Internal::Plugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized method, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag Tester::Internal::Plugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void Tester::Internal::Plugin::triggerAction()
{
    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action triggered"),
                             tr("This is an action from TesterPlugin."));
}

Q_EXPORT_PLUGIN2(TesterPlugin, TesterPluginPlugin)

