#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "dlist.h"

class DListTest:public QObject
{
    Q_OBJECT
public:
    explicit DListTest(QObject *parent = 0):QObject(parent){}
private slots:
    void init()
    {
        l = new DList();
    }
    void cleanup()
    {
        delete l;
    }

    void testValueHead()
    {
        l->add(3);
        QVERIFY(l->valueHead() == 3);
    }

    void testValueTail()
    {
        l->add(3);
        l->add(5);
        QVERIFY(l->valueTail() == 5);
    }

    void testAdd()
    {
        l->add(5);
        l->add(6);
        l->add(7);
        QVERIFY(l->valueHead() == 5 && l->valueTail() == 7);
    }

    void testAddCounter()
    {
        l->add(5);
        l->add(6);
        l->add(7);
        QVERIFY(l->length() == 3);
    }

    void testToString()
    {
        l->add(2);
        l->add(4);
        l->add(3);
        string str = "342";
        QVERIFY(l->toString() == str);
    }

    void testLength()
    {
        l->add(2);
        l->add(4);
        QVERIFY(l->length() == 2);
    }

    void testDelHead()
    {
        l->add(2);
        l->add(4);
        int x = l->delHead();
        QVERIFY(l->valueHead() == 4);
    }

    void testDelHeadReturnValue()
    {
        l->add(2);
        l->add(4);
        int x = l->delHead();
        QVERIFY(x == 2);
    }

private:
    List *l;
};
