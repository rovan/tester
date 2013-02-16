#include "testplan.h"
#include <QDir>
#include <QFile>
#include <QFileInfoList>
#include "testsuit.h"
#include "type.h"

TTestPlan::TTestPlan(QObject *parent)
    : QObject(parent)
{

}

QString TTestPlan::path() const{
    return Path;
}
QString TTestPlan::name() const{
    return Name;
}

TTestSuitCollection TTestPlan::suits() const{
    return Suits;
}

void TTestPlan::startSuits(){
    for(TTestSuitCollection::iterator i = Suits.begin(); i != Suits.end(); ++i){
        (*i)->start();
    }
}

void TTestPlan::setPath(const QString& value){
    Path = value;

    QDir dir(Path);
    if(dir.isReadable()){
        Suits.clear();
        QFileInfoList entries = dir.entryInfoList(QDir::Files);
        for(QFileInfoList::iterator info = entries.begin(); info != entries.end(); ++info){
            if(info->isExecutable()){
                STestSuit suit(new TTestSuit(this));
                suit->setExecutable(info->absoluteFilePath());
                Suits.append(suit);
            }
        }
    }
}

QStringList TTestPlan::executables() const{
    QStringList result;
    for(TTestSuitCollection::const_iterator i = Suits.constBegin(); i != Suits.constEnd(); ++i){
        result.append((*i)->name());
    }
    return result;
}
