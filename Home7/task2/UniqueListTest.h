#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "UniqueList.h"

class UniqueListTest:public QObject
{
    Q_OBJECT

public:
    explicit UniqueListTest(QObject *parent = 0):QObject(parent){}

private slots:

    void init()
    {
        x = 0;
        l = new UniqueList();
    }

    void cleanup()
    {
        delete l;
    }

    void testAdd()
    {
        l->add("qwert");
        QVERIFY(l->search("qwert"));
        try
        {
            l->add("qwert");
        }
        catch (UniqueList::AddingRepeat)
        {
            x = 100500;
        }
        QCOMPARE(x, 100500);
    }

    void testRemove()
    {
        try
        {
            l->remove("qwe");
        }
        catch (UniqueList::RemovingNonExistent)
        {
            x = 100500;
        }
        QCOMPARE(x, 100500);
    }

private:
    UniqueList *l;
    int x;
};
