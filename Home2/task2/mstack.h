#pragma once
#include "stack.h"
int const stackLen = 20;

class MStack : public Stack
{
public:
    MStack() : pointer(-1)
    {}
    ~MStack();
    void push(char x);
    char pop();
    string toString();
    int length();
private:
    char stack[stackLen];
    int pointer;
};
