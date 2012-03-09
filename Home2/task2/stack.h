#pragma once
#include "string"

using namespace std;

class Stack
{
public:
    virtual ~Stack()
    {}
    virtual void push(char x) = 0;
    virtual char pop() = 0;
    virtual string toString() = 0;
};
