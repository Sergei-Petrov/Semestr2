#pragma once
#include "stack.h"
#define stackLen 20

class MStack : public Stack
{
public:
    MStack() : pointer(-1)
    {}
    ~MStack();
    void push(char x);
    char pop();
    string toString();
private:
    char stack[stackLen];
    int pointer;
};
