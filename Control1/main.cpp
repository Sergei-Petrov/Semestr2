#include "iostream"
#include "Queue.h"
#include "QueueTest.h"

using namespace std;

int main()
{
    QueueTest test;
    QTest::qExec(&test);
    return 0;
}
