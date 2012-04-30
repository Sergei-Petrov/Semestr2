#pragma once
#include "Function.h"
#include "string"

using namespace std;

/// Interface for hash table

class Hash
{
public:
    virtual ~Hash() {}

    /**
      * addition to hash table
      *
      *@ param str - word is added to the hash table
      */
    virtual void add(const string &str) = 0;

    /**
      * removal from hash table
      *
      *@ param str - word is removedd from the hash table
      */
    virtual void remove(const string &str) = 0;

    /**
      * search in hash table
      *
      *@ param str - word is searched in the hash table
      */
    virtual bool search(const string &str) = 0;

    /**
      * change of hash function
      *
      *@ param x -number of hash function
      */
    virtual void selectOfFunction(Function *f) = 0;

    /// gives of the status about hash table
    virtual void status() = 0;
};
