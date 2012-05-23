#pragma once
#include "Tree.h"

template <typename T>
class Bag
{
public:
    class Iterator
    {
    public:
        Iterator(Tree<T> *tmp) : it(tmp) {}
        void operator++()
        {
            it = it->next(it);
        }

        void operator--()
        {
            it = it->prev(it);
        }

        T operator*()
        {
            return it->val(it);
        }

        bool operator==(Iterator &tmp)
        {
           return it == tmp.pointer();
        }

        bool operator!=(Iterator &tmp)
        {
            return it != tmp.pointer();
        }

    private:
        Tree<T> *it;
        Tree<T> *pointer()
        {
            return it;
        }
    };
    Bag() : tree(new Tree<T>){}
    ~Bag() {delete tree;}
    bool isEmpty() const { return tree->isEmpty();}
    void insert(const T &tmp);
    void erase(const T &tmp);
    bool find(const T &tmp) const;
    void clear();
    Tree<T> *first();
    Tree<T> *last();

private:
    Tree<T> *tree;
};

template <typename T>
void Bag<T>::insert(const T &tmp)
{
    tree->add(tmp);
}

template <typename T>
void Bag<T>::erase(const T &tmp)
{
    tree->RemoveNode(tmp);
}

template <typename T>
bool Bag<T>::find(const T &tmp) const
{
    return tree->search(tmp);
}

template <typename T>
void Bag<T>::clear()
{
    Tree<T> *tmp = tree;
    tree = new Tree<int>;
    delete tmp;
}

template <typename T>
Tree<T> *Bag<T>::first()
{
    return tree->first();
}

template <typename T>
Tree<T> *Bag<T>::last()
{
    return tree->last();
}
