#include <iostream>

using namespace std;

class Exception{};

class A
{
public:
    A()
    {
        cout << "Calling the constructor of class A" << endl;
    }
    ~A()
    {
        cout << "Calling the destructor of class A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "Calling the constructor of class B" << endl;
    }
    ~B()
    {
        cout << "Calling the destructor of class B" << endl;
    }
};

int main()
{
    try
    {
        cout << "Creating an object of class A" << endl;
        A a;
        cout << "Creating an object of class B" << endl;
        B b;
        cout << "Generation of exception" << endl;
        throw Exception();
    }
    catch (Exception)
    {
        cout << "Exception handling";
    }
    return 0;
}
