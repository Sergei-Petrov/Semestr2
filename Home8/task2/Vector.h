#pragma once
#include "iostream"
#include "sstream"

using namespace std;

/**
  * template class Vector
  *
  *@ T - type of coordinate that is stored in the vector
  *@ param SIZE - size of vector
  */

template <typename T, int SIZE>
class Vector
{
public:
    /// copy constructor
    Vector(const Vector<T, SIZE> &copy);

    /// constructor that initializes the null vector
    Vector();

    /**
      * Constructor which fills the vector array
      *
      *@ param v - array
      *@ param length - length of array
      */
    Vector(const T *v, int length);

    /// method that prints the vector to stream
    stringstream print();

    /**
      * method that adds two vectors
      *
      *@ param first - first vector
      *@ param second - seconf vector
      */
    void addition(const Vector<T, SIZE> &first, const Vector<T, SIZE> &second);

    /**
      * method that subtracts two vectors
      *
      *@ param first - vector from which is subtracted
      *@ param second - vector which is deducted
      */
    void subtraction(const Vector<T, SIZE> &first, const Vector<T, SIZE> &second);

    /**
      * method which considers the scalar multiplication
      *
      *@ param first - first vector
      */
    T scalar(const Vector<T, SIZE> &second);

    /// method that checks the vector to null
    bool isNull();

private:
    /// coordinates of vector
    T vector[SIZE];
};

template <typename T, int SIZE>
Vector<T, SIZE>::Vector(const Vector<T, SIZE> &copy)
{
    for (int i = 0; i < SIZE; i++)
        vector[i] = copy.vector[i];
}

template <typename T, int SIZE>
Vector<T, SIZE>::Vector()
{
    for (int i = 0; i < SIZE; i++)
        vector[i] = 0;
}

template <typename T, int SIZE>
Vector<T, SIZE>::Vector(const T *v, int length)
{
    for (int i = 0; i < SIZE && i < length; i++)
        vector[i] = v[i];
    if (SIZE > length)
        for(int i = length; i < SIZE; i++)
            vector[i] = 0;
}

template <typename T, int SIZE>
stringstream Vector<T, SIZE>::print()
{
    stringstream out;
    out << "<";
    for (int i = 0; i < SIZE; i++)
        if (i == SIZE - 1)
            out << vector[i];
        else
            out << vector[i] << ", ";
    out << ">" << endl;
    return out;
}

template <typename T, int SIZE>
void Vector<T, SIZE>::addition(const Vector<T, SIZE> &first, const Vector<T, SIZE> &second)
{
    for (int i = 0; i < SIZE; i++)
        vector[i] = first.vector[i] + second.vector[i];
}

template <typename T, int SIZE>
void Vector<T, SIZE>::subtraction(const Vector<T, SIZE> &first, const Vector<T, SIZE> &second)
{
    for (int i = 0; i < SIZE; i++)
        vector[i] = first.vector[i] - second.vector[i];
}

template <typename T, int SIZE>
T Vector<T, SIZE>::scalar(const Vector<T, SIZE> &second)
{
    T result = 0;
    for (int i = 0; i < SIZE; i++)
        result = result + vector[i] * second.vector[i];
    return result;
}

template <typename T, int SIZE>
bool Vector<T, SIZE>::isNull()
{
    for (int i = 0; i < SIZE; i++)
        if (vector[i] != 0)
            return false;
    return true;
}
