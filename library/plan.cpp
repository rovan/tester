#include "plan.h"
#include <QDir>
#include <QFile>
#include <QFileInfoList>
#include "suit.h"
#include "type.h"

namespace Tester{
namespace Kernel{

Plan::Plan(QObject *parent)
    : QObject(parent)
{

}

QString Plan::path() const{
    return Path;
}

QString Plan::library() const{
    return Library;
}

QString Plan::name() const{
    return Name;
}

Tester::Kernel::SuitCollection Plan::suits() const{
    return Suits;
}

void Plan::startSuits(){
    for(Tester::Kernel::SuitCollection::iterator i = Suits.begin(); i != Suits.end(); ++i){
        (*i)->start();
    }

    emit finished();
}

void Plan::scanPath()
{
    QDir dir(Path);
    if(dir.isReadable()){
        Suits.clear();
        QFileInfoList entries = dir.entryInfoList(QDir::Files, QDir::Name);
        for(QFileInfoList::iterator info = entries.begin(); info != entries.end(); ++info){
            if(info->isExecutable()){
                Suit* suit(new Suit(this));
                suit->setExecutable(info->absoluteFilePath());
                Suits.append(suit);
            }
        }
    }
}

void Plan::setPath(const QString& value){
    Path = value;
}

QStringList Plan::executables() const{
    QStringList result;
    for(Tester::Kernel::SuitCollection::const_iterator i = Suits.constBegin(); i != Suits.constEnd(); ++i){
        result.append((*i)->name());
    }
    return result;
}

void Plan::setLibraryPath(const QString& value){
    Library = value;

    for(Tester::Kernel::SuitCollection::iterator i = Suits.begin(); i != Suits.end(); ++i){
        (*i)->setLibrary(Library);
    }
}
}
}
