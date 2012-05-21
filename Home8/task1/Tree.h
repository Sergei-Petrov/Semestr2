#pragma once
#include "string"
#include "sstream"
#include "QQueue"

using namespace std;

/// Self balancing tree

template <typename T>
class Tree
{
public:
    /// constructor of tree
    Tree() : count(0), head(NULL), value(0) {}

    /// destructor of tree
    ~Tree();

    ///
    bool isEmpty() const;

    /**
      * adding to the tree
      *
      * param x - value of the added elements
      */
    void add(const T &x);

    /// the function returns the number of elements in the tree
    int length() const;

    /**
      * search in the tree
      *
      * param x - value of which is necessary to find
      */
    bool search(const T &x);

    /**
      * removal from the tree
      *
      * param x - value of which is necessary to remove
      */
    void RemoveNode(const T &x);

    /// the function returns the height of the tree
    int height() const;

    /// the function that returns a string consisting of the elements arranged in ascending order
    string printToWidth() const;

    /// the function that returns a string consisting of the elements passed in width
    string print() const;

private:
    /// helper function for "string print()"
    string print(Tree *tmp) const;

    /// Function balancing the tree. Used when you add an element
    int balance(Tree *r, Tree *p);

    /**
      * The function returns the height of the branches.Used in "int balance(Tree *r, Tree *p)" and "int height()"
      *
      * param t - branch, the length of which will be issued as a result
      */
    int heightOfBranches(Tree *t) const;

    /**
      * Removes from the memory part of the tree. Used in the destructor
      *
      * param t - the node from which to start removing
      */
    void clear(Tree *t);

    /// The four functions of carrying out coups. Used for balancing
    void turnSmallClockwise(Tree *r, Tree *p);
    void turnSmallCounterClockwise(Tree *r, Tree *p);
    void turnBigClockwise(Tree *r, Tree *p);
    void turnBigCounterClockwise(Tree *r, Tree *p);

    /// number of elements
    int count;

    /// number of repetitions of a given element
    int repeats;

    /// pointer to left child
    Tree<T> *left;

    /// pointer to right child
    Tree<T> *right;

    /// pointer to root of tree
    Tree<T> *head;

    /// value of node
    T value;
};

template <typename T>
Tree<T>::~Tree()
{
    clear(head);
}

template <typename T>
bool Tree<T>::isEmpty() const
{
    return head == NULL;
}

template <typename T>
void Tree<T>::add(const T &x)
{
    if (head == NULL)
    {
        head = new Tree();
        head->left = NULL;
        head->right = NULL;
        head->value = x;
        head->repeats = 1;
        count = 1;
        return;
    }
    Tree<T> *tmp = head;
    Tree<T> *tmp2 = head;
    while (tmp != NULL)
    {
        tmp2 = tmp;
        if (tmp->value == x)
        {
            tmp->repeats++;
            count++;
            return;
        }
        else if (tmp->value > x)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    tmp = new Tree();
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->value = x;
    tmp->repeats = 1;
    count++;
    if (tmp2->value > x)
        tmp2->left = tmp;
    else
        tmp2->right = tmp;
    balance(head, NULL);
}

template <typename T>
int Tree<T>::length() const
{
    return count;
}

template <typename T>
bool Tree<T>::search(const T &x)
{
    Tree<T> *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == x)
            return true;
        if (tmp->value > x)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return false;
}

template <typename T>
void Tree<T>::RemoveNode(const T &x)
{
    if (!search(x))
        return;
    Tree<T> **parent = &head;
    Tree<T> *tmp = head;
    while (tmp->value != x)
    {
        if (tmp->value > x)
        {
            parent = &tmp->left;
            tmp = tmp->left;
        }
        else
        {
            parent = &tmp->right;
            tmp = tmp->right;
        }
    }
    if (tmp->repeats > 1)
    {
        count--;
        repeats--;
        return;
    }
    else if (tmp->left == NULL && tmp->right == NULL)
    {
        *parent = NULL;
        delete tmp;
    }
    else if (tmp->left == NULL && tmp->right != NULL)
    {
        *parent = tmp->right;
        delete tmp;
    }
    else if (tmp->left != NULL && tmp->right == NULL)
    {
        *parent = tmp->left;
        delete tmp;
    }
    else if (tmp->left != NULL && tmp->right != NULL)
    {
        Tree<T> **parent2 = &tmp->right;
        Tree<T> *tmp2 = tmp->right;
        while (tmp2->left != NULL)
        {
            parent2 = &tmp2->left;
            tmp2 = tmp2->left;
        }
        tmp->value = tmp2->value;
        tmp->repeats = tmp2->repeats;
        *parent2 = NULL;
        delete tmp2;
    }
    count--;
}

