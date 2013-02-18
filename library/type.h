#ifndef TYPE_H
#define TYPE_H

#include <QList>
#include <QPointer>
#include <QSharedPointer>

class TLogProcessor;
class TLauncher;
class TTestSuit;
class TTestPlan;

//typedef QPointer<TLogProcessor> PLogProcessor;
//typedef QPointer<TLauncher> PLauncher;
//typedef QPointer<TTestSuit> PTestSuit;

//typedef QSharedPointer<TLogProcessor> SLogProcessor;
//typedef QSharedPointer<TLauncher>     SLauncher;
//typedef QSharedPointer<TTestSuit>     STestSuit;
//typedef QSharedPointer<TTestPlan>     STestPlan;

typedef QList<TTestSuit*> TTestSuitCollection;

#endif // TYPE_H
