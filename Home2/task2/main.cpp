#include "calculator.h"
#include "iostream"

int main()
{
    Calculator *obj = new Calculator;
    string str;
    cout << "Enter : ";
    cin >> str;
    cout << obj->calc(str);
    delete(obj);
    return 0;
}
