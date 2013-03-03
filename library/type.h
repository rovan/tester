#ifndef TYPE_H
#define TYPE_H

#include <QList>
#include <QPointer>
#include <QSharedPointer>

namespace Tester{
namespace Kernel{

class LogProcessor;
class Launcher;
class Suit;
class Plan;

typedef QList<Suit*> SuitCollection;

}
}

#endif // TYPE_H
