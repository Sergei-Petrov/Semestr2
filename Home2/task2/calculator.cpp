#include "calculator.h"

Calculator::~Calculator()
{
    delete(stack);
}

int Calculator::calc(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        switch(str[i])
        {
            case '*' : multiplication(); break;
            case '/' : division(); break;
            case '+' : addition(); break;
            case '-' : subtraction(); break;
            default : stack->push(str[i]); break;
        }
    }
    return (stack->pop() - '0');
}

void Calculator::multiplication()
{
    stack->push(((stack->pop() - '0') * (stack->pop() - '0')) + '0');
}

void Calculator::division()
{
    int a = stack->pop() - '0';
    int b = stack->pop() - '0';
    stack->push((b / a) + '0');
}

void Calculator::addition()
{
    stack->push(((stack->pop() - '0') + (stack->pop() - '0')) + '0');
}

void Calculator::subtraction()
{
    int a = stack->pop() - '0';
    int b = stack->pop() - '0';
    stack->push((b - a) + '0');
}
