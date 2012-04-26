#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Operation.h"

class OperationTest:public QObject
{
    Q_OBJECT

public:
    explicit OperationTest(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        tree = new Operation;
        count = 0;
    }

    void cleanup()
    {
        delete tree;
    }

    void TestCalc()
    {
        string s = "(*(+25)(-64))";
        tree->build(s, count);
        QCOMPARE(tree->rezult(), 14);
    }

    void TestToString()
    {
        string s = "(*(+25)(-64))";
        tree->build(s, count);
        string str = tree->toString();
        QVERIFY(str.compare(s) == 0);
    }

private:
    Operation *tree;
    int count;
};

QTEST_MAIN(OperationTest)
