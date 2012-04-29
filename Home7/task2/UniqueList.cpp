#include "UniqueList.h"

void UniqueList::add(string str)
{
    if (search(str))
        throw AddingRepeat();
    else
        List::add(str);
}

void UniqueList::remove(string str)
{
    if (!search(str))
        throw RemovingNonExistent();
    else
        List::remove(str);
}
