#pragma once
#include "Function.h"

class FirstHash : public Function
{
public:
    int hash(const string &str, int size);
};

class SecondHash : public Function
{
public:
    int hash(const string &str, int size);
};
