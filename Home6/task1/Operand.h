#pragma once
#include "Tree.h"
#include "iostream"

class Operand : public Tree
{
public:
    Operand(int x): val(x) {}
    int rezult() {return val;}
    void print()
    {
        cout << val;
    }

    string toString()
    {
        string str;
        str.push_back(val + '0');
        return str;
    }

private:
    int val;
};
