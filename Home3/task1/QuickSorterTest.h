#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "quicksorter.h"

class QuickSorterTest:public QObject
{
    Q_OBJECT

public:
    explicit QuickSorterTest(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        obj = new QuickSorter();
    }

    void cleanup()
    {
        delete obj;
    }

    void QuickSortTest()
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

