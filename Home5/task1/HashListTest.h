#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "HashList.h"

class HashListTest:public QObject
{
    Q_OBJECT

public:
    explicit HashListTest(QObject *parent = 0):QObject(parent){}

private slots:

    void init()
    {
        obj = new HashList();
        f = new FirstHash;
        f2 = new SecondHash;
        obj->selectOfFunction(f);
    }

    void cleanup()
    {
        delete obj;
    }

    void TestAdd()
    {
        obj->add("345");
        QVERIFY(obj->search("345"));
    }

    void TestRemove()
    {
        obj->add("345");
        obj->remove("345");
        QVERIFY(!obj->search("345"));
    }

    void TestRemoveRepeats()
    {
        obj->add("345");
        obj->add("345");
        obj->remove("345");
        QVERIFY(obj->search("345"));
    }

private:
    HashList *obj;
    Function *f;
    Function *f2;
};
