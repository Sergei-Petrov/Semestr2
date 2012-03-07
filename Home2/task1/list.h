#pragma once

class List
{ 
public:

    //List();
    virtual void add(int x) = 0;
    virtual void print() = 0;
    virtual int length() = 0;
    virtual int delHead() = 0;
};
