#include "dlist.h"
#include "iostream"
#include "list.h"

dList::dList()
{
    count = 0;
    head = NULL;
}

dList::~dList()
{
    while(head != NULL)
        {
            List *tmp = head;
            head = head->next;
            delete tmp;
        }
}

void dList::add(int x)
{
    dList *tmp = new dList;
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

void dList::print()
{
    dList *tmp = tail;
    while(tmp != NULL)
    {
        printf("%d ", tmp->value);
        tmp = tmp->prev;
    }
    printf("\n");
}

int dList::length()
{
    return count;
}

int dList::delHead()
{
    if(head == NULL)
    {
        printf("List is empty");
        return 0;
    }
    if (head->next == NULL)
    {
        int x = head->value;
        delete head;
        count--;
        return x;
    }
    int x = head->value;
    dList *tmp = head;
    head = tmp->next;
    delete tmp;
    head->prev = NULL;
    count--;
    return x;
}
