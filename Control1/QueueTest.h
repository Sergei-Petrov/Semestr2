#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Queue.h"

class QueueTest:public QObject
{
    Q_OBJECT
public:
    explicit QueueTest(QObject *parent = 0):QObject(parent){}
private slots:
    void init()
    {
        l = new Queue<int>();
    }
    void cleanup()
    {
        delete l;
    }

    void TestEnqueue()
    {
        l->enqueu(4, 2);
        l->enqueu(5, 2);
        QVERIFY(l->valHead() == 5);
    }

    void TestDequeue()
    {
        l->enqueu(2, 2);
        l->enqueu(4, 4);
        l->enqueu(3, 3);
        QVERIFY(4 == l->dequeue());
    }

private:
    Queue<int> *l;
};
