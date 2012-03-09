#include "pstack.h"
#include "iostream"

int main()
{
    Stack *stack = new PStack;
    stack->push('A');
    stack->push('B');
    cout << stack->pop() << endl;
    cout << stack->toString();
    delete(stack);
    return 0;
}
