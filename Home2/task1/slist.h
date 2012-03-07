#pragma once
#include "list.h"

class sList : public List
{
public:
    sList();
    ~sList();
    void add(int x);
    void print();
    int length();
    int delHead();
private:
    int count;
    int value;
    sList *next;
    sList *head;
    sList *tail;

};
