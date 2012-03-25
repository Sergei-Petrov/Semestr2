#include "pstack.h"

PStack::~PStack()
{
    while(head != NULL)
    {
        PStack *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void PStack::push(char x)
{
    PStack *tmp = new PStack;
    tmp->value = x;
    tmp->next = NULL;
    if (head != NULL)
        tmp->next = head;
    head = tmp;
    count++;
}

char PStack::pop()
{
    PStack *tmp;
    char x;
    if(head == NULL)
        return '\0';
    tmp = head;
    x = tmp->value;
    head = tmp->next;
    delete(tmp);
    count--;
    return x;
}

string PStack::toString()
{
    string str;
    PStack *tmp = head;
    while(tmp != NULL)
    {
        str.push_back(tmp->value);
        tmp = tmp->next;
    }
    return str;
}

int PStack::length()
{
    return count;
}

