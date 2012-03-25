#include "pStackTest.h"
#include "mStackTest.h"
#include "CalculatorTest.h"

int main()
{
    PStackTest test;
    QTest::qExec(&test);
    printf("\n");
    MStackTest test2;
    QTest::qExec(&test2);
    printf("\n");
    CalculatorTest test3;
    QTest::qExec(&test3);
    return 0;
}
