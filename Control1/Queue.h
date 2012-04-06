#pragma once
#include "string"

using namespace std;

template <typename T>

class Queue
{
public:
    Queue();
    ~Queue();
    void enqueu(T val, int pri);
    T dequeue();
    T valHead();
private:
    T value;
    int prior;
    Queue *next;
    Queue *head;
    Queue *tail;
};

template<typename T>
Queue<T>::Queue() : value(0), prior(0), head(NULL)
{}

template<typename T>
Queue<T>::~Queue()
{
    while(head != NULL)
    {
        Queue<T> *tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<typename T>
void Queue<T>::enqueu(T val, int pri)
{
    Queue<T> *tmp = new Queue;
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

template<typename T>
T Queue<T>::dequeue()
{
    //if (head == NULL)
      //  return 100500;
    Queue<T> *tmp = head;
    Queue<T> *del;
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

    Queue<T> *tmp2 = del->next;
    del->next = del->next->next;
    delete tmp2;
    return mValue;
}

template<typename T>
T Queue<T>::valHead()
{
    return head->value;
}
