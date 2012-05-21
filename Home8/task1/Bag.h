#pragma once
#include "Tree.h"

template <typename T>
class Bag
{
public:
    Bag() : tree(new Tree<T>){}
    ~Bag() {delete tree;}
    bool isEmpty() const { return tree->isEmpty();}
    void insert(const T &tmp);
    void erase(const T &tmp);
    bool find(const T &tmp) const;
    void clear();
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
