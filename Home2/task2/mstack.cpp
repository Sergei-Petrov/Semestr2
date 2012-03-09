#include "mstack.h"

MStack::~MStack()
{
    pointer = -1;
}

void MStack::push(char x)
{
    if(pointer >= stackLen)
        return;
    stack[++pointer] = x;
}

char MStack::pop()
{
    if(pointer == -1)
        return '\0';
    return stack[pointer--];
}

string MStack::toString()
{
    string str;
    for(int i = pointer; i >= 0; i--)
        str.push_back(stack[i]);
    return str;
}
