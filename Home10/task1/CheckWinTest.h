#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "CheckWin.h"

class CheckWinTest:public QObject
{
    Q_OBJECT

public:
    explicit CheckWinTest(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        ch.restart();
    }

    void cleanup()
    {}

    void TestHorizontal()
    {
        ch.addX(0);
        QVERIFY(!ch.check(0));
        ch.addX(1);
        QVERIFY(!ch.check(1));
        ch.addX(2);
        QVERIFY(ch.check(2));
    }

    void TestVertical()
    {
        ch.addX(0);
        QVERIFY(!ch.check(0));
        ch.addX(3);
        QVERIFY(!ch.check(3));
        ch.addX(6);
        QVERIFY(ch.check(6));
    }

    void TestDiagonals()
    {
        ch.addO(0);
        QVERIFY(!ch.check(0));
        ch.addO(4);
        QVERIFY(!ch.check(4));
        ch.addO(8);
        QVERIFY(ch.check(8));
        ch.restart();
        ch.addO(2);
        QVERIFY(!ch.check(2));
        ch.addO(4);
        QVERIFY(!ch.check(4));
        ch.addO(6);
        QVERIFY(ch.check(6));
    }

    void TestDraw()
    {
        ch.addO(0);
        QVERIFY(!ch.check(0));
        ch.addX(1);
        QVERIFY(!ch.check(4));
        ch.addO(3);
        QVERIFY(!ch.check(8));
        ch.addX(4);
        QVERIFY(!ch.check(2));
        ch.addO(7);
        QVERIFY(!ch.check(4));
        ch.addX(6);
        QVERIFY(!ch.check(6));
        ch.addO(2);
        QVERIFY(!ch.check(0));
        ch.addX(5);
        QVERIFY(!ch.check(4));
        ch.addO(8);
        QVERIFY(!ch.check(8));
        QVERIFY(ch.count == 9);
    }

private:
    CheckWin ch;
};


