#pragma once
#include "Hash.h"
#include "List.h"
#include "HashFunction.h"

const int SIZE = 100;

class HashList : public Hash
{
public:
    HashList() : func(new HashFunction)
    {
        for (int i = 0; i < SIZE; i++)
            HashTable[i] = new List;
    }
    ~HashList();
    void add(string str);
    void remove(string str);
    bool search(string str);
    void selectOfFunction(int x);
    void status();
private:
    void reboot();
    Function *func;
    List *HashTable[SIZE];
};
