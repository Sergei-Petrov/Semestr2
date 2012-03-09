#pragma once
#include "stack.h"

class PStack : public Stack
{
public:
    PStack() : count(0), head(NULL)
    {}
    ~PStack();
    void push(char x);
    char pop();
    string toString();
private:
    PStack *next;
    PStack *head;
    int value;
    int count;
};
