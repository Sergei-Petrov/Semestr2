#include "slist.h"
#include "list.h"
#include "iostream"

sList::sList()
{
    count = 0;
    head = NULL;
}

sList::~sList()
{
    while(head != NULL)
        {
            List *tmp = head;
            head = head->next;
            delete tmp;
        }
}

void sList::add(int x)
{
    sList *tmp = new sList;
    tmp->value = x;
    tmp->next = NULL;
    if(head == NULL)
        head = tmp;
    else
        tail->next = tmp;

    tail = tmp;
    count++;
}

void sList::print()
{
    sList *tmp = head;
    while(tmp != NULL)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int sList::length()
{
    return count;
}

int sList::delHead()
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
    sList *tmp = head;
    head = tmp->next;
    delete tmp;
    head->
    count--;
    return x;
}
