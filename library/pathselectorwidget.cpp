#include "pathselectorwidget.h"

#include <QFileDialog>

#include "ui_PathSelectorWidget.h"

namespace Tester{
namespace Gui{

PathSelectorWidget::PathSelectorWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PathSelectorWidget)
{
    ui->setupUi(this);

    connect(ui->Editor, &QLineEdit::textChanged, this, &Tester::Gui::PathSelectorWidget::pathChanged);
    connect(ui->Button, &QToolButton::clicked  , this, &Tester::Gui::PathSelectorWidget::selectPath);
}

PathSelectorWidget::~PathSelectorWidget(){
    delete ui;
}
void PathSelectorWidget::setPath(const QString& value){
    ui->Editor->setText(value);
}

void PathSelectorWidget::selectPath(){
    QFileDialog dialog(NULL, DialogTitle);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly, true);
    if(dialog.exec() == QDialog::Accepted){
        ui->Editor->setText(dialog.selectedFiles().takeFirst());
    }
}

QString PathSelectorWidget::path() const{
    return ui->Editor->text();
}

}
}