template <typename T>
int Tree<T>::height() const
{
    return heightOfBranches(head);
}

template <typename T>
string Tree<T>::printToWidth() const
{
    if (head == NULL)
        return "";
    stringstream out;
    QQueue<Tree*> q;
    q.enqueue(head);
    Tree<T> *x;
    while (!q.empty())
    {
        x = q.dequeue();
        for (int i = 0; i < x->repeats; i++)
            out << x->value << " ";
        if (x->left != NULL)
            q.enqueue(x->left);
        if (x->right != NULL)
            q.enqueue(x->right);
    }
    return out.str();
}

template <typename T>
string Tree<T>::print() const
{
    if (head == NULL)
        return "";
    return print(head);
}

template <typename T>
string Tree<T>::print(Tree *tmp) const
{
    if (tmp == NULL)
        return "";
    stringstream out;
    out << print(tmp->left);
    for (int i = 0; i < tmp->repeats; i++)
        out << tmp->value << " ";
    out << print(tmp->right);
    return out.str();
}

template <typename T>
int Tree<T>::heightOfBranches(Tree *t) const
{
    if (t == NULL)
        return -1;
    int l = heightOfBranches(t->left);
    int r = heightOfBranches(t->right);
    if (l > r)
        return l+1;
    else
        return r+1 ;
}

template <typename T>
void Tree<T>::clear(Tree *t)
{
    if (t != NULL)
    {
        clear(t->left);
        clear(t->right);
        delete(t);
    }
}

template <typename T>
void Tree<T>::turnSmallClockwise(Tree *r, Tree *p)
{
    Tree<T> *tmp = r->left;
    r->left = tmp->right;
    tmp->right = r;
    if (p == NULL)
    {
        head = tmp;
        return;
    }
    if (p->value <= tmp->value)
        p->right = tmp;
    else
        p->left = tmp;
}

template <typename T>
void Tree<T>::turnSmallCounterClockwise(Tree *r, Tree *p)
{
    Tree<T> *tmp = r->right;
    r->right = tmp->left;
    tmp->left = r;
    if (p == NULL)
    {
        head = tmp;
        return;
    }
    if (p->value <= tmp->value)
        p->right = tmp;
    else
        p->left = tmp;
}

template <typename T>
void Tree<T>::turnBigClockwise(Tree *r, Tree *p)
{
    Tree<T> *tmp = r->left->right;
    r->left->right = tmp->left;
    tmp->left = r->left;
    r->left = tmp->right;
    tmp->right = r;
    if (p == NULL)
    {
        head = tmp;
        return;
    }
    if (p->value <= tmp->value)
        p->right = tmp;
    else
        p->left = tmp;
}

template <typename T>
void Tree<T>::turnBigCounterClockwise(Tree *r, Tree *p)
{
    Tree<T> *tmp = r->right->left;
    r->right->left = tmp->right;
    tmp->right = r->right;
    r->right = tmp->left;
    tmp->left = r;
    if (p == NULL)
    {
        head = tmp;
        return;
    }
    if (p->value <= tmp->value)
        p->right = tmp;
    else
        p->left = tmp;
}

template <typename T>
int Tree<T>::balance(Tree *r, Tree *p)
{
    if ((heightOfBranches(r->left) - heightOfBranches(r->right) ) == 2)
    {
        if (heightOfBranches(r->left->left) > heightOfBranches(r->left->right))
            turnSmallClockwise(r, p);
        else
            turnBigClockwise(r, p);
    }
    if((heightOfBranches(r->left) - heightOfBranches(r->right)) == -2)
    {
        if(heightOfBranches(r->right->left) < heightOfBranches(r->right->right))
            turnSmallCounterClockwise(r, p);
        else
            turnBigCounterClockwise(r, p);
    }
    p = r;
    if(r->left != NULL)
        do
        {}while(!balance(r->left,p));
    if(r->right != NULL)
        do
        {}while(!balance(r->right,p));
    return 1;
}
