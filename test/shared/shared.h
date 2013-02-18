#ifndef SHARED_H
#define SHARED_H

#include "shared_global.h"

#include <QString>

class SHARED_EXPORT Shared
{
public:

    static QString errorExecutable(){
        return "C:/test.exe";
    }
    static QString failingExecutable(){
        return "./../mock/failing.exe";
    }
    static QString passingExecutable(){
        return "./../mock/passing.exe";
    }

    static QString noTestPath(){
        return "./../";
    }

    static QString existedTestPath(){
        return "./../mock/";
    }

    static QString errorLog(){
        return QString();
    }

    static QString failedLog(){
        return QString(
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\r\n"
            "<testsuite errors=\"0\" failures=\"1\" tests=\"3\" name=\"TFailingTest\">\r\n"
            "  <properties>\r\n"
            "    <property value=\"5.0.1\" name=\"QTestVersion\"/>\r\n"
            "    <property value=\"5.0.1\" name=\"QtVersion\"/>\r\n"
            "  </properties>\r\n"
            "  <testcase result=\"pass\" name=\"initTestCase\"/>\r\n"
            "  <testcase result=\"fail\" name=\"failingCase\">\r\n"
            "    <failure message=\"&apos;false&apos; returned FALSE. (Failure)\" result=\"fail\"/>\r\n"
            "  </testcase>\r\n"
            "  <testcase result=\"pass\" name=\"cleanupTestCase\"/>\r\n"
            "  <system-err/>\r\n"
            "</testsuite>\r\n"
        );
    }

    static QString passedLog(){
        return QString(
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\r\n"
            "<testsuite errors=\"0\" failures=\"0\" tests=\"3\" name=\"TPassingTest\">\r\n"
            "  <properties>\r\n"
            "    <property value=\"5.0.1\" name=\"QTestVersion\"/>\r\n"
            "    <property value=\"5.0.1\" name=\"QtVersion\"/>\r\n"
            "  </properties>\r\n"
            "  <testcase result=\"pass\" name=\"initTestCase\"/>\r\n"
            "  <testcase result=\"pass\" name=\"passingCase\"/>\r\n"
            "  <testcase result=\"pass\" name=\"cleanupTestCase\"/>\r\n"
            "  <system-err/>\r\n"
            "</testsuite>\r\n"
        );
    }

    static QString libraryLog(){
        return QString(
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\r\n"
            "<testsuite errors=\"0\" failures=\"0\" tests=\"3\" name=\"TExternalTest\">\r\n"
            "  <properties>\r\n"
            "    <property value=\"5.0.1\" name=\"QTestVersion\"/>\r\n"
            "    <property value=\"5.0.1\" name=\"QtVersion\"/>\r\n"
            "  </properties>\r\n"
            "  <testcase result=\"pass\" name=\"initTestCase\"/>\r\n"
            "  <testcase result=\"pass\" name=\"testCase1\"/>\r\n"
            "  <testcase result=\"pass\" name=\"cleanupTestCase\"/>\r\n"
            "  <system-err/>\r\n"
            "</testsuite>\r\n"
        );
    }

    static QString libraryPath(){
        return "./../";
    }

    static QString libraryExecutable(){
        return "./../mock/external.exe";
    }

};

class SHARED_EXPORT External{
public:
    static bool trueValue();
};

#endif // SHARED_H
