#ifndef TESTPLANFORM_H
#define TESTPLANFORM_H

#include <QWidget>
#include "library_global.h"
#include "type.h"

namespace Ui{
    class TTestPlan;
}

class QLineEdit;
class TTestModel;

class TESTER_EXPORT TTestPlanForm : public QWidget
{
    Q_OBJECT
public:
    explicit TTestPlanForm(QWidget* parent = 0);
signals:
    
public slots:
    void selectTestPath();
    void selectLibraryPath();
protected:
    void processSelection(const QString& title, QLineEdit* editor);

private:
    TTestPlan*      Plan;
    Ui::TTestPlan* UI;
    TTestModel*    TestModel;
};

#endif // TESTPLANFORM_H
