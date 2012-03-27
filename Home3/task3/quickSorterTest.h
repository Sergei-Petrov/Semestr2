#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "quickSorter.h"

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

    void testQuickSort()
    {
        int count = 9;
        int sign = -1;
        int count2 = 9;
        int **a = new int *[5];
        for (int i = 0; i < 5; i++)
            a[i] = new int[2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 5; j++)
            {
                a[j][i] = count;
                count = count + sign * count2--;
                sign = sign * -1;
            }
        int b[5][2] = {{0, 6}, {1, 5}, {7, 4}, {8, 3}, {9,2}};
        obj->sort(a, 5);

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 5; j++)
                QVERIFY(a[j][i] == b[j][i]);
        }
        for (int i = 0; i < 3; i++)
            delete [] a[i];
        delete [] a;
    }

private:
    Sorter *obj;
};

QTEST_MAIN(QuickSorterTest)
