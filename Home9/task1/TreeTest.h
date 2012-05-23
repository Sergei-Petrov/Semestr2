#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Tree.h"

class TreeTest:public QObject
{
    Q_OBJECT

public:
    explicit TreeTest(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        t = new Tree<int>;
    }

    void cleanup()
    {
        delete t;
    }

    void TestLength()
    {
        QCOMPARE(t->length(), 0);
    }

    void TestAdd()
    {
        t->add(5);
        t->add(6);
        QVERIFY(t->search(6) && t->search(6));
    }

    void TestAddCounter()
    {
        t->add(5);
        t->add(7);
        t->add(6);
        QCOMPARE(t->length(), 3);
    }

    void TestRemoveNodeFirst()
    {
        t->add(6);
        t->add(6);
        t->RemoveNode(6);
        QVERIFY(t->search(6));
        QCOMPARE(t->length(), 1);
        t->RemoveNode(6);
        QVERIFY(!t->search(6));
        QCOMPARE(t->length(), 0);
    }

    void TestRemoveNodeSecond()
    {
        t->add(6);
        t->RemoveNode(6);
        QVERIFY(!t->search(6));
        QCOMPARE(t->length(), 0);
    }

    void TestRemoveNodeThird()
    {
        t->add(6);
        t->add(7);
        t->RemoveNode(6);
        QVERIFY(!t->search(6) && t->search(7));
        QCOMPARE(t->length(), 1);
    }

    void TestRemoveNodeFourth()
    {
        t->add(6);
        t->add(5);
        t->RemoveNode(6);
        QVERIFY(!t->search(6) && t->search(5));
        QCOMPARE(t->length(), 1);
    }

    void TestRemoveNodeFifth()
    {
        t->add(6);
        t->add(5);
        t->add(7);
        t->RemoveNode(6);
        QVERIFY(!t->search(6) && t->search(5) && t->search(7));
        QCOMPARE(t->length(), 2);
    }

    /*void TestHeight()
    {
        t->add(4);
        t->add(2);
        t->add(0);
        t->add(1);
        t->add(3);
        t->add(9);
        t->add(6);
        t->add(5);
        t->add(8);
        t->add(7);
        t->add(5);
        QCOMPARE(t->height(), 3);
    }*/

    void TestPrint()
    {
        t->add(0);
        t->add(1);
        t->add(2);
        t->add(3);
        t->add(4);
        t->add(5);
        t->add(6);
        t->add(7);
        t->add(8);
        t->add(8);
        t->add(9);
        string str = "0 1 2 3 4 5 6 7 8 8 9 ";
        QCOMPARE(t->print(), str);
    }

    /*void TestPrintToWidth()
    {
        t->add(0);
        t->add(1);
        t->add(2);
        t->add(3);
        t->add(4);
        t->add(5);
        t->add(6);
        t->add(7);
        t->add(8);
        t->add(8);
        t->add(9);
        string str = "4 2 5 1 3 7 0 6 8 8 9 ";
        QCOMPARE(t->printToWidth(), str);
    }*/

private:
    Tree<int> *t;
};

