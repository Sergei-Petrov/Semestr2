#include "slist.h"
#include "dlist.h"
#include "list.h"
#include "iostream"

int main()
{
    List *lst = new dList;
    lst->add(5);
    lst->add(6);
    lst->add(7);
    lst->add(4);
    lst->add(8);
    lst->print();
    lst->delHead();
    lst->print();
    printf("\nlength = %d", lst->length());
    delete(lst);
    return 0;
}
