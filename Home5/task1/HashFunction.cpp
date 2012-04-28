#include "HashFunction.h"

int HashFunction::call(string str, int size)
{
    if (current == 1)
        return first(str, size);
    else
        return second(str, size);
}

void HashFunction::change(int x)
{
    if (x == 1 || x == 2)
        current = x;
}

int HashFunction::first(string str, int size)
{
    int key = 0;
    for (int i = 0; i < str.length(); i++)
    {
        key = key + str.data()[i];
    }
    return key % size;
}

int HashFunction::second(string str, int size)
{
    int key = 0;
    for (int i = 0; i < str.length(); i++)
    {
        key = key + str.data()[i] * (i + 1);
    }
    return key % size;
}
