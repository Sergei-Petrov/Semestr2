#pragma once

/// Generic class set

template <typename T>
class Set
{
public:
    Set() : val(0), next(NULL), head(NULL), current(NULL) {}
    ~Set();

    /// Adding an item from the set
    void addValue(T);

    /// Delete an item from the set
    bool delValue(T);

    /// Function for check for empty
    bool isEmpty() {return head == NULL;}

    /// Search function is an item in the set
    bool search(T);

    /// The intersection of set
    void intersect(Set<T> *, Set<T> *);

    /// The sum of set
    void sum(Set<T> *, Set<T> *);

private:
    bool further();
    T curValue();
    T val;
    Set *next;
    Set *head;
    Set *tail;
    Set *current;
};

template <typename T>
Set<T>::~Set()
{
    while (head != NULL)
    {
        Set *tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
void Set<T>::addValue(T x)
{
    Set *tmp = new Set;
    tmp->next = NULL;
    tmp->val = x;
    if (head == NULL)
    {
        head = tmp;
        current = head;
    }
    else
        tail->next = tmp;
    tail = tmp;
}

template <typename T>
bool Set<T>::delValue(T x)
{
    Set *tmp = head;
    if(tmp->val == x)
    {
        if (current == head)
        {
            head = tmp->next;
            current = head;
        }
        else
            head = tmp->next;
        delete tmp;
        return true;
    }

    while(tmp->next != NULL)
    {
        if (tmp->next->val == x)
        {
            if (current == tmp->next)
                current = head;
            Set *tmp2 = tmp->next;
            tmp = tmp2->next;
            delete tmp2;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

template <typename T>
bool Set<T>::search(T x)
{
    Set *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->val == x)
            return true;
        tmp = tmp->next;
    }
    return false;
}

template <typename T>
void Set<T>::intersect(Set<T> *first, Set<T> *second)
{
    do
        if (second->search(first->curValue()))
            addValue(first->curValue());
    while (first->further());
}

template <typename T>
void Set<T>::sum(Set<T> *first, Set<T> *second)
{
    do
        addValue(first->curValue());
    while (first->further());
    do
        if(!search(second->curValue()))
            addValue(second->curValue());
    while (second->further());
}

template <typename T>
bool Set<T>::further()
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

template <typename T>
T Set<T>::curValue()
{
    return current->val;
}


