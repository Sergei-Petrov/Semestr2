#pragma once
#include "stack.h"

class PStack : public Stack
{
public:
    PStack() : next (NULL), head(NULL), value(0), count(0)
    {}
    ~PStack();
    void push(char x);
    char pop();
    string toString();
    int length();
private:
    PStack *next;
    PStack *head;
    int value;
    int count;
};
