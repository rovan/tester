#include "testplan.h"
#include <QDir>
#include <QFileInfoList>
#include "testsuit.h"

TTestPlan::TTestPlan(const QString& path)
    : Path(path)
    , Name(path)
{
    QDir dir(path);
    if(dir.isReadable()){
        QFileInfoList entries = dir.entryInfoList(QDir::Files);

        for(QFileInfoList::iterator info = entries.begin(); info != entries.end(); ++info){
            if(info->isExecutable()){
                TTestSuit* suit = new TTestSuit(info->absolutePath());
                Suits.append(suit);
            }
        }
    }
}

TTestPlan::~TTestPlan(){
    for(TTestSuitCollection::iterator i = Suits.begin(); i != Suits.end(); ++i){
        delete *i;
    }
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
