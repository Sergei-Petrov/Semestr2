#pragma once
#include "list.h"
#include "iostream"

class DList : public List
{
public:
    DList() : count(0), head(NULL)
    {}
    ~DList();
    void add(int x);
    string toString();
    void printEnd();
    int length();
    int delHead();
    int valueHead();
    int valueTail();
private:
    int count;
    int value;
    DList *next;
    DList *head;
    DList *tail;
    DList *prev;
};
