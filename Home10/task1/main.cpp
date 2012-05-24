#include <QtGui/QApplication>
#include "Widget.h"
#include "CheckWinTest.h"

int main(int argc, char *argv[])
{
    CheckWinTest test;
    QTest::qExec(&test);
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
