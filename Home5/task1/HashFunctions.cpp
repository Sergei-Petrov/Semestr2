#include "HashFunctions.h"

int FirstHash::hash(const string &str, int size)
{
    int key = 0;
    for (int i = 0; i < str.length(); i++)
    {
        key = key + str.data()[i];
    }
    return key % size;
}

int SecondHash::hash(const string &str, int size)
{
    int key = 0;
    for (int i = 0; i < str.length(); i++)
    {
        key = key + str.data()[i] * (i + 1);
    }
    return key % size;
}


