#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "HashFunction.h"

class HashFunctionTest:public QObject
{
    Q_OBJECT

public:
    explicit HashFunctionTest(QObject *parent = 0):QObject(parent){}

private slots:

    void init()
    {
        l = new HashFunction();
    }

    void cleanup()
    {
        delete l;
    }

    void TestCall()
    {
        string str = "Aa5";
        QCOMPARE(l->call(str, 100), 15);
    }

    void TestChange()
    {
        string str = "Aa5";
        l->change(2);
        QCOMPARE(l->call(str, 100), 18);
    }

private:
    Function *l;
};
