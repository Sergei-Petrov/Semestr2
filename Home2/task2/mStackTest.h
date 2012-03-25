#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "mstack.h"

class MStackTest:public QObject
{
    Q_OBJECT
public:
    explicit MStackTest(QObject *parent = 0):QObject(parent){}
private slots:

    void init()
    {
        s = new MStack();
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

