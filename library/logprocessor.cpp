#include "logprocessor.h"
#include <QDataStream>
#include <QDebug>

class TXmlError{
public:
    int Line;
    int Column;
    QString Message;
};

TLogProcessor::TLogProcessor(QObject *parent)
    : QObject(parent)
    , State(TLogProcessor::Erroneous)
{
}

QDomDocument TLogProcessor::document() const{
    return Document;
}

QString TLogProcessor::log() const{
    return Log;
}

TLogProcessor::TestState TLogProcessor::state() const{
    return State;
}

void TLogProcessor::process(const QString& log){
    const QString previous_log = Log;
    const TLogProcessor::TestState previous_state = State;

    Log = log;

//    qDebug() << Log;

    if(previous_log != Log)
        emit logChanged(previous_log, Log);

    TXmlError error;
    Document.setContent(Log, &error.Message, &error.Line, &error.Column);

    if(!error.Message.isEmpty()){
        State = TLogProcessor::Erroneous;
    }else{
        const int failure_count = Document.firstChildElement().attribute("failures").toInt();
        const int error_count   = Document.firstChildElement().attribute("errors").toInt();

        if(failure_count > 0){
            State = TLogProcessor::Failed;
        }else if(error_count > 0){
            State = TLogProcessor::Erroneous;
        }else{
            State = TLogProcessor::Passed;
        }
    }
    if(previous_state != State)
        emit stateChanged(previous_state, State);
}

QDataStream& operator<<(QDataStream& stream, const TLogProcessor::TestState& data){
    return stream << int(data);
}

QDataStream& operator>>(QDataStream& stream, TLogProcessor::TestState& data){
    int state;
    stream >> state;
    data = TLogProcessor::TestState(state);
    return stream;
}
