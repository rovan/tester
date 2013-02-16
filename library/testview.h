#ifndef TESTVIEW_H
#define TESTVIEW_H

#include <QGraphicsWidget>
#include <QColor>

#include "type.h"

class TViewSettings{
public:
    static TViewSettings Default;
    static TViewSettings Pass;
    static TViewSettings Fail;
    static TViewSettings Warning;
    static TViewSettings Run;
    static TViewSettings Skip;

    static int Width;
    static int Height;
public:
    TViewSettings(const QString& border_color, const QString& fill_color)
        : BorderColor(QColor(border_color))
        , FillColor(QColor(fill_color))
    {}

    QColor BorderColor;
    QColor FillColor;
};

class TTestView : public QGraphicsWidget
{
    Q_OBJECT

public:
    TTestView(TTestSuit* test_suit, QGraphicsItem * parent = 0);
    ~TTestView();
    void setTestSuit(TTestSuit* value);

protected slots:
    void updateDecoration();
protected:
    QLinearGradient createGradientFromColor(const QColor &c);

private:
    void apply(const TViewSettings& settings);
private:
    QGraphicsPathItem*   BackItem;
    QGraphicsTextItem*   Title;
    QGraphicsWidget*     ImageContainer;
    QGraphicsPixmapItem* Image;
    QGraphicsTextItem*   FailText;
    QGraphicsTextItem*   Message;
    TTestSuit*           TestSuit;
};

#endif // TESTVIEW_H
