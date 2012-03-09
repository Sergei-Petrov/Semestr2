#pragma once
#include "pstack.h"

class Calculator
{
public:
    Calculator() : stack(new PStack)
    {}
    ~Calculator();
    int calc(string str);
private:
    Stack *stack;
};
