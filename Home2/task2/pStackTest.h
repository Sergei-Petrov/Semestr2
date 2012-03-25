#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "pstack.h"

class PStackTest:public QObject
{
    Q_OBJECT
public:
    explicit PStackTest(QObject *parent = 0):QObject(parent){}
private slots:

    void init()
    {
        s = new PStack();
    }

    void cleanup()
    {
        delete s;
    }

    void testToString()
    {
        s->push('3');
        s->push('4');
        QVERIFY(s->toString() == "43");
    }

    void testPush()
    {
        s->push('3');
        s->push('4');
        QVERIFY(s->toString() == "43");
    }

    void testPushCounter()
    {
        s->push('3');
        s->push('4');
        QVERIFY(s->length() == 2);
    }

    void testPop()
    {
        s->push('6');
        char x = s->pop();
        QVERIFY(s->toString() == "");
    }

    void testPopCounter()
    {
        s->push('6');
        char x = s->pop();
        QVERIFY(s->length() == 0);
    }

    void testPopReturnValue()
    {
        s->push('6');
        char x = s->pop();
        QVERIFY(x == '6');
    }

private:
    Stack *s;
};
