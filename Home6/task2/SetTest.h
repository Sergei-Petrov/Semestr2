#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Set.h"

class SetTest:public QObject
{
    Q_OBJECT

public:
    explicit SetTest(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        obj = new Set<int>;
        obj2 = new Set<int>;
        obj3 = new Set<int>;
    }

    void cleanup()
    {
        delete obj;
        delete obj2;
        delete obj3;
    }

    void TestIsEmpty()
    {
        QVERIFY(obj->isEmpty());
    }

    void TestAddValue()
    {
        obj->addValue(4);
        QVERIFY(!obj->isEmpty());
    }

    void TestDelValue()
    {
        obj->addValue(4);
        obj->addValue(5);
        QVERIFY(obj->delValue(4) && !obj->delValue(4));
    }

    void TestSearch()
    {
        obj->addValue(5);
        obj->addValue(6);
        obj->addValue(8);
        QVERIFY(obj->search(6) && !obj->search(1));
    }

    void TestIntersect()
    {
        obj3->addValue(5);
        obj3->addValue(6);
        obj3->addValue(8);
        obj2->addValue(3);
        obj2->addValue(4);
        obj2->addValue(8);
        obj->intersect(obj2, obj3);
        QVERIFY(obj->search(8));
    }

    void TestSum()
    {
        obj2->addValue(1);
        obj2->addValue(3);
        obj3->addValue(2);
        obj3->addValue(4);
        obj->sum(obj2, obj3);
        QVERIFY(obj->search(1) && obj->search(2) && obj->search(3) && obj->search(4));
    }

private:
    Set<int> *obj;
    Set<int> *obj2;
    Set<int> *obj3;
};

QTEST_MAIN(SetTest)
