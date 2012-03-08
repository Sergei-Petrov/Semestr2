#pragma once
#include "string"

using namespace std;

class List
{ 
public:
    virtual ~List()
    {}
    virtual void add(int x) = 0;
    virtual string toString() = 0;
    virtual int length() = 0;
    virtual int delHead() = 0;
};
