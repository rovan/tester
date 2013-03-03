#include "logprocessor.h"
#include <QDataStream>
#include <QDebug>

class TXmlError{
public:
    int Line;
    int Column;
    QString Message;
};

namespace Tester{
namespace Kernel{


LogProcessor::LogProcessor(QObject *parent)
    : QObject(parent)
    , State(LogProcessor::Erroneous)
{
}

QDomDocument LogProcessor::document() const{
    return Document;
}

QString LogProcessor::log() const{
    return Log;
}

LogProcessor::TestState LogProcessor::state() const{
    return State;
}

void LogProcessor::process(const QString& log){
    const QString previous_log = Log;
    const LogProcessor::TestState previous_state = State;

    Log = log;

//    qDebug() << Log;

    if(previous_log != Log)
        emit logChanged(previous_log, Log);

    TXmlError error;
    Document.setContent(Log, &error.Message, &error.Line, &error.Column);

    if(!error.Message.isEmpty()){
        State = LogProcessor::Erroneous;
    }else{
        const int failure_count = Document.firstChildElement().attribute("failures").toInt();
        const int error_count   = Document.firstChildElement().attribute("errors").toInt();

        if(failure_count > 0){
            State = LogProcessor::Failed;
        }else if(error_count > 0){
            State = LogProcessor::Erroneous;
        }else{
            State = LogProcessor::Passed;
        }
    }
    if(previous_state != State)
        emit stateChanged(previous_state, State);
}
}
}

QDataStream& operator<<(QDataStream& stream, const Tester::Kernel::LogProcessor::TestState& data){
    return stream << int(data);
}

QDataStream& operator>>(QDataStream& stream, Tester::Kernel::LogProcessor::TestState& data){
    int state;
    stream >> state;
    data = Tester::Kernel::LogProcessor::TestState(state);
    return stream;
}
