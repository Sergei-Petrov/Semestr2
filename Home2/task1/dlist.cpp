#include "dlist.h"
#include "iostream" //iostream я использовал, потому что " 'NULL' unclared identifer "

DList::~DList()
{
    while(head != NULL)
        {
            List *tmp = head;
            head = head->next;
            delete tmp;
        }
}

void DList::add(int x)
{
    DList *tmp = new DList;
    tmp->value = x;
    tmp->next = NULL;
    tmp->prev = NULL;
    if(head == NULL)
        head = tmp;
    else
    {
        tail->next = tmp;
        tmp->prev = tail;
    }
    tail = tmp;
    count++;
}

string DList::toString()
{
    string str;
    DList *tmp = tail;
    while(tmp != NULL)
    {
        str.push_back(tmp->value + '0');
        tmp = tmp->prev;
    }
    return str;
}

int DList::length()
{
    return count;
}

int DList::delHead()
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
    DList *tmp = head;
    head = tmp->next;
    delete tmp;
    head->prev = NULL;
    count--;
    return x;
}
