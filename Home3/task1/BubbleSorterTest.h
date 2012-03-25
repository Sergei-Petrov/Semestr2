#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "bubblesorter.h"

class BubbleSorterTest:public QObject
{
    Q_OBJECT
public:
    explicit BubbleSorterTest(QObject *parent = 0):QObject(parent){}
private slots:
    void init()
    {
        obj = new BubbleSorter();
    }
    void cleanup()
    {
        delete obj;
    }

    void BubbleSortTest()
    {
        int a[4] = {2, 6, 5, 3};
        int b[4] = {2, 3, 5, 6};
        obj->sort(a,4);
        for(int i = 0; i < 4; i++)
            QVERIFY(a[i] == b[i]);
    }

private:
    Sorter *obj;
};
