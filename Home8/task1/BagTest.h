#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Bag.h"

class BagTest:public QObject
{
    Q_OBJECT

public:
    explicit BagTest(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        t = new Bag<int>;
    }

    void cleanup()
    {
        delete t;
    }

    void TestIsEmpty()
    {
        QVERIFY(t->isEmpty());
    }

    void TestInsert()
    {
        t->insert(5);
        QVERIFY(t->find(5));
    }

    void TestErase()
    {
        t->insert(5);
        t->erase(5);
        QVERIFY(!t->find(5));
    }

    void TestClear()
    {
        t->insert(5);
        t->insert(7);
        t->insert(4);
        t->clear();
        QVERIFY(!t->find(5) && !t->find(7) && !t->find(4));
    }

private:
    Bag<int> *t;
};

