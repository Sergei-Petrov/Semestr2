#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "BubbleSorter.h"
#include "string"

using namespace std;

class BubbleSorterTest:public QObject
{
    Q_OBJECT
public:
    explicit BubbleSorterTest(QObject *parent = 0):QObject(parent){}
private slots:
    void init()
    {
        obj = new BubbleSorter<int, Comparative>;
        obj2 = new Comparative;
    }

    void cleanup()
    {
        delete obj;
        delete obj2;
    }

    void BubbleSortTestInt()
    {
        int a[4] = {2, 6, 5, 3};
        int b[4] = {2, 3, 5, 6};
        obj->sort(a,4, obj2);
        for(int i = 0; i < 4; i++)
            QCOMPARE(a[i], b[i]);
    }

private:
    BubbleSorter<int, Comparative> *obj;
    Comparative *obj2;
};

QTEST_MAIN(BubbleSorterTest)
