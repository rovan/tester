#ifndef VIEWCONTAINER_H
#define VIEWCONTAINER_H

#include <QGraphicsWidget>

class QGraphicsGridLayout;
class TTestView;

class TViewContainer : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit TViewContainer();
    ~TViewContainer();
    void addItem(TTestView* item);
    void clear();
    
public slots:
private:
    QGraphicsGridLayout* Layout;
};

#endif // VIEWCONTAINER_H
