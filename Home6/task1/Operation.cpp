#include "Operation.h"

Operation::~Operation()
{
    delete left;
    delete right;
}

int Operation::rezult()
 {
     int a = left->rezult();
     int b = right->rezult();

     switch (oper)
     {
     case '+':
         return a + b;
     case '-':
         return a - b;
     case '*':
         return a * b;
     case '/':
         return a / b;
     }

 }
void Operation::print()
{
    cout << toString();
}

string Operation::toString()
{
    string str;
    str.push_back('(');
    str.push_back(oper);
    str.append(left->toString());
    str.append(right->toString());
    str.push_back(')');
    return str;
}

void Operation::build(string &s, int &count)
{
    count++;
    oper = s[count++];
    Operation *tmp;
    if (s[count] == '(')
    {
        tmp = new Operation();
        tmp->build(s, count);
        left = tmp;
    }
    else
        left = new Operand(s[count++] - '0');

    if (s[count] == '(')
    {
        tmp = new Operation();
        tmp->build(s, count);
        right = tmp;
    }
    else
        right = new Operand(s[count++] - '0');
    count++;
}
