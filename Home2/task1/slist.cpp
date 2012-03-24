#include "slist.h"
#include "list.h"
#include "iostream"

SList::~SList()
{
    while(head != NULL)
        {
            SList *tmp = head;
            head = head->next;
            delete tmp;
        }
}

void SList::add(int x)
{
    SList *tmp = new SList;
    tmp->value = x;
    tmp->next = NULL;
    if(head == NULL)
        head = tmp;
    else
        tail->next = tmp;

    tail = tmp;
    count++;
}

string SList::toString()
{
    string str;
    SList *tmp = head;
    while(tmp != NULL)
    {
        str.push_back(tmp->value + '0');
        tmp = tmp->next;
    }
    return str;
}

int SList::length()
{
    return count;
}

int SList::delHead()
{
    if(head == NULL)
        return INT_MAX;
    if (head->next == NULL)
    {
        int x = head->value;
        delete head;
        count--;
        return x;
    }
    int x = head->value;
    SList *tmp = head;
    head = tmp->next;
    delete tmp;
    head->
    count--;
    return x;
}

int SList::valueHead()
{
    return head->value;
}

int SList::valueTail()
{
    return tail->value;
}
