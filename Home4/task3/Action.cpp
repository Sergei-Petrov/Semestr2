#include "Action.h"

int Action::operate(int first, int second, QString oper)
{
    if (oper == "+")
        return first + second;
    if (oper == "-")
        return first - second;
    if (oper == "*")
        return first * second;
    if (oper == "/")
        return first / second;
    return first;
}
