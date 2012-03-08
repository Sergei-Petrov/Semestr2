#pragma once
#include "list.h"
#include "iostream"

class SList : public List
{
public:
    SList() : count(0), head(NULL)
    {}
    ~SList();
    void add(int x);
    string toString();
    int length();
    int delHead();
private:
    int count;
    int value;
    SList *next;
    SList *head;
    SList *tail;

};
