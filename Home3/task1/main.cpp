#include "BubbleSorterTest.h"
#include "QuickSorterTest.h"

using namespace std;

int main()
{
    BubbleSorterTest test;
    QTest::qExec(&test);
    printf("\n");
    QuickSorterTest test2;
    QTest::qExec(&test2);
    return 0;
}
