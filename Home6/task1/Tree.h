#pragma once
#include "string"

using namespace std;

/// Interface for calculator tree

class Tree
{
public:
    virtual ~Tree() {}

    /// Interface function, which gives the result
    virtual int rezult() = 0;

    /// Interface function, which prints the result
    virtual void print() = 0;

    /// Interface function, which gives the string with rezult
    virtual string toString() = 0;
};
