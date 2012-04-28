#include "ListTest.h"
#include "HashFunctionTest.h"
#include "HashListTest.h"
#include "iostream"

int main()
{
    ListTest test;
    QTest::qExec(&test);
    cout << endl;
    HashFunctionTest test2;
    QTest::qExec(&test2);
    cout << endl;
    HashListTest test3;
    QTest::qExec(&test3);
    cout << endl;
    int a = 0;
    string str;
    Hash *table = new HashList;
    bool flag = true;
    while (flag)
    {
        cout << endl;
        cout << "0 - exit" << endl;
        cout << "1 - add string to hash" << endl;
        cout << "2 - remove string from hash" << endl;
        cout << "3 - search string from hash" << endl;
        cout << "4 - get status" << endl;
        cout << "5 - select func(1 or 2)" << endl;
        cin >> a;
        switch (a)
        {
        case 0:
            flag = false;
            break;
        case 1:
            cout << "Enter string" << endl;
            cin >> str;
            table->add(str);
            break;
        case 2:
            cout << "Enter string" << endl;
            cin >> str;
            table->add(str);
            break;
        case 3:
            cout << "Enter string" << endl;
            cin >> str;
            if (table->search(str))
                cout << "Found" << endl;
            else
                cout <<"Not found" << endl;
            break;
        case 4:
            table->status();
            break;
        case 5:
            cout << "Enter number" << endl;
            cin >> a;
            table->selectOfFunction(a);
            break;
        }
    }
    delete table;
    return 0;
}
