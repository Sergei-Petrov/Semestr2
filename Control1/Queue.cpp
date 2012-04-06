#include "Queue.h"
#include "iostream"

Queue::Queue() : value(0), prior(0), head(NULL)
{}

Queue::~Queue()
{
    while(head != NULL)
    {
        Queue *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void Queue::enqueu(int val, int pri)
{
    Queue *tmp = new Queue;
    tmp->value = val;
    tmp->prior = pri;
    tmp->next = NULL;
    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
        return;
    }
    tmp->next = head;
    head = tmp;
}

int Queue::dequeue()
{
    //if (head == NULL)
      //  return 100500;
    Queue *tmp = head;
    Queue *del;
    int mPrior = tmp->prior;
    int mValue = tmp->value;

    while(tmp->next != NULL)
    {
        if(tmp->next->prior > mPrior)
        {
            mPrior = tmp->next->prior;
            mValue = tmp->next->value;
            del = tmp;
        }
        tmp = tmp->next;
    }

    Queue *tmp2 = del->next;
    del->next = del->next->next;
    delete tmp2;
    return mValue;
}

int Queue::valHead()
{
    return head->value;
}
