#include <QtCore/QCoreApplication>
#include "FilePrinter.h"
#include "ConsolePrinter.h"
#include "iostream"

int main()
{
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
    Printer *obj = new FilePrinter;
    obj->print(matrix, n);
    Printer *obj2 = new ConsolePrinter;
    obj2->print(matrix, n);
    for (int i = 0; i < n; i++)
        delete [] matrix[i];
    delete [] matrix;
    delete obj;
    delete obj2;
    return 0;
}
