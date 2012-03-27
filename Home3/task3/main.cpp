#include "quickSorterTest.h"
#include "quickSorter.h"
#include "iostream"

using namespace std;

int main()
{
    //QuickSorterTest test;
    //QTest::qExec(&test);
    Sorter *obj = new QuickSorter;
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

    obj->sort(a, 5);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << a[j][i] << "=" << b[j][i] << endl;
    }
    for (int i = 0; i < 3; i++)
        delete [] a[i];
    delete [] a;
    delete obj;
    return 0;
}
