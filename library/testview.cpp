#include "testview.h"

#include <QPen>
#include <QFontMetricsF>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QVariant>
#include <QGraphicsScene>
#include <QDebug>

#include "testsuit.h"

int TViewSettings::Width  = 105;
int TViewSettings::Height = 105;

TViewSettings TViewSettings::Default = TViewSettings("gray", "darkgray");
TViewSettings TViewSettings::Pass    = TViewSettings("olivedrab", "yellowgreen");
TViewSettings TViewSettings::Warning = TViewSettings("#dddd00", "yellow");
TViewSettings TViewSettings::Fail    = TViewSettings("indianred", "tomato");
TViewSettings TViewSettings::Run     = TViewSettings("tan", "khaki");
TViewSettings TViewSettings::Skip    = TViewSettings("floralwhite", "white");


TTestView::TTestView(TTestSuit *test_suit, QGraphicsItem *parent)
    : QGraphicsWidget(parent)
    , TestSuit(NULL)
{
    setCacheMode(QGraphicsItem::ItemCoordinateCache);

    BackItem = new QGraphicsPathItem;
    QPainterPath path;
    path.addRoundedRect(0, 0, TViewSettings::Width, TViewSettings::Height, 15, 15);
    BackItem->setPath(path);
    BackItem->setPen(QPen(TViewSettings::Default.BorderColor, 2));
    BackItem->setBrush(createGradientFromColor(TViewSettings::Default.FillColor));
    BackItem->setParentItem(this);

    setVisible(false);
    resize(TViewSettings::Width, TViewSettings::Height);

    setTransformOriginPoint(TViewSettings::Width / 2.0, TViewSettings::Height / 2.0);

    Title = new QGraphicsTextItem(this);
    Title->setTextInteractionFlags(Qt::NoTextInteraction);
    Title->setDefaultTextColor(Qt::white);
    QFont f("Monotype", 9, QFont::DemiBold);
    Title->setFont(f);

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(4);
    shadow->setOffset(2, 3);
    shadow->setColor(QColor(50, 50, 50));
    Title->setGraphicsEffect(shadow);

    ImageContainer = new QGraphicsWidget(this);
    Image = new QGraphicsPixmapItem(ImageContainer);
    Image->setPos(0, 0);

    QFont f2("Monotype", 8/*, QFont::DemiBold*/);
    QFont f3("Monotype", 14, QFont::DemiBold);
    FailText = new QGraphicsTextItem(ImageContainer);
    FailText->setTextInteractionFlags(Qt::NoTextInteraction);
    FailText->setFont(f3);
    FailText->setDefaultTextColor(Qt::white);
    Message = new QGraphicsTextItem(this);
    Message->setTextInteractionFlags(Qt::NoTextInteraction);
    Message->setFont(f2);
    Message->setDefaultTextColor(Qt::white);

    setTestSuit(test_suit);
}

TTestView::~TTestView()
{

}

QLinearGradient TTestView::createGradientFromColor(const QColor &c)
{
    QLinearGradient result(QPointF(BackItem->boundingRect().width() * 0.42, 0),
                           QPointF(BackItem->boundingRect().width() * 0.76, BackItem->boundingRect().height()));
    QColor dark;
    dark.setCmyk(c.cyan(), c.magenta(), c.yellow(), 180);
    result.setColorAt(0, dark);
    result.setColorAt(1, c);
    return result;
}

void TTestView::setTestSuit(TTestSuit *value){
    if(TestSuit){
        TestSuit->disconnect(this);
    }

    TestSuit = value;

    if (TestSuit){
        const QString test_name = TestSuit->name();
        setToolTip(test_name);
        Title->setPlainText(test_name);

        QFontMetricsF fm(Title->font());
        if (fm.width(test_name) >= TViewSettings::Width - 10) {
            Title->setTextWidth(TViewSettings::Width - 10);
        }
        Title->setPos(geometry().width() / 2 - Title->boundingRect().width() / 2, 2);

        connect(TestSuit, &TTestSuit::finished, this, &TTestView::updateDecoration);
    }
}

void TTestView::updateDecoration(){
    if(TestSuit){
        if(TestSuit->isErroneus()){
            apply(TViewSettings::Warning);
        }else if(TestSuit->isPassed()){
            apply(TViewSettings::Pass);
        }else if(TestSuit->isFailed()){
            apply(TViewSettings::Fail);
        }
    }
}

