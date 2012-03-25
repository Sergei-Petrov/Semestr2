#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "calculator.h"

class CalculatorTest:public QObject
{
    Q_OBJECT
public:
    explicit CalculatorTest(QObject *parent = 0):QObject(parent){}
private slots:

    void init()
    {
        obj = new Calculator;
    }

    void cleanup()
    {
        delete obj;
    }

    void testCalculator()
    {
        string str = "23+4*2-3/";
        QVERIFY(obj->calc(str) == 6);
    }

private:
    Calculator *obj;
};
