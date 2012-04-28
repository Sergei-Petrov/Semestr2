#pragma once
#include "string"

using namespace std;

/// Interface for hash function

class Function
{
public:
    /**
      * function gives a hash
      *
      *@ param str - word from which hash is
      *@ param size - size of HashTable
      */
    virtual int call(string str, int size) = 0;

    /**
      * change of hash function
      *
      *@ x - number of hash function
      */
    virtual void change(int x) = 0;
};
