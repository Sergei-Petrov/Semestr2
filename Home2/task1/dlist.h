#pragma once
#include "list.h"

class dList : public List
{
public:
    dList();
    ~dList();
    void add(int x);
    void print();
    void printEnd();
    int length();
    int delHead();
private:
    int count;
    int value;
    dList *next;
    dList *head;
    dList *tail;
    dList *prev;
};
