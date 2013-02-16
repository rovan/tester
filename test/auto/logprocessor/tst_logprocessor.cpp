#include <QString>
#include <QtTest>
#include <QSignalSpy>

#include <logprocessor.h>
#include <shared.h>

class TTestHelper{
public:
    template<class T>
    static void propertyChange( const QSignalSpy& spy
                              , const T& actual
                              , const T& expected
                              , const int& expected_emissions
                              , const T& expected_previous
                              ){

        QCOMPARE(actual, expected);
        QCOMPARE(spy.count(), expected_emissions);

        if(spy.count() > 0){
            QList<QVariant> arguments = spy.at(0);
            T previous = arguments.at(0).value<T>();
            T current = arguments.at(1).value<T>();
            QCOMPARE(previous, expected_previous);
            QCOMPARE(current, expected);
        }
    }

};


class TLogProcessorTest : public QObject
{
    Q_OBJECT
    
public:
    TLogProcessorTest();
    
private Q_SLOTS:
    void general();
    void general_data();
};

TLogProcessorTest::TLogProcessorTest()
{
}

void TLogProcessorTest::general_data()
{
    QTest::addColumn<QString>("expected_log");
    QTest::addColumn<TLogProcessor::TestState>("expected_state");
    QTest::addColumn<int>("expected_log_changes");
    QTest::addColumn<int>("expected_state_changes");

    QTest::newRow("erroneous") << Shared::errorLog()  << TLogProcessor::Erroneous << 0 << 0;
    QTest::newRow("failing")   << Shared::failedLog() << TLogProcessor::Failed    << 1 << 1;
    QTest::newRow("passing")   << Shared::passedLog() << TLogProcessor::Passed    << 1 << 1;
}


void TLogProcessorTest::general()
{
    QFETCH(QString, expected_log);
    QFETCH(TLogProcessor::TestState, expected_state);
    QFETCH(int, expected_log_changes);
    QFETCH(int, expected_state_changes);

    TLogProcessor processor;

    QSignalSpy log_spy(&processor, SIGNAL(logChanged(const QString&, const QString&)));
    QSignalSpy state_spy(&processor, SIGNAL(stateChanged(const TLogProcessor::TestState&, const TLogProcessor::TestState&)));
    processor.process(expected_log);

    TTestHelper::propertyChange<QString>( log_spy
                                        , processor.log()
                                        , expected_log
                                        , expected_log_changes
                                        , QString()
                                        );


    TTestHelper::propertyChange<TLogProcessor::TestState>( state_spy
                                                         , processor.state()
                                                         , expected_state
                                                         , expected_state_changes
                                                         , TLogProcessor::Erroneous
                                                         );
}

QTEST_APPLESS_MAIN(TLogProcessorTest)

#include "tst_logprocessor.moc"
