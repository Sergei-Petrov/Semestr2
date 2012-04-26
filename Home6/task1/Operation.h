#pragma once
#include "Operand.h"

class Operation : public Tree
{
public:
    Operation() {}
    ~Operation();
    int rezult();
    void print();
    string toString();
    void build(string &s, int &count);

private:
    char oper;
    Tree *left;
    Tree *right;
};

