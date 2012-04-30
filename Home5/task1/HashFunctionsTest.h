#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "HashFunctions.h"

class HashFunctionsTest:public QObject
{
    Q_OBJECT

public:
    explicit HashFunctionsTest(QObject *parent = 0):QObject(parent){}

private slots:

    void init()
    {
        obj = new FirstHash();
        obj2 = new SecondHash();
    }

    void cleanup()
    {
        delete obj;
        delete obj2;
    }

    void TestFirst()
    {
        string str = "Aa5";
        QCOMPARE(obj->hash(str, 100), 15);
    }

    void TestSecond()
    {
        string str = "Aa5";
        QCOMPARE(obj2->hash(str, 100), 18);
    }

private:
    Function *obj;
    Function *obj2;
};
