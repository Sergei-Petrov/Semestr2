#pragma once
#include "Hash.h"
#include "List.h"
#include "HashFunctions.h"

const int SIZE = 100;

class HashList : public Hash
{
public:
    HashList() : func(NULL)
    {
        for (int i = 0; i < SIZE; i++)
            HashTable[i] = new List;
    }
    ~HashList();
    void add(const string &str);
    void remove(const string &str);
    bool search(const string &str);
    void selectOfFunction(Function *f);
    void status();
private:
    void reboot();
    Function *func;
    List *HashTable[SIZE];
};
