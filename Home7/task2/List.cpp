#include "List.h"

List::~List()
{
    while(head != NULL)
    {
        List *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void List::add(string str)
{
    List *tmp2 = head;
    while (tmp2 != NULL)
    {
        if (tmp2->value.compare(str) == 0)
        {
            tmp2->repeats++;
            return;
        }
        tmp2 = tmp2->next;
    }
    List *tmp = new List;
    tmp->value = str;
    tmp->next = NULL;
    tmp->repeats = 1;
    if(head == NULL)
    {
        head = tmp;
        current = head;
    }
    else
        tail->next = tmp;
    tail = tmp;
    count++;
}

int List::length()
{
    return count;
}

void List::remove(string str)
{
    List *tmp = head;
    if (tmp->value.compare(str) == 0)
    {
        if (tmp->repeats > 1)
        {
            repeats--;
            return;
        }
        head = tmp->next;
        delete tmp;
        count--;
        return;
    }
    while(tmp->next != NULL)
    {
        if (tmp->next->value.compare(str) == 0)
        {
            if (tmp->next->repeats > 1)
            {
                repeats--;
                return;
            }
            List *tmp2 = tmp->next;
            tmp = tmp2->next;
            delete tmp2;
            count--;
            return;
        }
        tmp = tmp->next;
    }
    current = head;
}

bool List::isEmpty()
{
    return head == NULL;
}

bool List::search(string str)
{
    List *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value.compare(str) == 0)
            return true;
        tmp = tmp->next;
    }
    return false;
}

string List::toString()
{
    string str;
    List *tmp = head;
    while (tmp != NULL)
    {
        str.append(tmp->value);
        tmp = tmp->next;
    }
    return str;
}

bool List::further()
{
    if (current->next == NULL)
    {
        current = head;
        return false;
    }
    else
    {
        current = current->next;
        return true;
    }
}

string List::curValue()
{
    return current->value;
}

int List::curRepeats()
{
    return current->repeats;
}
