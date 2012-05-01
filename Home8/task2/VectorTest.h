#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Vector.h"
#include "sstream"

class VectorTest:public QObject
{
    Q_OBJECT

public:
    explicit VectorTest(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {}

    void cleanup()
    {}

    void TestConstructor()
    {
        Vector<int, 5> obj;
        string str = "<0, 0, 0, 0, 0>\n";
        QCOMPARE(obj.print(), str);
    }

    void TestConstructorArray()
    {
        int a[5] = {1, 2, 3, 4, 5};
        string str = "<1, 2, 3, 4, 5>\n";
        Vector<int, 5> obj(a, 5);
        QCOMPARE(obj.print(), str);
    }

    void TestCopyConstructor()
    {
        int a[5] = {1, 2, 3, 4, 5};
        string str = "<1, 2, 3, 4, 5>\n";
        Vector<int, 5> obj(a, 5);
        Vector<int, 5> obj2(obj);
        QCOMPARE(obj2.print(), str);
    }

    void TestAddition()
    {
        int a[5] = {1, 2, 3, 4, 5};
        Vector<int, 5> obj(a, 5);
        Vector<int, 5> obj2(obj);
        Vector<int, 5> obj3;
        obj3.addition(obj, obj2);
        string str = "<2, 4, 6, 8, 10>\n";
        QCOMPARE(obj3.print(), str);
    }

    void TestSubtraction()
    {
        int a[5] = {2, 4, 6, 8, 10};
        Vector<int, 5> obj(a, 5);
        int b[5] = {1, 2, 3, 4, 5};
        Vector<int, 5> obj2(b, 5);
        Vector<int, 5> obj3;
        obj3.subtraction(obj, obj2);
        string str = "<1, 2, 3, 4, 5>\n";
        QCOMPARE(obj3.print(), str);
    }

    void TestScalar()
    {
        int a[5] = {1, 2, 3, 4, 5};
        Vector<int, 5> obj(a, 5);
        Vector<int, 5> obj2(obj);
        QCOMPARE(obj.scalar(obj2), 55);
    }

    void TestIsNull()
    {
        Vector<int, 5> obj;
        int a[5] = {1, 2, 3, 4, 5};
        Vector<int, 5> obj2(a, 5);
        QVERIFY(obj.isNull() && !obj2.isNull());
    }
};

QTEST_MAIN(VectorTest)
