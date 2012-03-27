#include <QtCore/QCoreApplication>
#include "FilePrinter.h"
#include "ConsolePrinter.h"
#include "FilePrinterTest.h"

int main()
{
    FilePrinterTest test;
    QTest::qExec(&test);
    cout << endl;

    int n = 0;
    cout << "Enter n" << endl;
    cin >> n;
    cout << "Enter matrix" << endl;
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[j][i];
    cout << "1 - print in file" << endl << "2 - print on console"
         << endl << "other key - exit" << endl << "Your choice : ";
    int a;
    cin >> a;
    Printer *obj = new FilePrinter;
    Printer *obj2 = new ConsolePrinter;
    switch (a)
    {
        case 1 :
            //Printer *obj = new FilePrinter;
            obj->print(matrix, n);
            //delete obj;
        break;
        case 2 :
            //Printer *obj2 = new ConsolePrinter;
            obj2->print(matrix, n);
            //delete obj2;
        break;
        default :
            break;
    }
    delete obj;
    delete obj2;
    for (int i = 0; i < n; i++)
        delete [] matrix[i];
    delete [] matrix;
    return 0;
}
