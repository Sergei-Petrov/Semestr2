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
    virtual int hash(const string &str, int size) = 0;
};
