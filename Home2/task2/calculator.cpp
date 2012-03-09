#include "calculator.h"

Calculator::~Calculator()
{
    delete stack;
}

int Calculator::calc(string str)
{
    int a = 0;
    int b = 0;
    for(int i = 0; i < str.length(); i++)
    {
        switch(str[i])
        {
            case '*' :
                stack->push(((stack->pop() - '0') * (stack->pop() - '0')) + '0');
                break;
            case '/' :
                a = stack->pop() - '0';
                b = stack->pop() - '0';
                stack->push((b / a) + '0');
                break;
            case '+' :
                stack->push(((stack->pop() - '0') + (stack->pop() - '0')) + '0');
                break;
            case '-' :
                a = stack->pop() - '0';
                b = stack->pop() - '0';
                stack->push((b - a) + '0');
                break;
            default : stack->push(str[i]); break;
        }
    }
    return (stack->pop() - '0');
}
