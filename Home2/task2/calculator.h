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
    void multiplication();
    void division();
    void addition();
    void subtraction();
    Stack *stack;
};
