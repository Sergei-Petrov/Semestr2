#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "List.h"

class ListTest:public QObject
{
    Q_OBJECT

public:
    explicit ListTest(QObject *parent = 0):QObject(parent){}

private slots:

    void init()
    {
        obj = new List();
    }

    void cleanup()
    {
        delete obj;
    }

    void TestLength()
    {
        QCOMPARE(obj->length(), 0);
    }

    void TestAdd()
    {
        string str = "123";
        obj->add(str);
        obj->add("1234");
        QVERIFY(!obj->isEmpty());
    }

    void TestAddCounter()
    {
        obj->add("123");
        obj->add("1234");
        QCOMPARE(obj->length(), 2);
    }

    void TestRemove()
    {
        obj->add("123");
        obj->remove("123");
        QVERIFY(obj->isEmpty());
    }

    void TestRemoveCounter()
    {
        obj->add("123");
        obj->remove("123");
        QCOMPARE(obj->length(), 0);
    }

    void TestIsEmpty()
    {
        QVERIFY(obj->isEmpty());
    }

    void TestSearch()
    {
        obj->add("23");
        obj->add("34");
        obj->add("45");
        QVERIFY(obj->search("34"));
    }

    void TestToString()
    {
        obj->add("23");
        obj->add("34");
        QCOMPARE(obj->toString().compare("2334"), 0);
    }

    void TestRepeats()
    {
        obj->add("234");
        obj->add("234");
        obj->remove("234");
        QVERIFY(obj->search("234"));
    }

    void TestCurrentRepeats()
    {
        obj->add("234");
        obj->add("234");
        QCOMPARE(obj->curRepeats(), 2);
    }

    void TestCurrrentValue()
    {
        obj->add("23");
        QCOMPARE(obj->curValue().compare("23"), 0);
    }

    void TestFurther()
    {
        obj->add("23");
        obj->add("34");
        obj->further();
        QCOMPARE(obj->curValue().compare("34"), 0);
    }

private:
    List *obj;
};
