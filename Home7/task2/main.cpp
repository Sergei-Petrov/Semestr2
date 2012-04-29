#include "ListTest.h"
#include "UniqueListTest.h"
#include "iostream"

int main()
{
    ListTest test;
    QTest::qExec(&test);
    cout << endl;
    UniqueListTest test2;
    QTest::qExec(&test2);
    return 0;
}
