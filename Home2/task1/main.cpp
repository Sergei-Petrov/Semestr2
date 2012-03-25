#include "sListTest.h"
#include "dListTest.h"

int main()
{
    SListTest test;
    QTest::qExec(&test);
    printf("\n");
    DListTest test2;
    QTest::qExec(&test2);
    return 0;
}
