#pragma once
#include "List.h"

class UniqueList : public List
{
public:
    class AddingRepeat {};
    class RemovingNonExistent {};
    void add(string str);
    void remove(string str);
};