/*
void TTestView::onTestStatusChanged(Test::TestStatus status)
{
    QColor bc;
    QColor c;

    img->setOpacity(1);

    int failCount = t->result().failures.count();
    int warnCount = 0;
    foreach (const TestIncident &incident, t->result().messages) {
        if (incident.type == "qwarn")
            warnCount++;
    }
    nbFail->setPlainText("");
    nbFail->setVisible(false);

    switch (status) {
    case Test::Initial:
        bc = BORDER_COLOR_INIT;
        c = COLOR_INIT;
        img->setVisible(false);
        message->setVisible(false);
        break;
    case Test::Building:
        img->setPixmap(QPixmap(":/images/build.png").scaled(QSize(32, 32), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        img->setVisible(true);
        message->setVisible(false);
        bc = BORDER_COLOR_RUN;
        c = COLOR_RUN;
        break;
    case Test::Running:
        img->setPixmap(QPixmap(":/images/gear.png").scaled(QSize(32, 32), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        img->setVisible(true);
        message->setVisible(false);
        bc = BORDER_COLOR_RUN;
        c = COLOR_RUN;
        break;
    case Test::BuildError:
        img->setPixmap(QPixmap(":/images/warn.png"));
        img->setVisible(true);
        bc = BORDER_COLOR_FAIL;
        c = COLOR_FAIL;
        message->setPlainText("Build Error");
        message->setVisible(true);
        break;
    case Test::RunError:
        img->setPixmap(QPixmap(":/images/warn.png"));
        img->setVisible(true);
        message->setPlainText("Run Error");
        message->setVisible(true);
        bc = BORDER_COLOR_FAIL;
        c = COLOR_FAIL;
        break;
    case Test::TestFail:
    case Test::TestPass:
        if (failCount == 0 && t->result().messages.count() == 0) {
            img->setPixmap(QPixmap(":/images/check.png").scaled(QSize(32, 32), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            img->setOpacity(0.5);
            message->setVisible(false);
        } else {
            img->setPixmap(QPixmap(":/images/warn.png"));
            nbFail->setPlainText(QString::number(failCount == 0 ? t->result().messages.count() : failCount));
            nbFail->setPos(img->boundingRect().width() + 2, -6);
            nbFail->setVisible(true);
            message->setPlainText(QLatin1String(failCount == 0 ?
                                                QLatin1String(t->result().messages.count() > 1 ? "messages" : "message")
                                                : QLatin1String(failCount > 1 ? "failures" : "failure")));
            message->setVisible(true);
        }
        img->setVisible(true);
        if (failCount > 0) {
            bc = BORDER_COLOR_FAIL;
            c = COLOR_FAIL;
        } else if (warnCount > 0) {
            bc = BORDER_COLOR_WARN;
            c = COLOR_WARN;
        } else {
            bc = BORDER_COLOR_PASS;
            c = COLOR_PASS;
        }
        break;
    case Test::Skipped:
        img->setVisible(false);
        message->setPlainText("Skipped");
        message->setVisible(true);
        bc = BORDER_COLOR_SKIP;
        c = COLOR_SKIP;
        break;
    }

    qreal imgContainerX = backItem->boundingRect().width() / 2 - img->boundingRect().width() / 2;
    qreal imgContainerY = backItem->boundingRect().height() / 2 - img->boundingRect().height() / 2 + 5;
    if (nbFail->isVisible()) {
        imgContainerX -= nbFail->boundingRect().width() / 2;
        imgContainerY -= 5;
    }
    imgContainer->setPos(imgContainerX, imgContainerY);
    imgContainer->setTransformOriginPoint(img->boundingRect().width() / 2, img->boundingRect().height() / 2);
    backItem->setPen(QPen(QColor(bc), 2));
    backItem->setBrush(createGradientFromColor(c));
    message->setPos(backItem->boundingRect().width() / 2 - message->boundingRect().width() / 2,
                    imgContainer->pos().y() + img->boundingRect().height() + 1);
}
*/
void TTestView::apply(const TViewSettings& settings){
    BackItem->setPen(QPen(QColor(settings.BorderColor), 2));
    BackItem->setBrush(createGradientFromColor(settings.FillColor));
}
