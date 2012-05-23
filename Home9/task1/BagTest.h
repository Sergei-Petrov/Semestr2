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

    void TestValueIterator()
    {
        t->insert(5);
        t->insert(7);
        t->insert(4);
        Bag<int>::Iterator it = Bag<int>::Iterator(t->first());
        QCOMPARE(*it, 4);
    }

    void TestIteratorNext()
    {
        t->insert(0);
        t->insert(1);
        t->insert(2);
        t->insert(3);
        t->insert(4);
        t->insert(5);
        t->insert(6);
        t->insert(7);
        t->insert(8);
        t->insert(8);
        t->insert(9);
        stringstream out;
        string str = "0 1 2 3 4 5 6 7 8 8 9 ";
        Bag<int>::Iterator it = Bag<int>::Iterator(t->first());
        for(int i = 0; i < 11; i++)
        {
            out << *it << " ";
            it++;
        }
        QCOMPARE(out.str(), str);
    }

    void TestIteratorPrev()
    {
        t->insert(0);
        t->insert(1);
        t->insert(2);
        t->insert(3);
        t->insert(4);
        t->insert(5);
        t->insert(6);
        t->insert(7);
        t->insert(8);
        t->insert(8);
        t->insert(9);
        stringstream out;
        string str = "9 8 8 7 6 5 4 3 2 1 0 ";
        Bag<int>::Iterator it = Bag<int>::Iterator(t->last());
        for(int i = 0; i < 11; i++)
        {
            out << *it << " ";
            it--;
        }
        QCOMPARE(out.str(), str);
    }

    void TestIteratorEqually()
    {
        t->insert(0);
        t->insert(1);
        Bag<int>::Iterator it = Bag<int>::Iterator(t->first());
        Bag<int>::Iterator it2 = Bag<int>::Iterator(t->first());
        QVERIFY(it == it2);
    }

    void TestIteratorNotEqually()
    {
        t->insert(0);
        t->insert(1);
        Bag<int>::Iterator it = Bag<int>::Iterator(t->first());
        Bag<int>::Iterator it2 = Bag<int>::Iterator(t->last());
        QVERIFY(it != it2);
    }

private:
    Bag<int> *t;
};

