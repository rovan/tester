#ifndef TESTPLANFORM_H
#define TESTPLANFORM_H

#include <QWidget>
#include "library_global.h"
#include "type.h"

namespace Ui{
    class TTestPlan;
}

class TViewContainer;

class TESTER_EXPORT TTestPlanForm : public QWidget
{
    Q_OBJECT
public:
    explicit TTestPlanForm(QWidget* parent = 0);
    ~TTestPlanForm();
signals:
    
public slots:
    void selectTestPath();

private:
    STestPlan            Plan;
    TViewContainer*      ItemContainer;
    Ui::TTestPlan*       UI;
};

#endif // TESTPLANFORM_H
