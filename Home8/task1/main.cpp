#include "TreeTest.h"
#include "BagTest.h"
#include "iostream"

int main()
{
    TreeTest test;
    QTest::qExec(&test);
    cout << endl;
    BagTest test2;
    QTest::qExec(&test2);
    return 0;
}
