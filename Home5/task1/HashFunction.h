#pragma once
#include "Function.h"

class HashFunction : public Function
{
public:
    HashFunction() : current(1) {}
    int call(string str, int size);
    void change(int x);
private:
    int current;
    int first(string str, int size);
    int second(string str, int size);
};
