#include "slist.h"
#include "dlist.h"
#include "list.h"

int main()
{
    List *lst = new DList;
    lst->add(5);
    lst->add(6);
    lst->add(7);
    lst->add(4);
    lst->add(8);
    cout << lst->toString() << endl;
    lst->delHead();
    cout << lst->toString() << endl;
    cout << "length = " << lst->length();
    delete(lst);
    return 0;
}
