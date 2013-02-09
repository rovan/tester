#include "testcase.h"
#include <QDomElement>

TTestCase::TTestCase(const QString case_name, const State& case_state)
    : CaseName(case_name)
    , CaseState(case_state)
{}

TTestCase::TTestCase(const QDomElement& element){
    CaseState = TTestCase::Undefined;
    if(element.tagName() == "testcase"){
        CaseName = element.attribute("name");
        CaseState = TTestCase::Pass;

        if(element.attribute("result") == "fail"){
            CaseState = TTestCase::Fail;
            for(QDomElement failure = element.firstChildElement(); !failure.isNull(); failure = failure.nextSiblingElement()){
                addFailedTag(failure.attribute("tag"), failure.attribute("message"));
            }
        }
    }
}

TTestCase::TTestCase(const TTestCase& original)
    : CaseName(original.CaseName)
    , CaseState(original.CaseState)
{

}

void TTestCase::addFailedTag(const QString& name, const QString& message){
    FailedTags.insert(name, message);
}

QHash<QString, QString> TTestCase::failedTags() const{
    return FailedTags;
}
