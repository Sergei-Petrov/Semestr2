#pragma once
#include "string"

using namespace std;

class List
{
public:
    List() : count(0), repeats(0), current(NULL), head(NULL) {}
    ~List();
    void add(string str);
    int length();
    void remove(string str);
    bool isEmpty();
    bool search(string str);
    string toString();
    bool further();
    string curValue();
    int curRepeats();
private:
    string value;
    int count;
    int repeats;
    List *current;
    List *next;
    List *head;
    List *tail;
};
