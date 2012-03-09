#include "mstack.h"
#include "iostream"

int main()
{
    Stack *stack = new MStack;
    stack->push('A');
    stack->push('B');
    cout << stack->toString() << endl;
    cout << stack->pop() << endl;
    cout << stack->toString();
    delete(stack);
    return 0;
}
