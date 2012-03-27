#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "FilePrinter.h"

class FilePrinterTest:public QObject
{
    Q_OBJECT

public:
    explicit FilePrinterTest(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        obj = new FilePrinter();
    }

    void cleanup()
    {
        delete obj;
    }

    void TestFilePrinter()
    {
        int count = 1;
        int **matrix = new int *[3];
        for (int i = 0; i < 3; i++)
            matrix[i] = new int[3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                matrix[j][i] = count++;
        obj->print(matrix, 3);
        FILE *file = fopen("file.txt", "r");
        string str = "5 8 9 6 3 2 1 4 7 ";
        char s[19];
        fgets(s, 19, file);
        fclose(file);
        for (int i = 0; i < 3; i++)
            delete [] matrix[i];
        delete [] matrix;
        QVERIFY(str == s);
    }

private:
    Printer *obj;
};

